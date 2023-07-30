---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/Date.cpp\"\n\r\nstruct Date{\r\n  uint64_t G;\r\n\
    \  constexpr Date() : G() {}\r\n  constexpr Date(uint64_t G): G(G) {}\r\n  constexpr\
    \ Date(int y, int m, int d) : G(date_to_G(y,m,d)) {}\r\n\r\n  constexpr Date &operator+=(const\
    \ Date &d){ this->G += d.G; return (*this); }\r\n  constexpr Date &operator-=(const\
    \ Date &d){ this->G -= d.G; return (*this); }\r\n  constexpr Date operator+(const\
    \ Date &d) const { return Date(*this) += d; }\r\n  constexpr Date operator-(const\
    \ Date &d) const { return Date(*this) -= d; }\r\n\r\n  constexpr Date &operator+=(int\
    \ d){ this->G += d; return (*this); }\r\n  constexpr Date &operator-=(int d){\
    \ this->G -= d; return (*this); }\r\n  constexpr Date operator+(int d) const {\
    \ return Date(*this) += d; }\r\n  constexpr Date operator-(int d) const { return\
    \ Date(*this) -= d; }\r\n\r\n  constexpr Date &operator++(){ this->G++; return\
    \ (*this); }\r\n  constexpr Date operator++(int){ Date tmp(*this); this->G++;\
    \ return tmp; }\r\n  constexpr Date &operator--(){ this->G--; return (*this);\
    \ }\r\n  constexpr Date operator--(int){ Date tmp(*this); this->G--; return tmp;\
    \ }\r\n\r\n  constexpr bool operator==(const Date &d) const { return this->G ==\
    \ d.G; }\r\n  constexpr bool operator!=(const Date &d) const { return this->G\
    \ != d.G; }\r\n  constexpr bool operator<(const Date &d) const { return this->G\
    \ < d.G; }\r\n\r\n  constexpr tuple<int,int,int> get_date() const {\r\n    uint64_t\
    \ J = G + (4*G + 146100) / 146097 * 3 / 4;\r\n    uint64_t L = J + (4*J + 1464)\
    \ / 1461 * 3 / 4;\r\n    int y = L/366, r = L%366, m = (5*r+2)/153 + 3, d = (5*r+2)%153/5\
    \ + 1;\r\n    if(m > 12) y++, m -= 12;\r\n    return {y, m, d};\r\n  }\r\n  constexpr\
    \ int get_y() const { return get<0>(get_date()); }\r\n  constexpr int get_m()\
    \ const { return get<1>(get_date()); }\r\n  constexpr int get_d() const { return\
    \ get<2>(get_date()); }\r\n  constexpr int get_w() const { return (G + 3) % 7;\
    \ } // Sun = 0\r\n  constexpr bool is_weekend() const { return get_w() == 0 ||\
    \ get_w() == 6; }\r\n  constexpr bool is_weekday() const { return !is_weekend();\
    \ }\r\n\r\n  static constexpr uint64_t date_to_G(int y, int m, int d){\r\n   \
    \ if(m <= 2) y--, m += 12;\r\n    return 365ull * y + y/4 - y/100 + y/400 + (153*(m-3)\
    \ + 2)/5 + d - 1;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct Date{\r\n  uint64_t G;\r\n  constexpr Date() :\
    \ G() {}\r\n  constexpr Date(uint64_t G): G(G) {}\r\n  constexpr Date(int y, int\
    \ m, int d) : G(date_to_G(y,m,d)) {}\r\n\r\n  constexpr Date &operator+=(const\
    \ Date &d){ this->G += d.G; return (*this); }\r\n  constexpr Date &operator-=(const\
    \ Date &d){ this->G -= d.G; return (*this); }\r\n  constexpr Date operator+(const\
    \ Date &d) const { return Date(*this) += d; }\r\n  constexpr Date operator-(const\
    \ Date &d) const { return Date(*this) -= d; }\r\n\r\n  constexpr Date &operator+=(int\
    \ d){ this->G += d; return (*this); }\r\n  constexpr Date &operator-=(int d){\
    \ this->G -= d; return (*this); }\r\n  constexpr Date operator+(int d) const {\
    \ return Date(*this) += d; }\r\n  constexpr Date operator-(int d) const { return\
    \ Date(*this) -= d; }\r\n\r\n  constexpr Date &operator++(){ this->G++; return\
    \ (*this); }\r\n  constexpr Date operator++(int){ Date tmp(*this); this->G++;\
    \ return tmp; }\r\n  constexpr Date &operator--(){ this->G--; return (*this);\
    \ }\r\n  constexpr Date operator--(int){ Date tmp(*this); this->G--; return tmp;\
    \ }\r\n\r\n  constexpr bool operator==(const Date &d) const { return this->G ==\
    \ d.G; }\r\n  constexpr bool operator!=(const Date &d) const { return this->G\
    \ != d.G; }\r\n  constexpr bool operator<(const Date &d) const { return this->G\
    \ < d.G; }\r\n\r\n  constexpr tuple<int,int,int> get_date() const {\r\n    uint64_t\
    \ J = G + (4*G + 146100) / 146097 * 3 / 4;\r\n    uint64_t L = J + (4*J + 1464)\
    \ / 1461 * 3 / 4;\r\n    int y = L/366, r = L%366, m = (5*r+2)/153 + 3, d = (5*r+2)%153/5\
    \ + 1;\r\n    if(m > 12) y++, m -= 12;\r\n    return {y, m, d};\r\n  }\r\n  constexpr\
    \ int get_y() const { return get<0>(get_date()); }\r\n  constexpr int get_m()\
    \ const { return get<1>(get_date()); }\r\n  constexpr int get_d() const { return\
    \ get<2>(get_date()); }\r\n  constexpr int get_w() const { return (G + 3) % 7;\
    \ } // Sun = 0\r\n  constexpr bool is_weekend() const { return get_w() == 0 ||\
    \ get_w() == 6; }\r\n  constexpr bool is_weekday() const { return !is_weekend();\
    \ }\r\n\r\n  static constexpr uint64_t date_to_G(int y, int m, int d){\r\n   \
    \ if(m <= 2) y--, m += 12;\r\n    return 365ull * y + y/4 - y/100 + y/400 + (153*(m-3)\
    \ + 2)/5 + d - 1;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/Date.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/Date.cpp
layout: document
redirect_from:
- /library/other/Date.cpp
- /library/other/Date.cpp.html
title: other/Date.cpp
---
