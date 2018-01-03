#include<vector>

using namespace std;

class Saleswoman {
  public:
    int minMoves(vector <int> pos, vector <int> delta) {
      int ret = 0, acc = 0, racc = 0;
      for (int i = 0; i < pos.size(); ++ i) {
        ret += (racc < 0 ? 3 : 1) * (pos[i] - (0 == i ? 0 : pos[i - 1]));
        if (delta[i] < 0) {
          if (0 == racc && -delta[i] <= acc) {
            acc += delta[i];
          } else {
            racc += delta[i];
          }
        } else if (0 < delta[i]) {
          acc += delta[i];
          if (-racc <= acc) {
            acc += racc;
            racc = 0;
          }
        }
      }
      return ret;
    }
};
