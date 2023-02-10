#pragma once

template<class Container>
vector<int> palindromic_length(Container s){
  int n = int(s.size());
  vector<int> pl(n+1), gpl(n+1);
  queue<tuple<int,int,int>> g, g2, g3;

  for(int j = 0; j < n; ++j){

    while(!g.empty()){
      auto[i, d, k] = g.front(); g.pop();
      if(i >= 1 && s[i-1] == s[j]) g2.emplace(i-1, d, k);
    }

    int r = -j - 1;
    while(!g2.empty()){
      auto[i, d, k] = g2.front(); g2.pop();
      if(i-r != d){
        g3.emplace(i, i-r, 1);
        if(k > 1) g3.emplace(i+d, d, k-1);
      }else{
        g3.emplace(i, d, k);
      }
      r = i + (k-1) * d;
    }

    if(j > 0 && s[j-1] == s[j]){
      g3.emplace(j-1, j-1-r, 1);
      r = j - 1;
    }
    g3.emplace(j, j-r, 1);

    auto[ni, nd, nk] = g3.front(); g3.pop();
    while(!g3.empty()){
      auto[i, d, k] = g3.front(); g3.pop();
      if(nd == d){
        nk += k;
      }else{
        g.emplace(ni, nd, nk);
        tie(ni, nd, nk) = make_tuple(i, d, k);
      }
    }
    g.emplace(ni, nd, nk);
    pl[j+1] = j + 1;
    g2 = g;
    while(!g.empty()){
      auto[i, d, k] = g.front(); g.pop();
      r = i + (k - 1) * d;
      int m = pl[r] + 1;
      if(k > 1) m = min(m, gpl[i - d + 1]);
      if(d <= i + 1) gpl[i - d + 1] = m;
      pl[j+1] = min(pl[j+1], m);
    }
    swap(g, g2);
  }
  return pl;
}
