#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class FiveRooksDiv2 {
  public:
    int findMax(vector <string> board) {
      int ret = 0;
      for (int i = 0; i < 8; ++ i) {
        int r = 0, c = 0;
        for (int j = 0; j < 8; ++ j) {
          if ('R' == board[i][j]) {
            ++ r;
          }
          if ('R' == board[j][i]) {
            ++ c;
          }
        }
        ret = max(ret, max(r, c));
      }
      return ret;
    }
};
