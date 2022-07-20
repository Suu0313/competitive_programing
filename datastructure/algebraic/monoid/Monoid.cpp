struct Monoid{

  Monoid() = default;
  Monoid(const Monoid&) = default;
  Monoid(Monoid&&) = default;
  Monoid &operator=(const Monoid&) = default;
  Monoid &operator=(Monoid&&) = default;

  Monoid(){}

  Monoid &operator+=(const Monoid &m){

  }

  Monoid operator+(const Monoid &m){ return Monoid(*this) += m; }
};
