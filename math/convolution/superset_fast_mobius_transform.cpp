template<typename T, class Minus = minus<T>>
vector<T> superset_fast_mobius_transform(vector<T> f, const Minus &op = Minus{}){
  int n = int(f.size());
  for(int i = 1; i < n; i <<= 1){
    for(int j = 0; j < n; ++j){
      if((i&j) == 0) f[j] = op(f[j], f[j | i]);
    }
  }
  return f;
}
