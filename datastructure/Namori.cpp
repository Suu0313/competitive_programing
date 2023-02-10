#pragma once

template<typename F>
struct DirectedNamori{
  int s, d, len;
  vector<int> dist, log;
  F f;

  DirectedNamori(int n, int s, const F &f): s(s), d(0), len(0), dist(n, -1), log(0), f(f) {
    int pos = s;
    while(dist[pos] < 0){
      dist[pos] = d++;
      log.push_back(pos);
      pos = f(pos);
    }
    len = d - dist[pos];
  }

  int query(long long K) const {
    if(K < d-len){
      int pos = s;
      for(int i = 0; i < K; ++i) pos = f(pos);
      return pos;
    }else{
      K -= d-len;
      K %= len;
      return log[d-len + K];
    }
  }
};
