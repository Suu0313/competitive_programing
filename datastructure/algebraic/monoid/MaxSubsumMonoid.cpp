#pragma once

template<typename T>
struct MaxSubsumMonoid{
  T pre = 0, suf = 0, mx = 0, whole = 0;
  int len = 0;

  MaxSubsumMonoid() = default;
  MaxSubsumMonoid(const MaxSubsumMonoid&) = default;
  MaxSubsumMonoid(MaxSubsumMonoid&&) = default;

  MaxSubsumMonoid(const T &x): pre(x), suf(x), mx(x), whole(x), len(1) {}
  MaxSubsumMonoid(const T &x, int n):
    pre(x * n), suf(x * n), mx(x * n), whole(x * n), len(n) {
    if(x < 0) pre = suf = mx = x;
  }

  MaxSubsumMonoid &operator=(const MaxSubsumMonoid&) = default;
  MaxSubsumMonoid &operator=(MaxSubsumMonoid&&) = default;

  MaxSubsumMonoid &operator+=(const MaxSubsumMonoid &m){
    if(m.len == 0) return (*this);
    if(len == 0) return (*this) = m;
    mx = max({mx, suf + m.pre, m.mx});
    pre = max(pre, whole + m.pre);
    suf = max(suf + m.whole, m.suf);
    whole += m.whole;
    len += m.len;
    return (*this);
  }
  MaxSubsumMonoid operator+(const MaxSubsumMonoid &m) const {
    return MaxSubsumMonoid(*this) += m;
  }

  bool operator==(const MaxSubsumMonoid &m) const {
    if(len == 0 && m.len == 0) return true;
    return (
      len == m.len && pre == m.pre && suf == m.suf
      && mx == m.mx && whole == m.whole
    );
  }
  bool operator!=(const MaxSubsumMonoid &m) const { return !((*this) == m); }
};
