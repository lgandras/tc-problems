#include<algorithm>

using namespace std;

class TopXorerEasy {
  public:
    int maximalRating(int A, int B, int C);
};

int TopXorerEasy::maximalRating(int A, int B, int C) {
  int p = 1, m = max(A, max(B, C));
  if (0 == m) {
    return 0;
  }
  m >>= 1;
  while (0 < m) {
    p *= 2;
    m /= 2;
  }
  int ret = 0;
  for (int i = p; i > 0; i /= 2) {
    if (i & A) {
      ret += i;
      if (i & B || i & C) {
        return ret + i - 1;
      }
    } else if (i & B) {
      ret += i;
      if (i & C) {
        return ret + i - 1;
      }
    } else if (i & C) {
      ret += i;
    }
  }
  return ret;
}
