struct subsets{
  struct itr{
    uint64_t s, t;
    bool operator!=([[maybe_unused]] monostate e){ return (t&s) != 0; }
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
    vector<int> idx; bool fl;
    bool operator!=([[maybe_unused]] monostate e){ return fl; }
    void operator++() { fl = next_permutation(idx.begin(), idx.end()); }
    vector<int> &operator*() { return idx; }
  };

  int n;
  permutation(int n): n(n) {}

  itr begin(){ vector<int> idx(n); iota(idx.begin(), idx.end(), 0); return {idx, true}; }
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

struct product{
  struct itr{
    int current;
    vector<int> res;
    product *p;
    bool operator!=([[maybe_unused]] monostate e){ return current != (p->upper); }
    void operator++(){ ++current; }
    const vector<int> &operator*(){
      int pos = current, i = 0;
      for(auto&&e : p->bases){ res[i++] = pos % e; pos /= e; }
      return res;
    }
  };
  vector<int> bases;
  int n, upper;
  product(const vector<int> &bases): bases(bases), n(bases.size()), upper(1) {
    for(auto&&e : bases) upper *= e;
  }
  product(int base, int n): bases(n), n(n), upper(1) {
    for(auto&&e : bases) upper *= (e = base);
  }

  itr begin(){ return {0, vector<int>(n), this}; }
  monostate end() { return {}; }
};
