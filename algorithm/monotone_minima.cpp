/**
 * [0 <= i < h) find f(i) O(h + wlogh)
 * 
 * @tparam F (int, int, int) -> bool
 * @param h 
 * @param w 
 * @param f (i, pj, nj) -> nj is better than pj
 * @return vector<int> f[i] is best j
 * @todo 非再帰にできないんですかこれ
 */
template<typename F> 
vector<int> monotone_minima(int h, int w, const F &f){
  auto rec = [&](auto self, const vector<int> &idx) -> vector<int> {
    int n = int(idx.size());
    if(n == 0) return {};
    vector<int> ridx; ridx.reserve(n/2);
    for(int i = 1; i < n; i += 2) ridx.push_back(idx[i]);
    auto rans = self(self, ridx);
    vector<int> ans(n);
    for(int i = 1, j = 0; i < n; i += 2, ++j) ans[i] = rans[j];
    for(int i = 0, j = 0; i < n; i += 2){
      ans[i] = j;
      for(int r = (i+1 == n ? w - 1 : ans[i + 1]); j != r; ){
        ++j;
        if(f(idx[i], ans[i], j)) ans[i] = j;
      }
    }
    return ans;
  };
  vector<int> idx(h); iota(idx.begin(), idx.end(), 0);
  return rec(rec, idx);
}
