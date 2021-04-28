template <typename T>
struct RAQBIT{
  int n;
  vector<vector<T>> node; //1-indexed
  RAQBIT() : n(0) {}
  RAQBIT(int n_) : n(n_+1), node(2,vector<T>(n,0)){}

  void add_sub(int p, int i, T x){
    if(i==0)return;
    for(int idx = i; idx < n; idx += (idx & -idx)){
      node.at(p).at(idx) += x;
    }
  }

  void add(int l, int r, T x){ // [l,r)
    add_sub(0, l, -x*(l-1));
    add_sub(0, r, x*(r-1));
    add_sub(1, l, x);
    add_sub(1, r, -x);
  }

  T sum_sub(int p, int i){
    T s(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      s += node.at(p).at(idx);
    }
    return s;
  }

  T sum(int i){ //[1,i]
    return sum_sub(0, i) + sum_sub(1, i)*i;
  }

  T query(int l, int r){ //[l,r)
    return sum(r-1)-sum(l-1); 
  }

  /* wakarann
  int lower_bound(T w){
    if(w <= 0) return 0;
    int x = 0, r = 1;
    while(r < n) r *= 2;
    for(int len = r; len>0; len>>=1){
      if(x+len<n && node.at(x+len) < w){
        //zettaichigau
        w -= node.at(0).at(x+len)+node.at(1).at(x+len);
        x += len;
      }
    }
    return x+1;
  }
  //*/
  
  /*
  //invension number
  REP(i,N){
    ans += i - bit.sum(a.at(i));
    bit.add(a.at(i),1);
  }
  */
};
