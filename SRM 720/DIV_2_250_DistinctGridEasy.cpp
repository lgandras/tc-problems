#include<vector>
#include<set>
#include<string>

using namespace std;

class DistinctGridEasy {
  public:
    string checkGrid(int n, int k, vector <int> grid);
};

string DistinctGridEasy::checkGrid(int n, int k, vector <int> grid) {
  set<int> c[50], r[50];
  for (int i = 0; i < n; ++ i) {
    for (int j = 0; j < n; ++ j) {
      r[i].insert(grid[i * n + j]);
      c[i].insert(grid[j * n + i]);
    }
  }
  for (int i = 0; i < n; ++ i) {
    if (r[i].size() != k || c[i].size() != k) {
      return "Bad";
    }
  }
  return "Good";
}
