template<typename T>
struct AndMonoid{

  AndMonoid() = default;
  AndMonoid(const AndMonoid&) = default;
  AndMonoid(AndMonoid&&) = default;
  AndMonoid &operator=(const AndMonoid&) = default;
  AndMonoid &operator=(AndMonoid&&) = default;

  T x = -1;
  AndMonoid(const T &x): x(x) {}

  AndMonoid &operator+=(const AndMonoid &m){
    x &= m.x;
  }

  AndMonoid operator+(const AndMonoid &m){ return AndMonoid(*this) += m; }

  bool operator==(const AndMonoid &m) const { return x == m.x; }
  bool operator!=(const AndMonoid &m) const { return !((*this) == m); }

};
