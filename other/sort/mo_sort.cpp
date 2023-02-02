vector<int> mo_sort(int n, int q, const vector<int> &l, const vector<int> &r){
  vector<int> idx(q); iota(begin(idx), end(idx), 0);
  int d = max<int>(1, n/max<double>(1.0, sqrt(q*2.0/3.0)));
  sort(begin(idx), end(idx), [&](int i, int j){
    if(l[i]/d != l[j]/d) return l[i] < l[j];
    else return ((l[i]/d)%2 ? (r[i] < r[j]) : (r[i] > r[j]));
  });
  return idx;
}
