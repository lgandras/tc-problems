#include<string>
#include<vector>

using namespace std;

class Permutiple {
  public:
    bool isPossible(vector<int> d, int y, int x) {
      if (0 == d.size()) {
        return x != y && y % x == 0;
      }
      for (int i = 0; i < d.size(); ++ i) {
        vector<int> sd;
        for (int j = 0; j < d.size(); ++ j) {
          if (i != j) {
            sd.push_back(d[j]);
          }
        }
        if (this->isPossible(sd, y * 10 + d[i], x)) {
          return true;
        }
      }
      return false;
    }
    string isPossible(int x) {
      vector<int> d;
      for (int i = x; i > 0; i /= 10) {
        d.push_back(i % 10);
      }
      return this->isPossible(d, 0, x) ? "Possible" : "Impossible";
    }
};
