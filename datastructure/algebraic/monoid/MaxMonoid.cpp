#pragma once

template<typename T>
struct MaxMonoid{
  T x = numeric_limits<T>::min();
  MaxMonoid() = default;
  MaxMonoid(const MaxMonoid&) = default;
  MaxMonoid(MaxMonoid&&) = default;

  MaxMonoid(const T &x): x(x) {}

  MaxMonoid &operator=(const MaxMonoid&) = default;
  MaxMonoid &operator=(MaxMonoid&&) = default;

  MaxMonoid &operator+=(const MaxMonoid &m){
    x = max(x, m.x);
    return (*this);
  }
  MaxMonoid operator+(const MaxMonoid &m) const {
    return MaxMonoid(*this) += m;
  }
};
