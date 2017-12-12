#include<string>
#include<vector>

using namespace std;

class NiceTable {
  public:
    string isNice(vector <string> t) {
      for (int i = 0; i < (1 << t.size()); ++ i) {
        for (int j = 0; j < (1 << t[0].size()); ++ j) {
          bool x[5] = {j & 1, j & 2, j & 4, j & 8, j & 16},
               y[5] = {i & 1, i & 2, i & 4, i & 8, i & 16},
               solved = true;
          for (int it = 0; it < t.size(); ++ it) {
            for (int jt = 0; jt < t[0].size(); ++ jt) {
              if (('1' == t[it][jt]) != (x[jt] xor y[it])) {
                solved = false;
                break;
              }
            }
            if (!solved) {
              break;
            }
          }
          if (solved) {
            return "Nice";
          }
        }
      }
      return "Not nice";
    }
};
