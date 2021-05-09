struct SuffixArray{ // O(Nlog^2N)
  vector<int> sa;
  const string s;

  SuffixArray(const string &s): sa(s.size()), s(s) {
    iota(sa.begin(), sa.end(), 0);

    int n = s.size();
    vector<int> rank(n), tmp(n);
    for(int i = 0; i < n; i++) rank[i] = s[i];

    int k = 1;
    auto cmp = [&](int i, int j){
      if(rank[i] != rank[j]) return rank[i] < rank[j];
      int ni = (i+k < n) ? rank[i+k] : -1;
      int nj = (j+k < n) ? rank[j+k] : -1;
      return ni < nj;
    };

    for(; k < n; k <<= 1){
      sort(sa.begin(), sa.end(), cmp);
      tmp[sa[0]] = 0;
      for(int i = 0; i < n-1; i++) tmp[sa[i+1]] = tmp[sa[i]] + cmp(sa[i], sa[i+1]);
      for(int i = 0; i < n; i++) rank[i] = tmp[i];
    }
  }

  int operator[](int k) const { return sa[k]; }
  size_t size() const { return s.size(); }

  int cmp_substr(const string &t, int ps = 0, int pt = 0) const {
    int n = s.size(), m = t.size();
    for(; ps < n && pt < m; ps++, pt++){
      if(s[ps] < t[pt]) return -1;
      if(s[ps] > t[pt]) return 1;
    }
    return pt < m ? -1 : 0;
  }

  int lower_bound(const string &t) const {
    int low = -1, high = s.size();
    while(high-low > 1){
      int mid = (low + high) >> 1;
      (cmp_substr(t, sa[mid])<0 ? low : high) = mid;
    }
    return high;
  }

  int upper_bound(const string &t) const {
    int low = -1, high = s.size();
    while(high-low > 1){
      int mid = (low + high) >> 1;
      (cmp_substr(t, sa[mid])<=0 ? low : high) = mid;
    }
    return high;
  }

  bool contain(const string &t) const {
    int idx = lower_bound(t);
    return cmp_substr(t, idx) == 0;
  }

  pair<int, int> equal_range(const string &t) const {
    return {lower_bound(t), upper_bound(t)};
  }

  void dump() const {
    int n = s.size();
    for(int i = 0; i < n; i++){
      cout << i << ": " << s.substr(sa[i]) << '\n';
    }
  }
};
