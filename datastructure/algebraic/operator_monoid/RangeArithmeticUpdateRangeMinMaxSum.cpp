template<typename T>
struct RangeArithmeticUpdateRangeMinMaxSum{
  using Monoid = MinMaxSumIdxMonoid<T>;
  using OperatorMonoid = ArithmeticUpdateMonoid<T>;
  static void act(Monoid &m, const OperatorMonoid &f){
    if(f.id) return;
    T x = f.a + f.b * m.l, y = f.a + f.b * (m.r - 1);
    m.mn = min(x, y); m.mx = max(x, y);
    m.sum = (x + y) * (m.r - m.l) /2;
  }
};
