#include<string>
#include<vector>
#include<utility>

using namespace std;

class FiveRooks {
  public:
    vector<int> find_aux(vector<string> board, vector<pair<int, int> > used, int level) {
      for (int r = 0; r < 8; ++ r) {
        for (int c = 0; c < 8; ++ c) {
          if ('R' == board[r][c]) {
            bool available = true;
            for (int i = 0; i < used.size(); ++ i) {
              if (used[i].first == r || used[i].second == c) {
                available = false;
                break;
              }
            }
            if (available) {
              vector<int> ret;
              if (1 < level) {
                used.push_back(pair<int, int>(r, c));
                ret = this->find_aux(board, used, level - 1);
                if (0 == ret.size()) {
                  used.pop_back();
                  continue;
                }
              }
              ret.push_back(r);
              ret.push_back(c);
              return ret;
            }
          }
        }
      }
      return vector<int>();
    }
    vector <int> find(vector <string> board) {
      return this->find_aux(board, vector<pair<int, int> >(), 5);
    }
};
