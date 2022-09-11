template<typename T>
struct SumIdxMonoid{
  T sum = 0;
  int l = -1, r = -1;
  SumIdxMonoid() = default;
  SumIdxMonoid(const SumIdxMonoid&) = default;
  SumIdxMonoid(SumIdxMonoid&&) = default;

  SumIdxMonoid(const T &x, int k): sum(x), l(k), r(k + 1) {}

  SumIdxMonoid &operator=(const SumIdxMonoid&) = default;
  SumIdxMonoid &operator=(SumIdxMonoid&&) = default;

  SumIdxMonoid &operator+=(const SumIdxMonoid &m){
    if(m.l == -1) return (*this);
    if(this->l == -1) return (*this) = m;
    sum += m.sum;
    r = m.r;
    return (*this);
  }
  SumIdxMonoid operator+(const SumIdxMonoid &m) const {
    return SumIdxMonoid(*this) += m;
  }
};
