#pragma once

template<typename T>
struct ArithmeticUpdateMonoid{
  bool id = 1;
  T a = T{}, b = T{};

  ArithmeticUpdateMonoid() = default;
  ArithmeticUpdateMonoid(const ArithmeticUpdateMonoid&) = default;
  ArithmeticUpdateMonoid(ArithmeticUpdateMonoid&&) = default;
  ArithmeticUpdateMonoid &operator=(const ArithmeticUpdateMonoid&) = default;
  ArithmeticUpdateMonoid &operator=(ArithmeticUpdateMonoid&&) = default;

  ArithmeticUpdateMonoid(const T &a, const T &b): id(false), a(a), b(b) {}
  ArithmeticUpdateMonoid(const T &a, const T &b, size_t l): id(false), a(a - b * l), b(b) {}

  ArithmeticUpdateMonoid &operator+=(const ArithmeticUpdateMonoid &m){
    if(!m.id) id = m.id, a = m.a, b = m.b;
    return (*this);
  }

  ArithmeticUpdateMonoid operator+(const ArithmeticUpdateMonoid &m){ return ArithmeticUpdateMonoid(*this) += m; }

  bool operator==(const ArithmeticUpdateMonoid &m) const {
    if(id && m.id) return true;
    if(id != m.id) return false;
    return (a == m.a) && (b == m.b);
  }

  bool operator!=(const ArithmeticUpdateMonoid &m) const { return !((*this) == m); }
};
