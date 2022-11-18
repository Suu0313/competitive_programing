vector<int> subset_sum(const vector<int> &a, int x){
  int n = int(a.size()), s = 0;
  vector<int> b(a), d(n), idx(n);
  for(auto&e : b){
    if(e < 0) x -= e;
    e = abs(e);
    s += e;
  }
  if(x < 0 || s < x) return {};
  bool flip = (x*2 < s);
  if(flip) x = s - x;
  iota(begin(idx), end(idx), 0);
  sort(begin(idx), end(idx), [&](int i, int j){ return b[i] < b[j]; });
  for(int i = 0; i < n; ++i) d[i] = b[idx[i]];
  int m = d[n-1], m2 = m*2 + 1, si = 0;
  while(x > 0 && si < n) x -= d[si++];
  
  // dp[i][j][k] = siより右i個と左j個で和がkになるようにできるか
  // ただし |x-k| < m

  // i,kが同じならjはtrueの中で最も左のものを選ぶのが最適なので
  // dp[i][k] = min(j)

  vector<vector<int>> dp(n-si+1, vector<int>(m2, si+1));
  dp[0][m+x] = 0;

  for(int i = si; i <= n; ++i){
    /*
    まずiはそのままjの選択 今のjを使ってよりよくできるなら更新
    下から回して累積的に更新する
    //*/
    for(int k = 0; k < m; ++k) if(dp[i-si][k] != si+1){
      int r = min(si, (i>si) ? dp[i-1-si][k] : si);
      for(int j = dp[i-si][k]; j < r; ++j){
        dp[i-si][k+d[j]] = min(dp[i-si][k+d[j]], j+1);
      }
    }
    // early return
    if(dp[i-si][m] != si+1){
      vector<int> buf(n), res(n); fill(begin(buf), begin(buf)+si, 1);

      for(int k = m; i != si || k != m+x; ){
        int j = dp[i-si][k] - 1;
        if(j>=0 && k>=d[j] && dp[i-si][k-d[j]] <= j){
          buf[j] = 0; k -= d[j];
        }else{
          --i;
          if(dp[i-si][k] != j + 1){
            buf[i] = 1; k += d[i];
          }
        }
      }
      for(int t = 0; t < n; ++t){
        res[idx[t]] = buf[t] ^ flip ^ (a[idx[t]] < 0);
      }
      return res;
    }

    if(i < n){
      // iを使って進める (元々使ってことにしてあるのでそのまま)
      for(int k = 0; k < m2; ++k){
        dp[i+1-si][k] = min(dp[i+1-si][k], dp[i-si][k]);
      }
      // iを使わず進める (m未満からさらに減らすのは禁止)
      for(int k = m; k < m2; ++k){
        dp[i+1-si][k-d[i]] = min(dp[i+1-si][k-d[i]], dp[i-si][k]);
      }
    }
  }
  return {};
}

vector<int> pm_sum(const vector<int> &a, int x){
  // sum (-1)^t ai = x
  for(auto&e : a) x += e;
  if(x & 1) return {};
  return subset_sum(a, x >> 1);
}
