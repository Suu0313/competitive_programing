#pragma once

template<typename T, size_t bwidth = 60>
struct Doubling{
  using OP = function<T(T,T)>;

  vector<vector<int>> npos;
  vector<vector<T>> val;
  const OP op;
  bool is_built;

  Doubling(size_t n, const OP &op)
    : npos(bwidth, vector<int>(n, -1)), val(bwidth, vector<T>(n)), op(op), is_built(false) {}

  void set_next(size_t i, int p){ npos[0][i] = p; }
  void set_value(size_t i, const T &x){ val[0][i] = x; }
  void set_next(const vector<int> &p){ npos[0] = p; }
  void set_value(const vector<T> &v){ val[0] = v; }

  void build(){
    is_built = true;
    size_t n = npos[0].size();
    for(size_t d = 0; d+1 < bwidth; d++){
      for(size_t i = 0; i < n; i++){
        int p = npos[d][i]; if(p == -1) continue;
        npos[d+1][i] = npos[d][p];
        val[d+1][i] = op(val[d][i], val[d][p]);
      }
    }
  }

  pair<int, T> query(int s, uint64_t k, const T &id = T()) {
    if(!is_built) build();
    T res = id;
    for(int d = bwidth-1; d >= 0; d--){
      if((k>>d) & 1){
        res = op(res, val[d][s]);
        s = npos[d][s];
      }
    }
    return {s, res};
  }
};


template<size_t bwidth = 60>
struct Doubling{

  vector<vector<int>> npos;
  bool is_built;

  Doubling(size_t n): npos(bwidth, vector<int>(n, -1)), is_built(false) {}

  void set_next(size_t i, int p){ npos[0][i] = p; }
  void set_next(const vector<int> &p){ npos[0] = p; }

  void build(){
    is_built = true;
    size_t n = npos[0].size();
    for(size_t d = 0; d+1 < bwidth; d++){
      for(size_t i = 0; i < n; i++){
        int p = npos[d][i]; if(p == -1) continue;
        npos[d+1][i] = npos[d][p];
      }
    }
  }

  int query(int s, uint64_t k) {
    if(!is_built) build();
    for(int d = bwidth-1; d >= 0; d--){
      if((k>>d) & 1) s = npos[d][s];
    }
    return s;
  }
};