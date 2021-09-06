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
