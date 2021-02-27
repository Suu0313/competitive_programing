template <typename T=int>
struct runtimeBIT{
  LL n;
  umap<LL, T> node; //1-indexed
  runtimeBIT() : n(0) {}
  runtimeBIT(LL n_) : n(n_+1) {}

  void add(LL i, T x){
    if(i==0)return;
    for(LL idx = i; idx < n; idx += (idx & -idx)){
      node[idx] += x;
    }
  }
  T sum(LL i){ //[1,i]
    T s(0);
    for(LL idx = i; idx > 0; idx -= (idx & -idx)){
      s += node[idx];
    }
    return s;
  }
  T query(LL l, LL r){ //[l,r)
    return sum(r-1)-sum(l-1); 
  }

  LL lower_bound(T w){
    if(w <= 0) return 0;
    LL x = 0, r = 1;
    while(r < n) r *= 2;
    for(LL len = r; len>0; len>>=1){
      if(x+len<n && node[x+len] < w){
        w -= node[x+len];
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