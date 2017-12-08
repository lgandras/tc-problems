#include<vector>
#include<string>

using namespace std;

class GravityPuzzleEasy {
  public:
    vector <string> solve(vector <string> board) {
      for (int i = 0; i < board[0].size(); ++ i) {
        int t = 0, b = board.size() - 1;
        while (true) {
          while (t < b && board[t][i] == '.') {
            ++ t;
          }
          while (t < b && board[b][i] == '#') {
            -- b;
          }
          if (b == t) {
            break;
          }
          board[t][i] = '.';
          board[b][i] = '#';
        }
      }
      return board;
    }
};
