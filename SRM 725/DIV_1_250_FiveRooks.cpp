#include<string>
#include<vector>

using namespace std;

class FiveRooks {
  public:
    vector <int> find(vector <string> board) {
      for (int r1 = 0; r1 < 8; ++ r1) {
        for (int c1 = 0; c1 < 8; ++ c1) {
          if ('R' == board[r1][c1]) {
            for (int r2 = 0; r2 < 8; ++ r2) {
              for (int c2 = 0; c2 < 8; ++ c2) {
                if ('R' == board[r2][c2] && r1 != r2 && c1 != c2) {
                  for (int r3 = 0; r3 < 8; ++ r3) {
                    for (int c3 = 0; c3 < 8; ++ c3) {
                      if ('R' == board[r3][c3] && r1 != r3 && r2 != r3 && c1 != c3 && c2 != c3) {
                        for (int r4 = 0; r4 < 8; ++ r4) {
                          for (int c4 = 0; c4 < 8; ++ c4) {
                            if ('R' == board[r4][c4] && r1 != r4 && r2 != r4 && r3 != r4 && c1 != c4 && c2 != c4 && c3 != c4) {
                              for (int r5 = 0; r5 < 8; ++ r5) {
                                for (int c5 = 0; c5 < 8; ++ c5) {
                                  if ('R' == board[r5][c5] && r1 != r5 && r2 != r5 && r3 != r5 && r4 != r5 && c1 != c5 && c2 != c5 && c3 != c5 && c4 != c5) {
                                    vector<int> ret;
                                    ret.push_back(r1);
                                    ret.push_back(c1);
                                    ret.push_back(r2);
                                    ret.push_back(c2);
                                    ret.push_back(r3);
                                    ret.push_back(c3);
                                    ret.push_back(r4);
                                    ret.push_back(c4);
                                    ret.push_back(r5);
                                    ret.push_back(c5);
                                    return ret;
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      return vector<int>();
    }
};
