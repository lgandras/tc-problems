#include<string>

using namespace std;

class StringTransform {
  public:
    string isPossible(string s, string t) {
      for (int i = t.size() - 1; i >= 0; -- i) {
        bool possible = false;
        for (int j = i; j >= 0; -- j) {
          if (s[j] == t[i]) {
            possible = true;
            break;
          }
        }
        if (!possible) {
          return "Impossible";
        }
      }
      return "Possible";
    }
};
