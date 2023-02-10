#pragma once

template<typename T>
struct LiChaoTree{
  struct Line{
    T a, b;
    Line(T a, T b) : a(a), b(b) {}
    inline T get(T x) const { return a*x + b; }
    inline bool over(const Line&l, const T &x) const {
      return get(x) < l.get(x);
    }
  };

  vector<T> xs;
  vector<Line> seg;
  size_t sz;

  LiChaoTree(const vector<T> &x, T inf): xs(x){
    sz = 1;
    while(sz < xs.size()) sz <<= 1;
    while(xs.size() < sz) xs.push_back(xs.back() + 1);
    seg.assign(2*sz, Line(0, inf));
  }

  void add_line(const T &a, const T &b){
    Line l(a, b);
    update(l, 1, 0, sz);
  }

  void add_segment(const T &a, const T &b, int l, int r){
    Line seg(a, b);
    int s = l + sz, t = r + sz, shift = 1;
    for(int s=l+sz, t=r+sz; s < t; s>>=1, t>>=1, shift<<=1){
      if(s & 1){
        update(seg, s++, l, l+shift);
        l += shift;
      }
      if(t & 1){
        update(seg, --t, r-shift, r);
        r -= shift;
      }
    }
  }

  T query(int k){
    const T x = xs[k];
    k += sz;
    T res = seg[k].get(x);
    while(k >>= 1) res = min(res, seg[k].get(x));

    return res;
  }

private:
  void update(Line x, int k, int l, int r){
    while(true){
      int m = (l + r) >> 1;
      bool lover = x.over(seg[k], xs[l]);
      bool mover = x.over(seg[k], xs[m]);
      if(mover) swap(seg[k], x);
      if(l+1 >= r) return;
      if(lover != mover) k = 2*k, r = m;
      else k = 2*k + 1, l = m;
    }
  }
};
