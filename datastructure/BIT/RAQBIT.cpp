template <typename T>
struct RAQBIT{
  int n;
  vector<vector<T>> node;
  RAQBIT() : n(0) {}
  RAQBIT(int n_) : n(n_+1), node(2,vector<T>(n,0)){}

  void add(int l, int r, T x){ // [l,r)
    add_sub(0, l, -x*l);
    add_sub(0, r, x*r);
    add_sub(1, l, x);
    add_sub(1, r, -x);
  }

  T sum(int i) const { //[0,i)
    return sum_sub(0, i) + sum_sub(1, i)*i;
  }

  T query(int l, int r) const { //[l,r)
    return sum(r)-sum(l); 
  }

  T operator[](int i) const { return query(i,i+1); }

private:
  void add_sub(int p, int i, T x){
    for(int idx = i+1; idx < n; idx += (idx & -idx)){
      node.at(p).at(idx) += x;
    }
  }

  T sum_sub(int p, int i) const {
    T s(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      s += node.at(p).at(idx);
    }
    return s;
  }
};
