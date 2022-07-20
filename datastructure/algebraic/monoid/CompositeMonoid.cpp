template<typename T>
struct CompositeMonoid{
  T a = 1, b = 0;
  CompositeMonoid() = default;
  CompositeMonoid(const CompositeMonoid&) = default;
  CompositeMonoid(CompositeMonoid&&) = default;

  CompositeMonoid(const T &a, const T &b): a(a), b(b) {}

  CompositeMonoid &operator=(const CompositeMonoid&) = default;
  CompositeMonoid &operator=(CompositeMonoid&&) = default;

  CompositeMonoid &operator+=(const CompositeMonoid &m){
    a *= m.a;
    b = b * m.a + m.b;
    return (*this);
  }
  CompositeMonoid operator+(const CompositeMonoid &m) const {
    return CompositeMonoid(*this) += m;
  }
  bool operator==(const CompositeMonoid &m) const { return a == m.a && b == m.b; }
  bool operator!=(const CompositeMonoid &m) const { return !((*this) == m); }
};
