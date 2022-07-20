template<typename T>
struct MinMonoid{
  T x = numeric_limits<T>::max();
  MinMonoid() = default;
  MinMonoid(const MinMonoid&) = default;
  MinMonoid(MinMonoid&&) = default;

  MinMonoid(const T &x): x(x) {}

  MinMonoid &operator=(const MinMonoid&) = default;
  MinMonoid &operator=(MinMonoid&&) = default;

  MinMonoid &operator+=(const MinMonoid &m){
    x = min(x, m.x);
    return (*this);
  }
  MinMonoid operator+(const MinMonoid &m) const {
    return MinMonoid(*this) += m;
  }
};
