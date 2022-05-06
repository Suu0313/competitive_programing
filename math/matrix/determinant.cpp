template<typename T>
T determinant(Matrix<T> a){
  assert(a.height() == a.width());
  int n = a.height();
  T res = 1;
  for(int i = 0; i < n; ++i){
    int pivot = -1;
    for(int j = i; j < n; ++j){
      if(a[j][i] != 0){
        pivot = j; break;
      }
    }
    if(pivot == -1) return 0;
    if(i != pivot){
      res *= -1; swap(a[i], a[pivot]);
    }
    res *= a[i][i];
    T inv = T(1)/a[i][i];
    for(int k = 0; k < n; ++k) a[i][k] *= inv;
    for(int j = i+1; j < n; ++j){
      T fac = a[j][i];
      for(int k = 0; k < n; ++k){
        a[j][k] -= a[i][k] * fac;
      }
    }
  }
  return res;
}
