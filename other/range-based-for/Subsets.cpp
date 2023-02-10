#pragma once

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
