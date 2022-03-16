template<typename T>
vector<T> fast_walsh_hadamard_transform(vector<T> f, bool inv = false){
  int n = int(f.size());
  for(int i = 1; i < n; i <<= 1){
    for(int j = 0; j < n; ++j){
      if((i&j) == 0){
        T x = f[j], y = f[j|i];
        f[j] = x + y; f[j|i] = x - y;
      }
    }
  }
  if(inv){
    T in = T(1)/n;
    for(auto&x : f) x *= in;
  }
  return f;
}
