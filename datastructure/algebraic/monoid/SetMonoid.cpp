template<typename T>
struct SetMonoid{
  bool id = 1;
  T x{};

  SetMonoid() = default;
  SetMonoid(const SetMonoid&) = default;
  SetMonoid(SetMonoid&&) = default;
  SetMonoid &operator=(const SetMonoid&) = default;
  SetMonoid &operator=(SetMonoid&&) = default;

  SetMonoid(const T &x): id(false), x(x) {}

  SetMonoid &operator+=(const SetMonoid &m){
    if(!m.id) id = m.id, x = m.x;
    return (*this);
  }

  SetMonoid operator+(const SetMonoid &m){ return SetMonoid(*this) += m; }

  bool operator==(const SetMonoid &m) const {
    if(id && m.id) return true;
    if(id != m.id) return false;
    return x == m.x;
  }

  bool operator!=(const SetMonoid &m) const { return !((*this) == m); }
};
