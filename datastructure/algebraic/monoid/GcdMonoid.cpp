#pragma once

template<typename T>
struct GcdMonoid{
  T x = 0;
  GcdMonoid() = default;
  GcdMonoid(const GcdMonoid&) = default;
  GcdMonoid(GcdMonoid&&) = default;

  GcdMonoid(const T &a, const T &b): a(a), b(b) {}

  GcdMonoid &operator=(const GcdMonoid&) = default;
  GcdMonoid &operator=(GcdMonoid&&) = default;

  GcdMonoid &operator+=(const GcdMonoid &m){
    if(m.x != 0) x = gcd(x, m.x);
    return (*this);
  }
  GcdMonoid operator+(const GcdMonoid &m) const {
    return GcdMonoid(*this) += m;
  }

  bool operator==(const GcdMonoid &m) const { return x == m.x; }
  bool operator!=(const GcdMonoid &m) const { return !((*this) == m); }
};
