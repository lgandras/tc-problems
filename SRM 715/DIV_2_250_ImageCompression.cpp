#include<string>
#include<vector>

using namespace std;

class ImageCompression {
  public:
    string isPossible(vector <string> image, int k) {
      for (int i = 0; i < image.size(); i += k) {
        for (int j = 0; j < image[0].size(); j += k) {
          char b = image[i][j];
          for (int ii = i; ii < i + k; ++ ii) {
            for (int jj = j; jj < j + k; ++ jj) {
              if (b != image[ii][jj]) {
                return "Impossible";
              }
            }
          }
        }
      }
      return "Possible";
    }
};
