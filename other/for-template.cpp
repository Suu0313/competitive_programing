struct subsets{
  struct itr{
    uint64_t s, t;
    bool operator!=(monostate e){ return (t&s) != 0; }
    void operator++() { t -= 1; }
    uint64_t operator*() { return t &= s; }
  };

  uint64_t s;
  subsets(uint64_t s) : s(s) {}

  itr begin() { return {s, (s-1)&s}; }
  monostate end() { return {}; }
};

struct combination{
  struct itr{
    uint64_t bit;
    bool operator!=(uint64_t e){ return bit < e; }
    void operator++() {
      uint64_t buff = bit | (bit-1);
      bit = (buff+1) | (((~ buff & - ~ buff) - 1) >> (__builtin_ctzll(bit) + 1));
    }
    uint64_t operator*() { return bit; }
  };

  int n, k;
  combination(int n, int k) : n(n), k(k) {}

  itr begin() { return {(1ull << k)-1}; }
  uint64_t end() { return 1ull << n; }
};

struct permutation{
  struct itr{
    vector<int> idx;
    bool operator!=(monostate e){ return next_permutation(idx.begin(), idx.end()); }
    void operator++() {}
    vector<int> operator*() { return idx; }
  };

  int n;
  permutation(int n): n(n) {}

  itr begin(){ vector<int> idx(n); iota(idx.begin(), idx.end(), 0); return {idx}; }
  monostate end() { return {}; }
};

struct supersets{
  struct itr{
    uint64_t s, t;
    bool operator!=(uint64_t e){ return (t|s) < e; }
    void operator++() { t += 1; }
    uint64_t operator*() { return t |= s; }
  };

  int n;
  uint64_t s;
  supersets(int n, uint64_t s) : n(n), s(s) {}

  itr begin() { return {s, s}; }
  uint64_t end() { return 1ull << n; }
};
