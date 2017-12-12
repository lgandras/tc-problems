#include<cstring>
#define MOD 1000000007LL

using namespace std;

class DerangementsDiv2 {
  public:
    long long f[101];
    long long fact(int x) {
      if (-1 == this->f[x]) {
        if (0 == x) {
          this->f[x] = 1;
        } else {
          this->f[x] = (x * this->fact(x - 1)) % MOD;
        }
      }
      return this->f[x];
    }
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
      memset(this->f, -1, sizeof(this->f[0]) * 101);
      memset(this->c, -1, sizeof(this->c[0][0]) * 51 * 51);
      long long ret = 0;
      for (int i = 0; i <= m; ++ i) {
        ret += (i % 2 == 0 ? 1 : -1) * ((this->fact(n + m - i) * this->comb(m, i)) % MOD) + MOD;
        ret %= MOD;
      }
      return ret;
    }
};
