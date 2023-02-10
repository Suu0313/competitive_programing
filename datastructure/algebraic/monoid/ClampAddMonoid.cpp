#pragma once

template<typename T>
struct ClampAddMonoid{

  ClampAddMonoid() = default;
  ClampAddMonoid(const ClampAddMonoid&) = default;
  ClampAddMonoid(ClampAddMonoid&&) = default;
  ClampAddMonoid &operator=(const ClampAddMonoid&) = default;
  ClampAddMonoid &operator=(ClampAddMonoid&&) = default;

  static constexpr T inf = numeric_limits<T>::max();

  T add = T(0), chmx = -inf, chmn = inf;

  ClampAddMonoid(const T &add, const T &chmx, const T &chmn): add(add), chmx(chmx), chmn(chmn) {}
  ClampAddMonoid(int t, const T &x){
    if(t == 0) add = x;
    if(t == 1) chmx = x;
    if(t == 2) chmn = x;
  }

  ClampAddMonoid &operator+=(const ClampAddMonoid &m){
    add += m.add;
    chmx = max(min(((chmx == -inf) ? chmx : chmx + m.add), m.chmn),  m.chmx);
    chmn = min(max(((chmn == inf) ? chmn : chmn + m.add), m.chmx),  m.chmn);
    return (*this);
  }

  ClampAddMonoid operator+(const ClampAddMonoid &m) const { return ClampAddMonoid(*this) += m; }

  T operator*(const T &x) const { return min(chmn, max(chmx, x + add)); }

  bool operator==(const ClampAddMonoid &m) const { return (add == m.add) && (chmx == m.chmx) && (chmn == m.chmn); }
  bool operator!=(const ClampAddMonoid &m) const { return !((*this) == m); }
};
