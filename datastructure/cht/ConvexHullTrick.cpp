#pragma once

template <typename T>
struct ConvexHullTrick{
  struct Line{
    T a, b;
    Line(T a, T b): a(a), b(b){}
  };
  deque<Line> Lines;
  const bool isMin;

  ConvexHullTrick(bool isMin = true): isMin(isMin) {}
  
  bool empty() const { return Lines.empty(); }
  void clear() { Lines.clear(); }

  T get_y(const Line &l, const T &x) const {
    return l.a * x + l.b;
  }

  bool needless(const Line& l, const Line& m, const Line& r){
    return (m.a-l.a)*(r.b-m.b) >= (m.b-l.b)*(r.a-m.a);
  }
  bool comp(const Line &l, const Line &r, T x){
    return get_y(l, x) >= get_y(r, x);
  }

  void add(T a, T b){
    if(!isMin) a*=-1, b*=-1;
    Line l(a,b);
    int n = Lines.size();
    if(n == 0){
      Lines.emplace_back(l);
      return;
    }
    auto[na, nb] = Lines.front();
    if(n == 1){
      if(na == a){
        if(nb > b) Lines.front() = l;
      }else if(na <= a){
        Lines.emplace_front(l);
      }else{
        Lines.emplace_back(l);
      }
      return;
    }
    if(na <= a){
      while(n>=2 && needless(Lines.front(),Lines[1],l)){
        Lines.pop_front(); n--;
      }
      Lines.emplace_front(l);
    }else{
      while(n>=2 && needless(Lines[n-2],Lines[n-1],l)){
        Lines.pop_back(); n--;
      }
      Lines.emplace_back(l);
    }
  }

  T query(T x){
    assert(!empty());
    int l = -1, r = Lines.size()-1;
    while(r-l > 1){
      int m = (l+r) >> 1;
      if(comp(Lines[m], Lines[m+1], x)) l = m;
      else r = m;
    }
    if(isMin) return get_y(Lines[r], x);
    return -get_y(Lines[r], x);
  }

  T query_inc(T x){
    assert(!empty());
    while(int(Lines.size())>=2 && comp(Lines.front(),Lines[1],x)) Lines.pop_front();
    if(isMin) return get_y(Lines.front(), x);
    return -get_y(Lines.front(), x);
  }

  T query_dec(T x){
    assert(!empty());
    while(int(Lines.size())>=2 && comp(Lines.back(),Lines[int(Lines.size())-2],x)) Lines.pop_back();
    if(isMin) return get_y(Lines.back(), x);
    return -get_y(Lines.back(), x);
  }
};
