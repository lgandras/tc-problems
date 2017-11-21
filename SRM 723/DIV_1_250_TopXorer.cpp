#include<vector>
#include<algorithm>

using namespace std;

class TopXorer {
  public:
    int maximalRating(vector <int> x);
};

int TopXorer::maximalRating(vector <int> x) {
  int ret = 0;
  for (int i = 1 << 30; i > 0; i >>= 1) {
    for (vector<int>::iterator j = x.begin(); j != x.end(); ++ j) {
      if (*j & i) {
        if (ret & i) {
          return ret | (i - 1);
        }
        ret |= i;
      }
    }
  }
  return ret;
}
