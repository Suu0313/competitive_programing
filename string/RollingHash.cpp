struct RollingHash{
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

  inline void expand(size_t n){
    if(size_t pn = pow_table.size(); pn < n+1){
      pow_table.resize(n + 1);
      for(size_t i = pn-1; i < n; ++i){
        pow_table[i+1] = cal_mod(mul(pow_table[i], base));
      }
    }
  }

  const uint64_t base;
  vector<uint64_t> pow_table;

  RollingHash(uint64_t base = generate_base()): base(base), pow_table(1,1) {}

  vector<uint64_t> build(const string &s) const {
    int n = int(s.size());
    vector<uint64_t> res(n + 1);
    for(int i = 0; i < n; ++i) res[i+1] = cal_mod(mul(res[i], base) + s[i]);
    return res;
  }

  template<typename T>
  vector<uint64_t> build(const vector<T> &s) const {
    int n = int(s.size());
    vector<uint64_t> res(n + 1);
    for(int i = 0; i < n; ++i) res[i+1] = cal_mod(mul(res[i], base) + s[i]);
    return res;
  }

  uint64_t query(const vector<uint64_t> &s, int l = 0, size_t n = string::npos){
    n = min(n, s.size()-1 - l);
    expand(n);
    return cal_mod(s[l+n] + mod*4 - mul(s[l], pow_table[n]));
  }

  uint64_t cat(uint64_t hl, uint64_t hr, size_t hr_len){
    expand(hr_len);
    return cal_mod(mul(hl, pow_table[hr_len]) + hr);
  }

  int lcp(const vector<uint64_t> &a, int la, int ra, const vector<uint64_t> &b, int lb, int rb){
    int n = min(ra - la, rb - lb);
    int l = 0, r = n+1;
    while(r-l > 1){
      int m = (l+r) >> 1;
      if(query(a, la, m) == query(b, lb, m)) l = m;
      else r = m;
    }
    return l;
  }
};
