#define M 1000000007

using namespace std;

class SimpleMazeEasy {
  public:
    int findSum(long long n) {
      long long c = n % 3, m = n / 3 % M;
      n %= M;
      // lagrange interpolation with {(0, 0), (1, 16), (2, 600), (3, 4680), (4, 19904), (5, 61000)}
      if (0 == c) {
        // f(x) = n^3 * (59 * n^2 - 11) / 3
        return ((m * n % M) * n % M) * (((n * n % M) * 59 - 11) % M) % M;
      } else if (1 == c) {
        // f(x) = n^3 * (59 * (3 * m + 1)^2 - 11) / 3 = n^3 * (177 * m^2 + 118 * m + 16)
        return ((n * n % M) * n % M) * (((m * m % M) * 177 + m * 118 + 16) % M) % M;
      } else {
        // f(x) = n^3 * (59 * (3 * m + 2)^2 - 11) / 3 = n^3 * (177 * m^2 + 236 * m + 75)
        return ((n * n % M) * n % M) * (((m * m % M) * 177 + m * 236 + 75) % M) % M;
      }
    }
};

