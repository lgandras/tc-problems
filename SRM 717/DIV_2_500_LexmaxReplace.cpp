#include<string>
#include<algorithm>

using namespace std;

class LexmaxReplace {
  public:
    string get(string s, string t) {
      sort(t.begin(), t.end(), greater<char>());
      for (int i = 0; i < s.size(); ++ i) {
        for (int j = 0; j < t.size(); ++ j) {
          if (s[i] < t[j]) {
            s[i] = t[j];
            t[j] = 0;
          }
        }
      }
      return s;
    }
};
