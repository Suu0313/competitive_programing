#pragma once

#include ".\\BitVector.cpp"

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

  int rank(const T &l, const T &r, int s, int t) const {
    return rank_leg(r, s, t)[0] - rank_leg(l, s, t)[0];
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

  // pos of kth x
  int select(const T &x, int k) const;

  T kth_smallest(int s, int t, int k) const {
    T ret = 0;
    for(size_t i = bn; i--; ){
      size_t j = bn - i - 1;
      int z = bitvectors[j].rank0(s, t);

      if(k < z){
        s = bitvectors[j].rank0(s);
        t = bitvectors[j].rank0(t);
      }else{
        ret |= T(1) << i;
        s = boundary[j] + bitvectors[j].rank1(s);
        t = boundary[j] + bitvectors[j].rank1(t);
        k -= z;
      }
    }
    return ret;
  }

  T kth_largest(int s, int t, int k) const {
    return kth_smallest(s, t, (t - s) - k - 1);
  }

  vector<pair<T, int>> top_k(int s, int t, int k) const {
    vector<pair<T, int>> res; res.reserve(k);
    using ti4t = tuple<int, int, int, size_t, T>; // width, left, right, depth, value;
    auto cmp = [](const ti4t &l, const ti4t &r) -> bool {
      if(get<0>(l) != get<0>(r)) return get<0>(l) < get<0>(r);
      if(get<3>(l) != get<3>(r)) return get<3>(l) > get<3>(r);
      if(get<4>(l) != get<4>(r)) return get<4>(l) > get<4>(r);
      return true;
    };
    priority_queue<ti4t, vector<ti4t>, decltype(cmp)> pq{cmp};
    pq.emplace(t - s, s, t, 0, 0);

    while(!pq.empty()){
      auto[width, left, right, depth, value] = pq.top(); pq.pop();
      if(depth >= bn){
        res.emplace_back(value, width);
        if(int(res.size()) >= k) break;
        continue;
      }

      int nl = bitvectors[depth].rank0(left);
      int nr = bitvectors[depth].rank0(right);
      if(nl != nr) pq.emplace(nr - nl, nl, nr, depth+1, value);

      nl = bitvectors[depth].rank1(left);
      nr = bitvectors[depth].rank1(right);
      if(nl != nr) pq.emplace(nr - nl, nl, nr, depth+1, value | (T(1) << (bn - depth - 1)));
    }
    return res;
  }

  vector<pair<T, int>> intersect(int s1, int t1, int s2, int t2) const;

  // min x s.t. l <= x < r in a[s, t)
  T get_min(const T &l, const T &r, int s, int t) const {
    using t5_t = tuple<int, int, size_t, T, int>; // left, right, depth, value, tight;
    stack<t5_t> st; st.emplace(s, t, 0, 0, 1);

    while(!st.empty()){
      auto[left, right, depth, value, tight] = st.top(); st.pop();
      if(depth == bn){
        if(value < r) return value;
        continue;
      }
      
      int nl = boundary[depth] + bitvectors[depth].rank1(left);
      int nr = boundary[depth] + bitvectors[depth].rank1(right);
      int bit = (l >> (bn - depth - 1)) & 1;

      if(nl != nr) st.emplace(nl, nr, depth+1, (value << 1) | 1, tight & bit);

      nl = bitvectors[depth].rank0(left);
      nr = bitvectors[depth].rank0(right);
      if(nl != nr && (!(tight && bit))) st.emplace(nl, nr, depth+1, value << 1, tight);
    }

    return -1;
  }

  // max x s.t. l <= x < r in a[s, t)
  T get_max(const T &l, const T &r, int s, int t) const {
    using t5_t = tuple<int, int, size_t, T, int>; // left, right, depth, value, tight;
    stack<t5_t> st; st.emplace(s, t, 0, 0, 1);

    while(!st.empty()){
      auto[left, right, depth, value, tight] = st.top(); st.pop();
      if(depth == bn) return value;

      int nl = bitvectors[depth].rank0(left);
      int nr = bitvectors[depth].rank0(right);
      int bit = (l >> (bn - depth - 1)) & 1;
      T nval = T(1) << (bn - depth - 1);
      if(nl != nr && (!(tight && bit))) st.emplace(nl, nr, depth+1, value, tight);
      
      nl = boundary[depth] + bitvectors[depth].rank1(left);
      nr = boundary[depth] + bitvectors[depth].rank1(right);
      if(nl != nr && ((value | nval) < r)) st.emplace(nl, nr, depth+1, value | nval, tight & bit); 
    }

    return -1;
  }

  // (x, c) s.t. l <= x < r, c = #{i | ai = x}
  vector<pair<T, int>> enumerate(const T &l, const T &r, int s, int t) const;
};
