template<typename T>
struct RangechminRangeMin{
  using Monoid = MinMonoid<T>;
  using OperatorMonoid = MinMonoid<T>;

  static void act(Monoid &m, const OperatorMonoid &f){
    m += f;
  }
};
