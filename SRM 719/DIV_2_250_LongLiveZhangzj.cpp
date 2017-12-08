#include<string>
#include<vector>

using namespace std;

class LongLiveZhangzj {
  public:
    int donate(vector <string> speech, vector <string> words);
};

int LongLiveZhangzj::donate(vector <string> speech, vector <string> words) {
  int ret = 0;
  for (int i = 0; i < speech.size(); ++ i) {
    for (int j = 0; j < words.size(); ++ j) {
      if (speech[i] == words[j]) {
        ++ ret;
        break;
      }
    }
  }
  return ret;
};
