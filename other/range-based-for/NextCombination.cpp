#pragma once

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
