template<typename T>
vector<T> Concat(const vector<T> &a, const vector<T> &b){
  vector<T> res = a;
  res.reserve(a.size() + b.size());
  res.insert(end(res), begin(b), end(b));
  return res;
}
