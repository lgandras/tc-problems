#include<cstring>
#include<algorithm>
#define MOD 1000000007LL

using namespace std;

class DerangementsDiv2 {
  public:
    long long c[51][51];
    long long comb(int m, int n) {
      if (-1 == this->c[m][n]) {
        if (n == m || 0 == n) {
          this->c[m][n] = 1;
        } else {
          this->c[m][n] = (this->comb(m - 1, n) + this->comb(m - 1, n - 1)) % MOD;
        }
      }
      return this->c[m][n];
    }
    int count(int n, int m) {
      memset(this->c, -1, sizeof(this->c[0][0]) * 51 * 51);
      long long fact = 1;
      for (int i = 1; i < n; ++ i) {
        fact *= i;
        fact %= MOD;
      }
      long long ret = 0;
      for (int i = 0; i <= m; ++ i) {
        fact *= max(1, n + i);
        fact %= MOD;
        ret += ((m - i) % 2 == 0 ? 1 : -1) * ((fact * this->comb(m, i)) % MOD) + MOD;
        ret %= MOD;
      }
      return ret;
    }
};
