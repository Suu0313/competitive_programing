#pragma once

template<typename T, typename U>
T partition(U sum, const vector<U> &d, const vector<U> &u, const vector<U> &m){

  auto com = [&](U n, U r) -> T {
    if(n < r) return T(0);
    if (n < 0 || r < 0) return T(0);
    r = min(r, n - r);
    T res = 1;
    for(int i = 0; i < r; i++){
      res *= n - i; res /= i + 1;
    }
    return res;
  };

  int n = u.size();
  auto msum = 0;
  for(auto &e : m) msum += e;

  auto dfs = [&](auto f, int ind, U sum) -> T {
    if(ind == n){
      return com(sum+msum-1, msum-1);
    }

    T res = 0;
    auto nu = u[ind] - d[ind];
    auto nsum = sum - d[ind] * m[ind];

    for(int i = 0; i <= m[ind]; i++){
      res += f(f, ind+1, nsum - (nu+1) * i) * com(m[ind], i) * (i%2==0 ? 1 : -1);
    }

    return res;
  };

  return dfs(dfs, 0, sum);
}
