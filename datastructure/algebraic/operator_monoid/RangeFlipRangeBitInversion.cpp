template<typename T>
struct RangeFlipRangeBitInversion{
  using Monoid = BitInversionMonoid<T>;
  using OperatorMonoid = XorMonoid<bool>;
  static void act(Monoid &m, const OperatorMonoid &f){
    if(!f.x) return;
    m.inv = m.zero * m.one - m.inv;
    swap(m.zero, m.one);
  }
};
