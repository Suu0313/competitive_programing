template<typename T>
struct RangeArithmeticAddRangeSum{
  using Monoid = SumIdxMonoid<T>;
  using OperatorMonoid = PairAddMonoid<T>;
  static void act(Monoid &m, const OperatorMonoid &f){
    T a = f.a + f.b * m.l;
    m.sum += (a * 2 + f.b * (m.r - m.l - 1)) * (m.r - m.l) / 2;
  }
};
