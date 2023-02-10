#pragma once

#include ".\\LongestCommonPrefixArray.cpp"

template<typename Container>
tuple<int,int,int> longest_common_substr_lcp(const Container &s, const Container &t){
  int n = s.size(), m = t.size();
  vector<int> u(n + 1 + m); int lower = s[0];
  for(int i = 0; i < n; i++){ u[i] = s[i]; lower = min(lower, u[i]); }
  for(int i = 0; i < m; i++){ u[n+1+i] = t[i]; lower = min(lower, u[n+1+i]); }
  u[n] = lower - 1;
  LongestCommonPrefixArray<vector<int>> lcp(u, false);
  int res = -1, l = -1, r = -1;
  for(int i = 0; i < n + 1 + m; i++){
    if(i == n) continue;
    if(int j = lcp.sa[lcp.rank[i] - 1]; (i < n) != (j < n)){
      if(int cur = lcp.get(i); res < cur){
        res = cur;
        if(i < n) l = i, r = j - n - 1;
        else l = j, r = i - n - 1;
      }
    }
  }
  return {res, l, r};
}
