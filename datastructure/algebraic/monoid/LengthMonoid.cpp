template<typename T>
struct LengthMonoid{
  T x{};
  size_t l = 0;

  LengthMonoid() = default;
  LengthMonoid(const LengthMonoid&) = default;
  LengthMonoid(LengthMonoid&&) = default;

  LengthMonoid(const T &x, size_t l = 1): x(x), l(l) {}

  LengthMonoid &operator=(const LengthMonoid&) = default;
  LengthMonoid &operator=(LengthMonoid&&) = default;

  LengthMonoid &operator+=(const LengthMonoid &m){
    x += m.x; l += m.l;
    return (*this);
  }
  LengthMonoid operator+(const LengthMonoid &m) const {
    return LengthMonoid(*this) += m;
  }

  bool operator==(const LengthMonoid &m) const { return x == m.x && l == m.l; }
  bool operator!=(const LengthMonoid &m) const { return !((*this) == m); }
};
