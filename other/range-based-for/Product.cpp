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
