#include <bits/stdc++.h>
using namespace std;

struct BitVector{
  using u16 = uint16_t;
  using u32 = uint32_t;

  static constexpr int b_sz = 16;
  static constexpr int s_ws = 16;
  static constexpr int l_ws = 512;

  vector<u16> b_vector;
  vector<u32> l_block;
  vector<u16> s_block;
  u32 cnt_one = 0;

  static int popCount(u32 x){ return __builtin_popcountll(x); }
  static u32 bitMask(int n){ return (u32(1) << n) - 1; }

  BitVector() = default;
  BitVector(const BitVector&) = default;
  BitVector(BitVector&&) = default;
  BitVector(const vector<bool> &bit){ init(bit); }

  BitVector &operator=(const BitVector&) = default;
  BitVector &operator=(BitVector&&) = default;

  void init(const vector<bool> &bit){
    const int n = int(bit.size());
    b_vector.assign(n / b_sz + 1, 0);

    for(int i = 0; i < n; ++i){
      if(!bit[i]) continue;
      b_vector[i / b_sz] |= 1 << (i % b_sz);
    }

    l_block.assign(n / l_ws + 1, 0);
    s_block.assign(n / s_ws + 1, 0);

    for(int i = 0; i <= n; ++i){
      if(i % l_ws == 0) l_block[i / l_ws] = cnt_one;
      if(i % s_ws == 0) s_block[i / s_ws] = cnt_one - l_block[i / l_ws];

      if(i != n && i % b_sz == 0) cnt_one += popCount(b_vector[i / b_sz]);
    }
  }

  bool access(int t) const { return (b_vector[t / b_sz] >> (t % b_sz) & 1); }
  int rank0(int t) const { return t - rank1(t); }
  int rank1(int t) const {
    return l_block[t / l_ws] + s_block[t / s_ws]
    + popCount(b_vector[t / b_sz] & bitMask(t % b_sz));
  }

  int select0(int t) const;
  int select1(int t) const;
};


template<size_t bn, typename T>
struct WaveletMatrix{
  array<BitVector, bn> bitvectors = {};
  array<size_t, bn> boundary = {};
  vector<T> a;
  
  WaveletMatrix() = default;
  WaveletMatrix(const vector<T> &a): a(a) { init(a); }

  void init(vector<T> whole){
    size_t n = whole.size();
    for(size_t i = bn; i--; ){
      vector<T> zero, one;
      vector<bool> bv(n);
      for(size_t j = 0; j < n; ++j){
        ((whole[j] >> i & 1) ? one : zero).push_back(whole[j]);
        bv[j] = (whole[j] >> i & 1);
      }

      boundary[bn - i - 1] = zero.size();
      bitvectors[bn - i - 1].init(bv);

      if(i == 0) break;
      swap(whole, zero);
      whole.insert(end(whole), begin(one), end(one));
    }
  }

  const T &operator[](int t) const { return a[t]; }

  // count x in a[s, t)
  int rank(const T &x, int s, int t) const {
    return rank_leg(x, s, t)[1];
  }

  // count x \in [l, r) in a[s, t)
  int rank(const T &l, const T &r, int s, int t) const {
    return rank_leg(r, s, t)[0] - rank_leg(l, s, r)[0];
  }

  array<int, 3> rank_leg(const T &x, int s, int t) const {
    if(s >= t) return {0, 0, 0};
    int lt = 0, gt = 0;

    for(size_t i = bn; i--; ){
      size_t j = bn - i - 1;
      int len = t - s;
      if(x >> i & 1){
        s = boundary[j] + bitvectors[j].rank1(s);
        t = boundary[j] + bitvectors[j].rank1(t);
      }else{
        s = bitvectors[j].rank0(s);
        t = bitvectors[j].rank0(t);
      }
      ((x >> i & 1) ? lt : gt) += len - (t - s);
    }
    return {lt, t - s, gt};
  }
};
