#include<vector>
#include<string>

using namespace std;

class TurtleGame {
  public:
    string getwinner(vector <string> board) {
      int o = 0;
      for (int i = 0; i < board.size(); ++ i) {
        for (int j = 0; j < board[0].size(); ++ j) {
          o += '#' == board[i][j];
        }
      }
      return ((board.size() - 1) * (board[0].size() - 1) - o) % 2 ? "Win" : "Lose";
    }
};
