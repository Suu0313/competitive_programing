template<typename T, class Minus = minus<T>>
vector<T> subset_fast_moebius_transform(vector<T> f, const Minus &op = Minus{}){
  int n = int(f.size());
  for(int i = 1; i < n; i <<= 1){
    for(int j = 0; j < n; ++j){
      if((i&j) == 0) f[j | i] = op(f[j | i], f[j]);
    }
  }
  return f;
}
