struct FastFactor{
  int n;
  VI min_factor;

  FastFactor(int n_):n(n_+1),min_factor(n_+1){
    iota(ALL(min_factor),0);
    for(int i = 2; i*i < n; ++i){
      if(min_factor.at(i) < i) continue;
      for(int j = i*i; j < n; j += i){
        if(min_factor.at(j) == j) min_factor.at(j) = i;
      }
    }
  }

  map<int,int> factor(int a){
    map<int,int> res;
    while(a > 1){
      res[min_factor.at(a)]++;
      a /= min_factor.at(a);
    }
    return res;
  }

  bool isPrime(int p){
    if(p<=1) return false;
    if(p>=n) return false;
    return p == min_factor.at(p);
  }

  VI prime_table(){
    VI res;
    REP(i,n){
      if(isPrime(i)) res.PB(i);
    }
    return res;
  }
};