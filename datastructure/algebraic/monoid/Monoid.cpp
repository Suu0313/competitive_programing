#pragma once

template<typename T>
struct Monoid{

  Monoid() = default;
  Monoid(const Monoid&) = default;
  Monoid(Monoid&&) = default;
  Monoid &operator=(const Monoid&) = default;
  Monoid &operator=(Monoid&&) = default;

  T x = T{}; // id
  Monoid(const T &x): x(x) {}

  Monoid &operator+=(const Monoid &m){
    x += m.x;
    return (*this);
  }

  Monoid operator+(const Monoid &m) const { return Monoid(*this) += m; }

  bool operator==(const Monoid &m) const { return x == m.x; }
  bool operator!=(const Monoid &m) const { return !((*this) == m); }

};
