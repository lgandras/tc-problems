#include<vector>

using namespace std;

class MulticoreProcessingEasy {
  public:
    int fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores);
};

int MulticoreProcessingEasy::fastestTime(int jobLength, int corePenalty, vector <int> speed, vector <int> cores) {
  int ret = 1 << 30;
  for (int i = 0; i < speed.size(); ++ i) {
    for (int j = 1; j <= cores[i]; ++ j) {
      int penalty = (j - 1) * corePenalty,
          jobTime = (jobLength + speed[i] - 1) / speed[i],
          jobTimeCore = (jobTime + j - 1) / j + penalty;
      ret = ret < jobTimeCore ? ret : jobTimeCore;
    }
  }
  return ret;
};
