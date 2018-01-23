#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class RepeatNumberCompare {
  public:
    string compare(int x1, int k1, int x2, int k2) {
      vector<char> d1, d2;
      for (; x1 > 0; x1 /= 10) {
        d1.push_back('0' + (x1 % 10));
      }
      for (; x2 > 0; x2 /= 10) {
        d2.push_back('0' + (x2 % 10));
      }
      if (d1.size() * k1 < d2.size() * k2) {
        return "Less";
      } else if (d2.size() * k2 < d1.size() * k1) {
        return "Greater";
      }
      string s1 = "", s2 = "";
      for (int i = 0; i < d1.size() * k1; ++ i) {
        s1 += d1[d1.size() - 1 - i % d1.size()];
        s2 += d2[d2.size() - 1 - i % d2.size()];
      }
      return s1.compare(s2) < 0 ? "Less" : (s2.compare(s1) < 0 ? "Greater" : "Equal");
    }
};
