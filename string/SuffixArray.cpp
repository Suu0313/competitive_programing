struct SuffixArray{
  vector<int> sa;
  const string s;

  SuffixArray(const string &s): sa(s.size()), s(s) {
    int n = s.size();
    if(n <= 1) return;
    if(n == 2){
      if(s[0] < s[1]) sa[1] = 1;
      else sa[0] = 1;
      return;
    }
    if(n < 10){ sa_native(); return; }
    if(n < 40){ sa_doubling(); return; }
    sa_is(s);
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
      cout << i << ": " << sa[i] << " " << s.substr(sa[i]) << endl;
    }
  }

private:
  void sa_native(){
    int n = s.size();
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j){
      if(i == j) return false;
      for(;i < n && j < n; i++, j++) if(s[i] != s[j]) return s[i] < s[j];
      return i == n;
    });
  }

  void sa_doubling(){
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int i, int j){ return s[i] < s[j]; });
    int n = s.size(), k = 0;
    vector<int> rank(n), tmp(n), nsa(n);

    tmp[sa[0]] = 0;
    for(int i = 0; i < n-1; i++) tmp[sa[i+1]] = tmp[sa[i]] + (s[sa[i]] < s[sa[i+1]]);
    swap(rank, tmp);

    auto nr = [&](int i){ return (i+k < n) ? rank[i+k] : -1; };

    auto cmp = [&](int i, int j){
      if(rank[i] != rank[j]) return rank[i] < rank[j];
      return nr(i) < nr(j);
    };
    
    auto binsort2 = [&](){
      vector<int> cnt(n+1);
      for(int i = 0; i < n; i++) cnt[nr(i)+1]++;
      for(int i = 0; i < n; i++) cnt[i+1] += cnt[i];
      for(int i = 0; i < n; i++) nsa[--cnt[nr(i)+1]] = i;
    };

    auto binsort = [&](){
      binsort2();
      vector<int> cnt(n);
      for(int i = 0; i < n; i++) cnt[rank[i]]++;
      for(int i = 0; i < n-1; i++) cnt[i+1] += cnt[i];
      for(int i = n-1; i >= 0; i--) sa[--cnt[rank[nsa[i]]]] = nsa[i];
    };

    for(k = 1; k < n; k <<= 1){
      binsort(); tmp[sa[0]] = 0;
      for(int i = 0; i < n-1; i++) tmp[sa[i+1]] = tmp[sa[i]] + cmp(sa[i], sa[i+1]);
      swap(rank, tmp);
    }
  }
  
  void sa_is(const string &s){
    int n = s.size();
    vector<int> v(n);
    for(int i = 0; i < n; i++) v[i] = s[i];
    auto res = sa_is(v, 256);
    for(int i = 0; i < n; i++) sa[i] = res[i+1];
  }

  vector<int> sa_is(const vector<int> &v, int num){
    int n = v.size();
    if(n == 1) return {0};
    if(n == 2){ if(s[0] < s[1]){ return {0,1};} return {1,0}; }

    vector<bool> ls(n + 1, false); ls[n] = true;
    for(int i = n-2; i >= 0; i--){
      if(v[i] == v[i+1]) ls[i] = ls[i+1];
      else ls[i] = v[i] < v[i+1];
    }

    auto islms = [&](int i){ return i>0 && (!ls[i-1] && ls[i]); };

    auto chk = [&](int i){ if(i >= n){ return 0; } return v[i] + 1; };

    vector<int> nsa(n + 1), lms, rev(n+1), sorted_lms;
    for(int i = 0; i <= n; i++) if(islms(i)) lms.push_back(i);
    int m = lms.size(); sorted_lms.reserve(m);
    for(int i = 0; i < m; i++) rev[lms[i]] = i;

    auto induced_sort = [&](){
      vector<int> bin(num + 2), cnt(num + 1);
      for(int i = 0; i <= n; i++) bin[chk(i)+1]++;
      for(int i = 0; i <= num; i++) bin[i+1] += bin[i];

      for(int i = m-1; i >= 0; i--){
        int j = chk(lms[i]); nsa[bin[j+1] - (++cnt[j])] = lms[i];
      }

      fill(cnt.begin(), cnt.end(), 0);
      for(auto&&i : nsa) if(i > 0 && !ls[i-1]) nsa[bin[chk(i-1)] + (cnt[chk(i-1)]++)] = i - 1;
      
      fill(cnt.begin(), cnt.end(), 0);
      for(int i = n; i >= 0; i--) if(nsa[i] > 0 && ls[nsa[i]-1]) {
        int j = chk(nsa[i] - 1); nsa[bin[j+1] - (++cnt[j])] = nsa[i] - 1;
      }
    };

    induced_sort();
    for(int i = 0; i <= n; i++) if(islms(nsa[i])) sorted_lms.push_back(nsa[i]);

    vector<int> rank(m); int rmax = 0;

    for(int i = 0; i < m-1; i++){
      int l = sorted_lms[i], r = sorted_lms[i+1];
      auto cmp = [&](){
        for(int pl=l, pr=r; pl<=n && pr<=n; pl++, pr++){
          if(chk(pl) != chk(pr)) return true;
          if(pl == l) continue;
          if(islms(pr)) return false;
          if(islms(pl) && !islms(pl)) return true;
        }
        assert(false); return true;
      };
      rmax += cmp();
      rank[rev[r]] = rmax;
    }

    if(rmax+1 == (int)rank.size()){
      vector<int> tmp(m); swap(tmp, lms);
      for(int i = 0; i < m; i++) lms[rank[i]] = tmp[i];
    }else{
      auto rec_sa = sa_is(rank, rmax+1);
      vector<int> tmp(m);
      for(int i = 0; i < m; i++) tmp[i] = lms[rec_sa[i+1]];
      swap(tmp, lms);
    }

    fill(nsa.begin(), nsa.end(), 0);
    induced_sort();
    
    return nsa;
  }
};
