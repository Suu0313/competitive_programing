template <typename T=int>
struct BIT{
  int n;
  vector<T> node; //1-indexed
  BIT() : n(0) {}
  BIT(int n_) : n(n_+1), node(n,0){}

  void add(int i, T x){
    if(i==0)return;
    for(int idx = i; idx < n; idx += (idx & -idx)){
      node.at(idx) += x;
    }
  }
  T sum(int i){ //[1,i]
    T s(0);
    for(int idx = i; idx > 0; idx -= (idx & -idx)){
      s += node.at(idx);
    }
    return s;
  }
  T query(int l, int r){ //[l,r)
    return sum(r-1)-sum(l-1); 
  }

  int lower_bound(T w){
    if(w <= 0) return 0;
    int x = 0, r = 1;
    while(r < n) r *= 2;
    for(int len = r; len>0; len>>=1){
      if(x+len<n && node.at(x+len) < w){
        w -= node.at(x+len);
        x += len;
      }
    }
    return x+1;
  }
  /*
  //invension number
  REP(i,N){
    ans += i - bit.sum(a.at(i));
    bit.add(a.at(i),1);
  }
  */
};
