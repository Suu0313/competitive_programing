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

template<typename T>
struct RangeArithmeticAddRangeSum{
  using Monoid = SumIdxMonoid<T>;
  using OperatorMonoid = PairAddMonoid<T>;
  static void act(Monoid &m, const OperatorMonoid &f){
    T a = f.a + f.b * m.l;
    m.sum += (a * 2 + f.b * (m.r - m.l - 1)) * (m.r - m.l) / 2;
  }
};
