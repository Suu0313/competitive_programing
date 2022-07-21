template<typename T>
struct RangeAffineRangeSum{
  using Monoid = LengthMonoid<T>;
  using OperatorMonoid = CompositeMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m = Monoid(f.a * m.x + f.b * m.l, m.l);
  }
};
