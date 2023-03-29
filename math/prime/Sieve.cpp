#pragma once

struct Sieve{
  int n;
  vector<int> min_factor;

  Sieve(int n_):n(n_+1), min_factor(n/2){
    int sn = sqrt(n)+1, ni = n/2, sni = sn/2;
    for(int i = 0; i < ni; ++i) min_factor[i] = 2*i + 1;

    for(int i = 1; i < sni; ++i){
      if(min_factor[i] < 2*i+1) continue;
      for(int j = 2*i*(i+1); j < ni; j += 2*i+1){
        if(min_factor[j] > 2*i + 1) min_factor[j] = 2*i + 1;
      }
    }
  }

  map<int,int> factor(int a) const {
    map<int,int> res;
    while(~a&1 && a > 1){ ++res[2]; a >>= 1; }
    while(a > 1){
      res[min_factor[a>>1]]++;
      a /= min_factor[a>>1];
    }
    return res;
  }

  vector<int> vfactor(int a) const {
    vector<int> ps;
    while(~a&1 && a > 1){ ps.push_back(2); a >>= 1; }
    while(a > 1){
      ps.push_back(min_factor[a>>1]);
      a /= min_factor[a>>1];
    }
    return ps;
  }

  bool is_prime(int p) const {
    if(p<=1) return false;
    if(p==2) return true;
    return min_factor[p>>1] == p;
  }

  vector<int> prime_table() const {
    vector<int> res;
    for(int i=2; i < n ; i++){
      if(is_prime(i)) res.push_back(i);
    }
    return res;
  }

  vector<int> divisors(int a) const {
    if(a <= 0) return {};
    vector<int> res(1, 1);
    for(const auto[p, c] : factor(a)){
      int m = int(res.size());
      res.resize(m * (c + 1));
      for(int i = 0; i < m * c; ++i){
        res[i + m] = res[i] * p;
      }
    }
    return res;
  }

  int cnt_divisors(int a) const {
    if(a <= 0) return 0;
    int res = 1;
    for(const auto[p, c] : factor(a)) res *= c + 1;
    return res;
  }
};
