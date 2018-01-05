#include<vector>
#include<valarray>
#include<utility>
#include<iostream>

template <typename T>
std::vector<T> lagrange_interpolation(std::vector<std::pair<T, T> > points) {
  size_t h = points.size(), w = h + 1;
  std::valarray<T> a(h), x(w * h);
  for (int i = 0; i < h; ++ i) {
    x[w * i] = 1;
    for (int j = 1; j < h; ++ j) {
      x[w * i + j] = x[w * i + j - 1] * points[i].first;
    }
    x[w * i + h] = points[i].second;
  }
  for (int i = 0; i < h; ++ i) {
    for (int j = i + 1; j < h; ++ j) {
      // Potential compiler bug: https://stackoverflow.com/questions/48113627/valarray-in-place-operation-gives-different-result-as-a-temporary-assignment?noredirect=1#comment83203104_48113627
      // Do not attempt to do the following two instruction as a single one
      std::valarray<T> v = x[std::slice(j * w, w, 1)] - std::valarray<T>(x[std::slice(w * i, w, 1)]) * x[w * j + i] / x[w * i + i];
      x[std::slice(j * w, w, 1)] = v;
        
    }
  }
  for (int i = h - 1; i >= 0; -- i) {
    a[i] = (x[w * i + h] - (a * std::valarray<T>(x[std::slice(i * w, h, 1)])).sum()) / x[w * i + i];
  }
  std::vector<T> ret(h);
  for (int i = 0; i < h; ++ i) {
    ret[i] = a[i];
  }
  return ret;
};
