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
