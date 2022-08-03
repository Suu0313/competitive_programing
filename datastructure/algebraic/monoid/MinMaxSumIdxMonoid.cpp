template<typename T>
struct MinMaxSumIdxMonoid{
  T mn = numeric_limits<T>::min(), mx = numeric_limits<T>::max(), sum = 0;
  int l = -1, r = -1;
  MinMaxSumIdxMonoid() = default;
  MinMaxSumIdxMonoid(const MinMaxSumIdxMonoid&) = default;
  MinMaxSumIdxMonoid(MinMaxSumIdxMonoid&&) = default;

  MinMaxSumIdxMonoid(const T &x, int k): mn(x), mx(x), sum(x), l(k), r(k + 1) {}
  MinMaxSumIdxMonoid(const T &x, int l, int r): mn(x), mx(x), sum(x * (r - l)), l(l), r(r) {}
  MinMaxSumIdxMonoid(const T &mn, const T &mx, const T &sum, int l, int r): mn(mn), mx(mx), sum(sum), l(l), r(r) {}

  MinMaxSumIdxMonoid &operator=(const MinMaxSumIdxMonoid&) = default;
  MinMaxSumIdxMonoid &operator=(MinMaxSumIdxMonoid&&) = default;

  MinMaxSumIdxMonoid &operator+=(const MinMaxSumIdxMonoid &m){
    if(m.l == -1) return (*this);
    if(this->l == -1) return (*this) = m;
    mn = min(mn, m.mn);
    mx = max(mx, m.mx);
    sum += m.sum;
    r = m.r;
    return (*this);
  }
  MinMaxSumIdxMonoid operator+(const MinMaxSumIdxMonoid &m) const {
    return MinMaxSumIdxMonoid(*this) += m;
  }
};
