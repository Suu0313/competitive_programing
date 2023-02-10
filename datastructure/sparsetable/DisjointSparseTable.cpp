#pragma once


template<typename SemiGroup>
struct DisjointSparseTable{
  vector<vector<SemiGroup>> table;
  vector<int> lookup;

  DisjointSparseTable() = default;
  template<class Iiter>
  DisjointSparseTable(Iiter first, Iiter last): table(1, vector<SemiGroup>(first, last)){
    size_t n = table[0].size();
    for(size_t i = 1, b = 1; b < n; ++i, b <<= 1){
      table.push_back(table[0]);
      for(size_t j = 0; j < n; j += b << 2){
        size_t t = min(j + (b << 1), n), r = min(t + (b << 1), n);
        for(size_t k = 0; t >= j+2+k; ++k) table[i][t-2-k] = table[0][t-2-k] + table[i][t-1-k];
        if(n <= t) break;
        for(size_t k = t+1; k < r; k++) table[i][k] = table[i][k - 1] + table[0][k];
      }
    }
    lookup.assign(1 << table.size(), 0);
    for(size_t i = 2; i < lookup.size(); i++) lookup[i] = lookup[i >> 1] + 1;
  }
  template<class Container>
  DisjointSparseTable(const Container &c): DisjointSparseTable(begin(c), end(c)) {}


  SemiGroup query(int l, int r) const {
    if(l >= r) return SemiGroup{};
    if(l >= --r) return table[0][l];
    int p = lookup.at(l ^ r);
    return table[p][l] + table[p][r];
  }
};
