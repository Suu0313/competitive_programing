#pragma once

struct RollingHash2D{
  static constexpr uint64_t mod = (1ull << 61) - 1;
  static constexpr uint64_t mask(int k){ return (1ull << k) - 1; }
  static constexpr uint64_t add(uint64_t a, uint64_t b){
    return ((a+=b) >= mod) ? (a - mod) : a;
  }
  static constexpr uint64_t mul(uint64_t a, uint64_t b){
    uint64_t au = a >> 31, ad = a & mask(31);
    uint64_t bu = b >> 31, bd = b & mask(31);
    int64_t mid = ad*bu + au*bd;
    uint64_t mu = mid >> 30, md = mid & mask(30);
    return au*bu*2 + mu + (md << 31) + ad*bd;
  }
  static constexpr uint64_t cal_mod(uint64_t x){
    uint64_t res = (x >> 61) + (x & mask(61));
    return (res>=mod) ? (res-mod) : res;
  }

  static inline uint64_t generate_base(){
    mt19937_64 mt(random_device{}());
    uniform_int_distribution<uint64_t> rand(1, mod-1);
    return rand(mt);
  }

  inline void expand1(size_t n){
    if(size_t pn = pow_table1.size(); pn < n+1){
      pow_table1.resize(n + 1);
      for(size_t i = pn-1; i < n; ++i){
        pow_table1[i+1] = cal_mod(mul(pow_table1[i], base1));
      }
    }
  }

  inline void expand2(size_t n){
    if(size_t pn = pow_table2.size(); pn < n+1){
      pow_table2.resize(n + 1);
      for(size_t i = pn-1; i < n; ++i){
        pow_table2[i+1] = cal_mod(mul(pow_table2[i], base2));
      }
    }
  }

  const uint64_t base1, base2;
  vector<uint64_t> pow_table1, pow_table2;

  RollingHash2D(uint64_t base1 = generate_base(), uint64_t base2 = generate_base())
  : base1(base1), base2(base2), pow_table1(1,1), pow_table2(1,1) {}

  vector<vector<uint64_t>> build(const vector<string> &s) const {
    int n = int(s.size()), m = int(s[0].size());
    vector<vector<uint64_t>> res(n + 1, vector<uint64_t>(m + 1));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        res[i+1][j+1] = cal_mod(mul(res[i+1][j], base2) + s[i][j]);
      }
    }
    for(int j = 0; j < m; ++j){
      for(int i = 0; i < n; ++i){
        res[i+1][j+1] = cal_mod(mul(res[i][j+1], base1) + res[i+1][j+1]);
      }
    }
    return res;
  }

  template<typename T>
  vector<vector<uint64_t>> build(const vector<vector<T>> &s) const {
    int n = int(s.size()), m = int(s[0].size());
    vector<vector<uint64_t>> res(n + 1, vector<uint64_t>(m + 1));
    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        res[i+1][j+1] = cal_mod(mul(res[i+1][j], base2) + s[i][j]);
      }
    }
    for(int j = 0; j < m; ++j){
      for(int i = 0; i < n; ++i){
        res[i+1][j+1] = cal_mod(mul(res[i][j+1], base1) + res[i+1][j+1]);
      }
    }
    return res;
  }

  uint64_t query(const vector<vector<uint64_t>> &s, int l, int r, int d, int u){
    expand1(r - l);
    expand2(u - d);
    uint64_t p1 = pow_table1[r-l], p2 = pow_table2[u-d];
    
    return cal_mod(cal_mod(s[r][u] + mod*4 - cal_mod(mul(s[r][d], p2)))
      + cal_mod(mul(s[l][d], cal_mod(mul(p1, p2))) + mod*4 - cal_mod(mul(s[l][u], p1)))
      );
  }
};
