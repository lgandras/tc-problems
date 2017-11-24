#include<vector>

using namespace std;

class HillClimber {
  public:
    int longest(vector <int> height);
};

int HillClimber::longest(vector <int> height) {
  int ret = 0, c = 0;
  for (vector<int>::iterator i = height.begin() + 1; i != height.end(); ++ i) {
    if (*i - *(i - 1) > 0) {
      ++ c;
    } else {
      c = 0;
    } 
    ret = ret > c ? ret : c;
  }
  return ret;
};
