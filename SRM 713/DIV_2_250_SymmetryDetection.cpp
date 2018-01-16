#include<vector>
#include<string>

using namespace std;

class SymmetryDetection {
  public:
    string detect(vector <string> board) {
      int ret = 3, n = board.size(), m = board[0].size();
      for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m / 2; ++ j) {
          if (board[i][j] != board[i][m - j - 1]) {
            ret &= ~1;
            break;
          }
        }
      }
      for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n / 2; ++ j) {
          if (board[j][i] != board[n - j - 1][i]) {
            ret &= ~2;
            break;
          }
        }
      }
      return 3 == ret ? "Both" : (2 == ret ? "Horizontally symmetric" : (1 == ret ? "Vertically symmetric" : "Neither"));
    }
};
