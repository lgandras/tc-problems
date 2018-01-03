#include<string>
#include<algorithm>

using namespace std;

class MaximumRange {
  public:
    int findMax(string s) {
      int c[] = {0, 0, 0};
      for (int i = 0; i < s.size(); ++ i) {
        c[s[i] - '+'] ++;
      }
      return max(c[0], c[2]);
    }
};
