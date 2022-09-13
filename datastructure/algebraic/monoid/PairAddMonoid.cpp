template<typename T>
struct PairAddMonoid{
  T a = T{}, b = T{};

  PairAddMonoid() = default;
  PairAddMonoid(const PairAddMonoid&) = default;
  PairAddMonoid(PairAddMonoid&&) = default;
  PairAddMonoid &operator=(const PairAddMonoid&) = default;
  PairAddMonoid &operator=(PairAddMonoid&&) = default;

  PairAddMonoid(const T &a, const T &b): a(a), b(b) {}
  PairAddMonoid(const T &a, const T &b, size_t l): a(a - b * l), b(b) {}

  PairAddMonoid &operator+=(const PairAddMonoid &m){
    a += m.a, b += m.b;
    return (*this);
  }

  PairAddMonoid operator+(const PairAddMonoid &m) const { return PairAddMonoid(*this) += m; }

  bool operator==(const PairAddMonoid &m) const { return (a == m.a) && (b == m.b); }

  bool operator!=(const PairAddMonoid &m) const { return !((*this) == m); }
};
