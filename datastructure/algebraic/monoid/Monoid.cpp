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
  }

  Monoid operator+(const Monoid &m){ return Monoid(*this) += m; }

  bool operator==(const SetMonoid &m) const { return x == m.x; }
  bool operator!=(const SetMonoid &m) const { return !((*this) == m); }

};
