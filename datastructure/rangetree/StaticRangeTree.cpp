#pragma once


template<typename Tx, typename Ty, typename T = int>
struct StaticRangeTree{
  using OP = function<T(T, T)>;
  int n;
  vector<Tx> xs;
  vector<vector<Ty>> ys;
  vector<vector<T>> sum;
  const OP op, inv;
  const T id;

  StaticRangeTree(const OP &op = plus{}, const OP &inv = minus{}, const T &id = 0)
  : n(1), op(op), inv(inv), id(id) {}

  void build(vector<tuple<Tx,Ty,T>> ps){
    int n0 = int(ps.size());
    sort(begin(ps), end(ps));
    xs.resize(n0);
    for(int i = 0; i < n0; ++i) xs[i] = get<0>(ps[i]);
    xs.erase(unique(begin(xs), end(xs)), end(xs));
    n0 = int(xs.size());
    for(n = 1; n < n0; ) n <<= 1;
    xs.resize(n, numeric_limits<Tx>::max());
    ys.resize(n * 2);
    sum.resize(n * 2, vector<T>(1, id));
    int cur = 0;
    for(auto&&[x,y,v] : ps){
      if(xs[cur] != x) ++cur;
      ys[cur + n].push_back(y);
      sum[cur + n].push_back(v);
    }

    for(int i = n-1; i > 0; --i){
      for(int l = 0, r = 0; l < int(ys[i*2].size()) || r < int(ys[i*2+1].size());){
        if(l == int(ys[i*2].size())){
          while(r < int(ys[i*2+1].size())){
            ys[i].push_back(ys[i*2+1][r]);
            sum[i].push_back(sum[i*2+1][r+1]);
            ++r;
          }
          break;
        }

        if(r == int(ys[i*2+1].size())){
          while(l < int(ys[i*2].size())){
            ys[i].push_back(ys[i*2][l]);
            sum[i].push_back(sum[i*2][l+1]);
            ++l;
          }
          break;
        }

        if(ys[i*2][l] < ys[i*2+1][r]){
          ys[i].push_back(ys[i*2][l]);
          sum[i].push_back(sum[i*2][l+1]);
          ++l;
        }else{
          ys[i].push_back(ys[i*2+1][r]);
          sum[i].push_back(sum[i*2+1][r+1]);
          ++r;
        }
      }
    }

    for(int i = 1; i < n*2; ++i){
      int m = int(sum[i].size());
      for(int j = 0; j < m-1; ++j) sum[i][j+1] = op(sum[i][j], sum[i][j+1]);
    }
  }

  void build(const vector<pair<Tx,Ty>> &ps){
    vector<tuple<Tx,Ty,int>> psv;
    psv.reserve(ps.size());
    for(auto&&[x,y] : ps) psv.emplace_back(x, y, 1);
    build(psv);
  }

  T query(Tx lx, Tx rx, Ty dy, Ty uy) const {
    int l = lower_bound(begin(xs), end(xs), lx) - begin(xs);
    int r = lower_bound(begin(xs), end(xs), rx) - begin(xs);
    T lres = id, rres = id;
    for(l+=n, r+=n; l < r; l>>=1, r>>=1){
      if(l & 1){
        int u = lower_bound(begin(ys[l]), end(ys[l]), uy) - begin(ys[l]);
        int d = lower_bound(begin(ys[l]), end(ys[l]), dy) - begin(ys[l]);
        lres = op(lres, inv(sum[l][u], sum[l][d]));
        ++l;
      }
      if(r & 1){
        --r;
        int u = lower_bound(begin(ys[r]), end(ys[r]), uy) - begin(ys[r]);
        int d = lower_bound(begin(ys[r]), end(ys[r]), dy) - begin(ys[r]);
        rres = op(inv(sum[r][u], sum[r][d]), rres);
      }
    }
    return op(lres, rres);
  }
};
