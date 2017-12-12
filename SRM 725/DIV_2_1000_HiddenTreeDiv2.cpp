#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

class HiddenTreeDiv2 {
  public:
    long long dp[16384], a[16384], b[16384]; // 2 ^ 14
    long long traverse(int k) {
      long long *ret = &dp[k];
      if (-1 != *ret) {
        return *ret;
      }
      vector<int> v;
      for (int i = 1; i <= k; i <<= 1) {
        if (k & i) {
          v.push_back(i);
        }
      }
      if (1 == v.size()) {
        *ret = (a[v[0]] == b[v[0]]) ? b[v[0]] : 0;
        return *ret;
      }
      for (int i = 0; i < v.size(); ++ i) {
        if (this->a[v[i]] < this->b[v[i]]) {
          int g = 0;
          for (int j = 0; j < v.size(); ++ j) {
            if (j != i) {
              g |= v[j];
            }
          }
          if (this->b[v[i]] - this->a[v[i]] == this->traverse(g)) {
            *ret = this->b[v[i]];
            return *ret;
          }
        }
      }
      for (int i = 1; i < (1 << v.size()) - 2; ++ i) {
        int a = 0, b = 0;
        for (int l = 0, j = 1; l < v.size(); ++ l, j <<= 1) {
          if (i & j) {
            a |= v[l];
          } else {
            b |= v[l];
          }
        }
        long long wa = this->traverse(a);
        long long wb = this->traverse(b);
        if (0 < wa && 0 < wb) {
          *ret = wa + wb;
          return *ret;
        }
      }
      *ret = 0;
      return *ret;
    }
    string isPossible(vector <int> a, vector <int> b) {
      for (int i = 0, j = 1; i < a.size(); ++ i, j <<= 1) {
        this->a[j] = a[i];
        this->b[j] = b[i];
      }
      memset(dp, -1, sizeof(dp[0]) * 16384);
      return 0 < this->traverse((1 << a.size()) - 1) ? "Possible" : "Impossible";
    }
};
