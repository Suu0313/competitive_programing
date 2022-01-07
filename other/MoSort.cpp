vector<int> MoSort(int n, int q, const vector<int> &l, const vector<int> &r){
  vector<int> idx(q); iota(begin(idx), end(idx), 0);
  int d = max(1.0, n/sqrt(q));
  sort(begin(idx), end(idx), [&](int i, int j){
    if(l[i]/d != l[j]/d) return l[i] < l[j];
    return r[i] < r[j];
  });
  return idx;
}
