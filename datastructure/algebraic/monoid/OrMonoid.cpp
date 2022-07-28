template<typename T>
struct OrMonoid{

  OrMonoid() = default;
  OrMonoid(const OrMonoid&) = default;
  OrMonoid(OrMonoid&&) = default;
  OrMonoid &operator=(const OrMonoid&) = default;
  OrMonoid &operator=(OrMonoid&&) = default;

  T x = 0;
  OrMonoid(const T &x): x(x) {}

  OrMonoid &operator+=(const OrMonoid &m){
    x |= m.x;
  }

  OrMonoid operator+(const OrMonoid &m){ return OrMonoid(*this) += m; }

  bool operator==(const OrMonoid &m) const { return x == m.x; }
  bool operator!=(const OrMonoid &m) const { return !((*this) == m); }

};
