#include<vector>

using namespace std;

class LongMansionDiv2 {
  public:
    long long minimalTime(int M, vector <int> t);
};

long long LongMansionDiv2::minimalTime(int M, vector <int> t) {
  long long ret = 0, m = 1 << 30;
  for (int i = 0; i < t.size(); ++ i) {
    ret += t[i];
    m = m < t[i] ? m : t[i];
  }
  ret += (M - 1) * (long long)m;
  return ret;
};
