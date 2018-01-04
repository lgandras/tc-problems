#include<string>

using namespace std;

class StringHalving {
  public:
    string lexsmallest(string s) {
      bool r[26];
      for (int i = 0; i < 26; ++ i) {
        r[i] = false;
      }
      int m = -1;
      for (int i = 0; i < s.size(); ++ i) {
        if (!r[s[i] - 'a']) {
          r[s[i] - 'a'] = true;
        } else {
          break;
        }
        if (-1 == m || s[i] < s[m]) {
          m = i;
        }
      }
      return string(1, s[m]);
    }
};
