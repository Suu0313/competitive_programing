/**
 * [0 <= i < h) find f(i) O(h + w)
 * 
 * @tparam F (int, int, int) -> bool
 * @param h 
 * @param w 
 * @param f (i, pj, nj) -> nj is better than pj
 * @return vector<int> f[i] is best j
 * @todo monotone_minima より遅いのを何とかしたい
 */
template<typename F> 
vector<int> totally_monotone_minima(int h, int w, const F &f){
  auto rec = [&](auto self, const vector<int> &hidx, const vector<int> &widx) -> vector<int> {

    int n = int(hidx.size());
    if(n == 0) return {};
    vector<int> nwidx; nwidx.reserve(n);
    for(int j : widx){
      while(!nwidx.empty() && f(hidx[nwidx.size() - 1], nwidx.back(), j)) nwidx.pop_back();
      if(int(nwidx.size()) < n) nwidx.push_back(j);
    }

    vector<int> ridx; ridx.reserve(n/2);
    for(int i = 1; i < n; i += 2) ridx.push_back(hidx[i]);
    auto rans = self(self, ridx, nwidx);

    vector<int> ans(n);
    for(int i = 1, j = 0; i < n; i += 2, ++j) ans[i] = rans[j];

    for(int i = 0, j = 0; i < n; i += 2){
      ans[i] = nwidx[j];
      for(int r = (i+1 == n ? nwidx.back() : ans[i + 1]); nwidx[j] != r; ){
        ++j;
        if(f(hidx[i], ans[i], nwidx[j])) ans[i] = nwidx[j];
      }
    }
    return ans;
  };
  vector<int> hidx(h); iota(hidx.begin(), hidx.end(), 0);
  vector<int> widx(w); iota(widx.begin(), widx.end(), 0);
  return rec(rec, hidx, widx);
}
