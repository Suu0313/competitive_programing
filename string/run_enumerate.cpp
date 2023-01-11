template<typename Container> // (p, l, r)
vector<tuple<int, int, int>> run_enumerate(const Container &s){
  auto solve_impl = [](Container l, Container r){
    int n = int(l.size()), m = int(r.size());
    r.reserve(n + m*2);
    for(int i = 0; i < n; i++) r.push_back(l[i]);
    for(int i = 0; i < m; i++) r.push_back(r[i]);
    reverse(begin(l), end(l));
    vector<int> lz = z_algorithm(l), rz = z_algorithm(r);
    vector<tuple<int, int, int>> res;

    for(int p = 1; p <= n; ++p){
      int a = (p == n ? p : lz[p] + p);
      int b = min(rz[n + m - p], m);
      if(a + b < 2 * p) continue;
      res.emplace_back(p, a, b);
    }

    return res;
  };

  int n = int(s.size());

  stack<pair<int, int>> st; st.emplace(0, n);
  vector<vector<pair<int, int>>> ps(n + 1);

  while(!st.empty()){
    auto[l, r] = st.top(); st.pop();
    if(l+1 >= r) continue;
    int m = (l + r)/2;
    st.emplace(l, m); st.emplace(m, r);

    Container ls(begin(s) + l, begin(s) + m), rs(begin(s) + m, begin(s) + r);

    for(auto&&[p, a, b] : solve_impl(ls, rs)) ps[p].emplace_back(m - a, m + b);
    reverse(begin(ls), end(ls)); reverse(begin(rs), end(rs));
    for(auto&&[p, a, b] : solve_impl(rs, ls)) ps[p].emplace_back(m - b, m + a);
  }

  vector<tuple<int, int, int>> res;
  set<pair<int, int>> seen;
  for(int p = 1; p <= n; ++p){
    sort(begin(ps[p]), end(ps[p]),
      [](auto &x, auto &y){ return make_pair(x.first, -x.second) < make_pair(y.first, -y.second); });

    int nr = -1;
    for(auto&&[l, r] : ps[p]){
      if(nr < r){
        nr = r;
        if(seen.count({l, r})) continue;
        seen.emplace(l, r);
        res.emplace_back(p, l, r);
      }
    }
  }
  return res;
}
