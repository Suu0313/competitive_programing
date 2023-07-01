#pragma once

#include "./SuffixArray.cpp"

template<typename Container>
struct LongestCommonPrefixArray{
  SuffixArray<Container> sa;
  vector<int> lcp, rank;

  struct SparseTable{
    vector<vector<int>> table;
    vector<int> lookup;
    SparseTable() {}
    void build(const vector<int> &v){
      const int n = v.size(), b = 32 - __builtin_clz(n);
      table.assign(b, vector<int>(n)); lookup.assign(n+1, 0);
      for(int i = 0; i < n; i++) table[0][i] = v[i];
      for(int i = 1; i < b; i++){
        for(int j = 0; j+(1<<i) <= n; j++) table[i][j] = min(table[i-1][j], table[i-1][j+(1<<(i-1))]);
      }
      for(int i = 2; i < n+1; i++) lookup[i] = lookup[i>>1] + 1;
    }
    int fold(int l, int r) const { int b = lookup[r-l]; return min(table[b][l], table[b][r-(1<<b)]); }
  } st;

  LongestCommonPrefixArray(const Container &s, bool usermq = true): sa(s), lcp(sa.size()), rank(sa.size()), st(){
    int n = sa.size();
    for(int i = 0; i < n; i++) rank[sa[i]] = i;
    for(int i = 0, h = 0; i < n; i++) if(int nr = rank[i] + 1; nr < n){
      for(int j = sa[nr]; max(i,j)+h<n && sa.s[i+h]==sa.s[j+h]; h++);
      lcp[nr] = h;
      if(h > 0) h--;
    }
    if(usermq) st.build(lcp);
  }

  size_t size() const { return lcp.size(); }
  int operator[](int k) const { return lcp[k]; }
  int get(int k) const { return lcp[rank[k]]; }
  int fold(int i, int j) const {
    auto&&[l,r] = minmax(rank[i], rank[j]);
    return st.fold(l+1, r+1);
  }

  void dump() const {
    int n = size();
    for(int i = 0; i < n; i++){
      cout << i << ": " << sa[i] << ", " << lcp[i] << " [ ";
      for(int j = sa[i]; j < n; j++) cout << sa.s[j] << " ";
      cout << " ]\n";
    }
  }
};
