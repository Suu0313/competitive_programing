template<typename T, int p = T::get_mod()>
struct Lucas{
  Combination<T> bc;

  Lucas(): bc(p-1) {}

  T com(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    T res = 1;
    while(n){
      res *= bc.com(n%p, k%p);
      if(k == 0 || res == 0) return res;
      n /= p; k /= p;
    }
    return res;
  }
};
