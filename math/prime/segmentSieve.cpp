#pragma once

struct segmentSieve{
  int64_t l, r, m;
  vector<int> small;
  vector<vector<int64_t>> large;
  vector<int64_t> aux;

  segmentSieve(int64_t l, int64_t r): l(l), r(r), m(sqrt(r)+1), small(m), large(r-l), aux(r-l, 1) {
    iota(small.begin(), small.end(), 0);
    
    for(int64_t i = 2; i*i < r; ++i){
      if(small[i] < i) continue;
      for(int64_t j = i*i; j < m; j += i){
        if(small[j] == j) small[j] = i;
      }
      for(int64_t j = (l+i-1)/i*i; j < r; j += i){
        int64_t x = j;
        while(x%i == 0){
          if(aux[j-l] > m) break;

          large[j-l].push_back(i);
          aux[j-l] *= i;
          x /= i;
        }
      }
    }
  }

  vector<int64_t> factor(int64_t n){
    auto res = large[n - l];
    n /= aux[n-l];

    if(n >= m) res.push_back(n);
    else{
      while(n > 1){
        res.push_back(small[n]);
        n /= small[n];
      }
    }
    return res;
  }
};
