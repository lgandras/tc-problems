#include<cstring>
#define MOD 1000000007

using namespace std;

class DerangementsDiv2 {
  public:
    int fact(long long x) {
      if (x == 0) {
        return 1;
      }
      return (x * this->fact(x - 1)) % MOD;
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
    int count(int n, int m, int i, int f) {
      long long ret = f * this->fact(n + m - i) * this->comb(m, i) % MOD;
      if (i < m) {
        ret += this->count(n, m, i + 1, f * -1) + MOD;
        ret %= MOD;
      }
      return ret;
    }
    int count(int n, int m) {
      memset(this->c, -1, sizeof(this->c[0][0]) * 51 * 51);
      return this->count(n, m, 0, 1);
    }
};
