template<typename T>
Formalpowerseries<T> partition_function_table_fps(int n){
  Formalpowerseries<T> f(n + 1); f[0] = 1;
  for(int k = 1, p = -1; n >= k*(3*k - 1)/2; ++k, p = -p) f[k*(3*k - 1)/2] = p;
  for(int l = 1, p = -1; n >= l*(3*l + 1)/2; ++l, p = -p) f[l*(3*l + 1)/2] = p;
  return f.inv();
}
