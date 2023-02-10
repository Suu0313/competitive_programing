#pragma once

template<class Container = vector<int>>
struct permutation{
  struct itr{
    Container c; bool fl;
    bool operator!=([[maybe_unused]] monostate e) const { return fl; }
    void operator++() { fl = next_permutation(std::begin(c), std::end(c)); }
    Container &operator*() { return c; }
  };

  Container c;
  permutation(int n): c(n) { iota(std::begin(c), std::end(c), 0); }
  permutation(const Container &c): c(c) {}

  itr begin(){ return {c, true}; }
  monostate end() { return {}; }
};
