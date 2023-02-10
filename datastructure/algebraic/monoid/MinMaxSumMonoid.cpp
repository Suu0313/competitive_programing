#pragma once

template<typename T>
struct MinMaxSumMonoid{
  T mn = numeric_limits<T>::min(), mx = numeric_limits<T>::max(), sum = 0;
  size_t len = 0;
  MinMaxSumMonoid() = default;
  MinMaxSumMonoid(const MinMaxSumMonoid&) = default;
  MinMaxSumMonoid(MinMaxSumMonoid&&) = default;

  MinMaxSumMonoid(const T &x, size_t l = 1): mn(x), mx(x), sum(x * l), len(l) {}
  MinMaxSumMonoid(const T &mn, const T &mx, const T &sum, size_t len): mn(mn), mx(mx), sum(sum), len(len) {}

  MinMaxSumMonoid &operator=(const MinMaxSumMonoid&) = default;
  MinMaxSumMonoid &operator=(MinMaxSumMonoid&&) = default;

  MinMaxSumMonoid &operator+=(const MinMaxSumMonoid &m){
    mn = min(mn, m.mn);
    mx = max(mx, m.mx);
    sum += m.sum;
    len += m.len;
    return (*this);
  }
  MinMaxSumMonoid operator+(const MinMaxSumMonoid &m) const {
    return MinMaxSumMonoid(*this) += m;
  }
};
