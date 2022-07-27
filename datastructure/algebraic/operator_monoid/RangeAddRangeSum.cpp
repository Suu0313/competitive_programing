template<typename T>
struct RangeAddRangeSum{
  using Monoid = LengthMonoid<T>;
  using OperatorMonoid = T;

  static void act(Monoid &m, const OperatorMonoid &f){
    m.x += f * m.l;
  }
};
