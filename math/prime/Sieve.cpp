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

  bool isPrime(int p) const {
    if(p<=1) return false;
    if(p==2) return true;
    return min_factor[p>>1] == p;
  }

  vector<int> prime_table() const {
    vector<int> res;
    for(int i=2; i < n ; i++){
      if(isPrime(i)) res.push_back(i);
    }
    return res;
  }

  vector<int> divisors(int a) const {
    vector<pair<int, int>> ps;

    for(auto&&p : vfactor(a)){
      if(!ps.empty() && ps.back().first == p) ++ps.back().second;
      else ps.emplace_back(p, 1);
    }
    int m = int(ps.size());
    stack<pair<int, int>> st; st.emplace(0, 1);
    vector<int> res;

    while(!st.empty()){
      auto[i, s] = st.top(); st.pop();
      if(i == m){
        res.push_back(s);
        continue;
      }
      auto[p, c] = ps[i];
      for(int j = 0; j <= c; j++, s *= p) st.emplace(i+1, s);
    }
    return res;
  }
};
