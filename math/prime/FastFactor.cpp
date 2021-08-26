struct FastFactor{
  int n;
  vector<int> min_factor;

  FastFactor(int n_):n(n_+1), min_factor(n/2){
    int sn = sqrt(n)+1, ni = n/2, sni = sn/2;
    for(int i = 0; i < ni; ++i) min_factor[i] = 2*i + 1;

    for(int i = 1; i < sni; ++i){
      if(min_factor[i] < 2*i+1) continue;
      for(int j = 2*i*(i+1); j < ni; j += 2*i+1){
        min_factor[j] = 2*i + 1;
      }
    }
  }

  map<int,int> factor(int a){
    map<int,int> res;
    while(~a&1 && a > 1){ ++res[2]; a >>= 1; }
    while(a > 1){
      res[min_factor[a>>1]]++;
      a /= min_factor[a>>1];
    }
    return res;
  }

  bool isPrime(int p){
    if(p<=1) return false;
    if(p==2) return true;
    return min_factor[p>>1] == p;
  }

  vector<int> prime_table(){
    vector<int> res;
    for(int i=2; i < n ; i++){
      if(isPrime(i)) res.push_back(i);
    }
    return res;
  }
};
