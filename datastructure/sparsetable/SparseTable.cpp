template<typename Band>
struct SparseTable{
  vector<vector<Band>> table;
  vector<int> lookup;
  
  SparseTable() = default;
  template<class Iiter>
  SparseTable(Iiter first, Iiter last): table(1, vector<Band>(first, last)){
    size_t n = table[0].size();
    for(size_t i = 1, b = 1; b < table.back().size(); ++i, b <<= 1){
      table.emplace_back(); table.reserve(n - b);
      for(size_t j = b; j < table[i-1].size(); ++j){
        table[i].push_back(table[i-1][j - b] + table[i-1][j]);
      }
    }
    lookup.assign(n + 1, 0);
    for(size_t i = 2; i < n+1; i++) lookup[i] = lookup[i >> 1] + 1;
  }
  template<class Container>
  SparseTable(const Container &c): SparseTable(begin(c), end(c)) {}
  

  Band fold(int l, int r) const {
    if(l == r) return Band{};
    int b = lookup[r - l];
    return table[b][l] + table[b][r - (1 << b)];
  }
};
