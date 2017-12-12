#include<vector>
#include<algorithm>

using namespace std;

class OvercookedDiv2 {
  public:
    int minStale(vector <int> start, vector <int> time) {
      for (int i = 1; i < start.size(); ++ i) {
        start[i] = max(start[i], start[i - 1] + time[i - 1]);
      }
      for (int j = start.size(); j >= 2; -- j) {
        int m = start[0];
        for (int i = 1; i < j; ++ i) {
          m += start[i] - (start[i - 1] + time[i - 1]);
        }
        m = (m + j - 1) / j;
        start[j - 2] = max(start[j - 2], start[j - 1] - m - time[j - 2]);
      }
      int ret = start[0];
      for (int i = 1; i < start.size(); ++ i) {
        ret = max(ret, start[i] - (start[i - 1] + time[i - 1]));
      }
      return ret;
    }
};
