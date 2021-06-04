struct Date{
  uint64_t G;
  constexpr Date() : G() {}
  constexpr Date(uint64_t G): G(G) {}
  constexpr Date(int y, int m, int d) : G(date_to_G(y,m,d)) {}

  constexpr Date &operator+=(const Date &d){ this->G += d.G; return (*this); }
  constexpr Date &operator-=(const Date &d){ this->G -= d.G; return (*this); }
  constexpr Date operator+(const Date &d) const { return Date(*this) += d; }
  constexpr Date operator-(const Date &d) const { return Date(*this) -= d; }

  constexpr Date &operator+=(int d){ this->G += d; return (*this); }
  constexpr Date &operator-=(int d){ this->G -= d; return (*this); }
  constexpr Date operator+(int d) const { return Date(*this) += d; }
  constexpr Date operator-(int d) const { return Date(*this) -= d; }

  constexpr Date &operator++(){ this->G++; return (*this); }
  constexpr Date &operator++(int){ this->G++; return (*this); }
  constexpr Date &operator--(){ this->G--; return (*this); }
  constexpr Date &operator--(int){ this->G--; return (*this); }

  constexpr tuple<int,int,int> get_date() const {
    uint64_t J = G + (4*G + 146100) / 146097 * 3 / 4;
    uint64_t L = J + (4*J + 1464) / 1461 * 3 / 4;
    int y = L/366, r = L%366, m = (5*r+2)/153 + 3, d = (5*r+2)%153/5 + 1;
    if(m > 12) y++, m -= 12;
    return {y, m, d};
  }

  constexpr int get_w() const { return (G + 3) % 7; }

  static constexpr uint64_t date_to_G(int y, int m, int d){
    if(m <= 2) y--, m += 12;
    return 365ull * y + y/4 - y/100 + y/400 + (153*(m-3) + 2)/5 + d - 1;
  }
};