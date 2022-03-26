template<typename T>
Formalpowerseries<T> p_subset_sum(const vector<int> &a, int s){
  vector<T> cnt(s + 1);
  for(auto&e : a) if(e <= s) ++cnt[e];

  vector<T> inv(s + 1, 1);
  int mod = T::get_mod();
  for(int i = 2; i <= s; ++i) inv[i] = -inv[mod % i] * (mod / i);

  Formalpowerseries<T> f(s + 1);
  for(int i = 1; i <= s; ++i){
    for(int k = 1; k*i <= s; ++k){
      f[i * k] +=  cnt[i] * inv[k] * (k&1 ? 1 : -1);
    }
  }

  return f.exp();
}
