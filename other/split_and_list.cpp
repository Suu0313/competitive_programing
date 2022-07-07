template<typename T, class Operator, class Compair>
pair<vector<T>, vector<T>> split_and_list(const vector<T> &a, const T &e, const Operator &op, const Compair &cmp){
  vector<T> b(1, e), c(1, e);

  for(auto&&x : a){
    int n = int(b.size());
    b.reserve(n * 2);
    for(int i = 0; i < n; ++i) b.push_back(op(b[i], x));
    inplace_merge(begin(b), begin(b) + n, end(b), cmp);
    swap(b, c);
  }

  return {b, c};
}
