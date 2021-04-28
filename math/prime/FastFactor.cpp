struct FastFactor{
  int n;
  vector<int> min_factor;

  FastFactor(int n_):n(n_+1),min_factor(n_+1){
    iota(min_factor.begin(), min_factor.end(), 0);
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

  vector<int> prime_table(){
    vector<int> res;
    for(int i=0; i < n ; i++){
      if(isPrime(i)) res.push_back(i);
    }
    return res;
  }
};