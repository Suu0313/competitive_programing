template<typename T, typename T2>
vector<T> convert_base_10tob(T x, T2 b) {
  vector<T> ret;
  T t = 1, k = abs(b);
  while(x) {
    ret.emplace_back((x * t) % k);
    if(ret.back() < 0) ret.back() += k;
    x -= ret.back() * t;
    x /= k; t *= b / k;
  }
  if(ret.empty()) ret.emplace_back(0);
  reverse(begin(ret), end(ret));
  return ret;
}

template<typename T, typename T2>
T convert_base_bto10(const vector<T> &a, T2 b) {
  T ret = 0;
  for(auto&e : a) (ret *= b) += e;
  return ret;
}

template<typename T = int>
vector<T> stov(const string &s, char c = '0'){
  int n = int(s.size());
  vector<T> res(n);
  for(int i = 0; i < n; ++i) res[i] = s[i] - c;
  return res;
}
