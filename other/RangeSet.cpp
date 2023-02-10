#pragma once

template<typename T>
struct RangeSet{
  set<pair<T, T>> st;
  RangeSet(){
    st.emplace(numeric_limits<T>::min(), numeric_limits<T>::min());
    st.emplace(numeric_limits<T>::max(), numeric_limits<T>::max());
  }

  bool contains(T x) const {
    auto [l, r] = *prev(st.lower_bound(make_pair(x+1, x+1)));
    return l <= x && x <= r;
  }

  bool contains(T l, T r) const {
    auto [nl, nr] = *prev(st.lower_bound(make_pair(l+1, l+1)));
    return nl <= l && r <= nr;
  }

  bool insert(T x){
    auto nit = st.lower_bound(make_pair(x+1,x+1));
    auto it = prev(nit);
    auto [l, r] = *it;
    auto [nl, nr] = *nit;
    if(l<=x && x<=r) return false;
    if(r == x-1){
      if(x+1 == nl){
        st.erase(it);
        st.erase(nit);
        st.emplace(l,nr);
      }else{
        st.erase(it);
        st.emplace(l,x);
      }
    }else{
      if(x+1 == nl){
        st.erase(nit);
        st.emplace(x,nr);
      }else{
        st.emplace(x,x);
      }
    }
    return true;
  }

  bool insert(T l, T r){
    auto it = prev(st.lower_bound(make_pair(l+1, l+1)));
    auto [nl, nr] = *it;
    if(r <= nr) return false;
    if(nl <= l && l <= nr+1) l = nl;
    else it++;
    while(it->second <= r) it = st.erase(it);
    if(it->first <= r+1){ r = it->second; st.erase(it); }
    st.emplace(l, r);
    return true;
  }

  bool erase(T x){
    auto it = prev(st.lower_bound(make_pair(x+1, x+1)));
    auto [l, r] = *it;
    if(r < x) return false;
    st.erase(it);
    if(l != r){
      if(l == x) st.emplace(l+1, r);
      else if(r == x) st.emplace(l, r-1);
      else st.emplace(l, x-1), st.emplace(x+1, r); 
    }
    return true;
  }

  bool erase(T l, T r){
    auto it = prev(st.lower_bound(make_pair(l+1, l+1)));
    auto [nl, nr] = *it;
    // ToDo
    return true;
  }

  int mex(int x=0) const {
    auto [l, r] = *prev(st.lower_bound(make_pair(x+1, x+1)));
    if(l<=x && x<=r) return r+1;
    return x;
  }

  int cnt() const {
    return (int)st.size() - 2;
  }
};
