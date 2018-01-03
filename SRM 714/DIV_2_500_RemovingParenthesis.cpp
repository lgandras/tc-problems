#include<string>
#include<cstring>

using namespace std;

class RemovingParenthesis {
  int dp[1048576];
  string s;
  int countWays(int c) {
    int *ret = &dp[c];
    if (-1 != *ret) {
      return *ret;
    }
    if (0 == c) {
      *ret = 1;
      return *ret;
    }
    *ret = 0;
    int acc = 0, start = -1;
    for (int i = 0; i < s.size(); ++ i) {
      if ((1 << i) & c) {
        if (-1 == start) {
          start = i;
        }
        acc += '(' == s[i] ? 1 : -1;
        if (acc < 0) {
          return *ret;
        }
      }
    }
    if (acc != 0) {
      return *ret;
    }
    c &= ~(1 << start);
    for (int i = start + 1; i < s.size(); ++ i) {
      if (')' == s[i]) {
        *ret += this->countWays(c & ~(1 << i));
      }
    }
    return *ret;
  }
  public:
    int countWays(string s) {
      this->s = s;
      memset(dp, -1, 1048576 * sizeof(dp[0]));
      return this->countWays((1 << s.size()) - 1);
    }
};
