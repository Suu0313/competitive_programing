struct divide{
  struct itr{
    uint64_t s;
    int n;
    bool operator!=([[maybe_unused]] monostate e){ return s != 1ull<<n; }
    void operator++(){ ++s; }
    vector<vector<int>> operator*(){
      vector<vector<int>> res(1, vector<int>(1, 0));
      for(int i = 0; i < n; ++i){
        if(s>>i & 1) res.emplace_back(1, i+1);
        else res.back().emplace_back(i+1);
      }
      return res;
    }
  };
  int n;
  divide(int n): n(n) {}

  itr begin(){ return {0, n-1}; }
  monostate end() { return {}; }
};
