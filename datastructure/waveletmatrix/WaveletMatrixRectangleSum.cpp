#pragma once

#include ".\\WaveletMatrix.cpp"

template<size_t bn, typename T, typename V>
struct WaveletMatrixRectangleSum : WaveletMatrix<bn, T> {
  vector<V> vs[bn];
  using WaveletMatrix<bn, T>::bitvectors;
  using WaveletMatrix<bn, T>::boundary;
  WaveletMatrixRectangleSum() = default;
  WaveletMatrixRectangleSum(const vector<T> &a, const vector<V> &v): WaveletMatrix<bn, T>(a) { init(a, v); }

  void init(const vector<T> &a, const vector<V> &v){
    size_t n = a.size();
    vector<int> ord(n); iota(begin(ord), end(ord), 0);
    for(size_t i = bn; i--; ){
      vector<int> zero, one;
      for(size_t j = 0; j < n; ++j) (bitvectors[bn-i-1].access(j) ? one : zero).push_back(ord[j]);
      swap(ord, zero);
      ord.insert(end(ord), begin(one), end(one));
      size_t j = bn - i - 1;
      vs[j].assign(n + 1, 0);
      for(size_t k = 0; k < n; ++k) vs[j][k+1] = vs[j][k] + v[ord[k]];
    }
  }

  // sum v[i] | s <= i < t, a[i] < x
  V sum(const T &x, int s, int t) const {
    V res = 0;
    for(size_t i = bn; i--; ){
      size_t j = bn - i - 1;
      if(x >> i & 1){
        res += vs[j][bitvectors[j].rank0(t)] - vs[j][bitvectors[j].rank0(s)];
        s = boundary[j] + bitvectors[j].rank1(s);
        t = boundary[j] + bitvectors[j].rank1(t);
      }else{
        s = bitvectors[j].rank0(s);
        t = bitvectors[j].rank0(t);
      }
    }
    return res;
  }

  V sum(const T &l, const T &r, int s, int t) const {
    return sum(r, s, t) - sum(l, s, t);
  }
};
