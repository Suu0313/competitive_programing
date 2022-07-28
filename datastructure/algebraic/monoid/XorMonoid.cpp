template<typename T>
struct XorMonoid{

  XorMonoid() = default;
  XorMonoid(const XorMonoid&) = default;
  XorMonoid(XorMonoid&&) = default;
  XorMonoid &operator=(const XorMonoid&) = default;
  XorMonoid &operator=(XorMonoid&&) = default;

  T x = 0;
  XorMonoid(const T &x): x(x) {}

  XorMonoid &operator+=(const XorMonoid &m){
    x ^= m.x;
  }

  XorMonoid operator+(const XorMonoid &m){ return XorMonoid(*this) += m; }

  bool operator==(const XorMonoid &m) const { return x == m.x; }
  bool operator!=(const XorMonoid &m) const { return !((*this) == m); }

};
