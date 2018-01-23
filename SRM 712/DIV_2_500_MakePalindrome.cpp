#include<string>
#include<vector>

using namespace std;

class MakePalindrome {
  public:
    vector <string> constructMinimal(string card) {
       int c[26];
       for (int i = 0; i < 26; ++ i) {
         c[i] = 0;
       }
       for (int i = 0; i < card.size(); ++ i) {
         c[card[i] - 'a'] ++;
       }
       vector<string> ret;
       for (int i = 0; i < 26; ++ i) {
         if (c[i] % 2 == 1) {
           ret.push_back(string(c[i], 'a' + i));
         }
       }
       if (0 == ret.size()) {
         ret.push_back("");
       }
       for (int i = 0; i < 26; ++ i) {
         if (c[i] % 2 == 0) {
           string p = string(c[i] / 2, 'a' + i);
           ret[0] = p + ret[0] + p;
         }
       }
       return ret;
    }
};
