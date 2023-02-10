#pragma once

#include ".\\geometry_base.cpp"


template<class T> struct Point{
  T x,y;
  Point() = default;
  Point(T x, T y) : x(x), y(y) {}
  Point(const pair<T,T> &p) : x(p.first), y(p.second) {}

  Point operator*(const T b) const { return Point(x * b, y * b); }
  Point operator/(const T b) const { return Point(x / b, y / b); }
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  Point operator*(const Point &b) const { return Point(x*b.x - y*b.y, x*b.y + y*b.x); }
  Point operator/(const Point &b) const { return Point(x*b.x + y*b.y, y*b.x - x*b.y)/(b.x*b.x + b.y*b.y); }

  Point &operator*=(const T b){ return (*this) = (*this) * b; }
  Point &operator/=(const T b){ return (*this) = (*this) / b; }
  Point &operator+=(const Point &b){ return (*this) = (*this) + b; }
  Point &operator-=(const Point &b){ return (*this) = (*this) - b; }
  Point &operator*=(const Point &b){ return (*this) = (*this) * b; }
  Point &operator/=(const Point &b){ return (*this) = (*this) / b; }
  
  bool operator==(const Point &b) const {
    return geometry::eq(x, b.x) && geometry::eq(y, b.y);
  }
  bool operator!=(const Point &b) const {
    return !(geometry::eq(x, b.x) && geometry::eq(y, b.y));
  }
  bool operator<(const Point &b) const { 
    if(geometry::eq(x, b.x)) return y < b.y;
    return x < b.x;
  }
  T norm() const { return x * x + y * y; }
  double abs() const { return hypot<double>(x, y); }
  double dist(const Point &b) const { return hypot<double>(x - b.x, y - b.y); }
  double arg() const { return atan2<double>(y, x); }
  
  Point ArgVec() const {
    if((*this) == Point(0, 0)) return (*this);
    if(geometry::is_zero(x)) return Point(0, -1);
    return (*this) / gcd(x, y) * (x < 0 ? -1 : 1);
  }

  int ort() const {
    if(geometry::is_zero(x) && geometry::is_zero(y)) return 0;
    if(geometry::is_zero(y)) return x > 0 ? 1 : 3;
    if(geometry::is_zero(x)) return y > 0 ? 2 : 4;
    if (y > 0) return x > 0 ? 1 : 2;
    else return x > 0 ? 4 : 3;
  }
  Point rotate90() const { return Point(-y, x);}
  Point rotate180() const { return Point(-x, -y);}
  Point rotate270() const { return Point(y, -x);}

  Point flip_x(T p = 0) const { return Point(p*2 - x, y);}
  Point flip_y(T p = 0) const { return Point(x, p*2 - y);}

  Point rotate(double theta) const {
    return Point(cos(theta)*x - sin(theta)*y, sin(theta)*x + cos(theta)*y);
  }

  Point flip(double theta) const {
    return (*this).rotate(-theta).flip_y().rotate(theta);
  }

  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << p.x << " " << p.y;
  }
  friend istream &operator>>(istream &is, Point &p) {
    T a, b; is >> a >> b;
    p = Point<T>(a, b);
    return (is);
  }

  T cross(const Point &p) const { return x * p.y - y * p.x; }
  T cross(const Point &p, const Point &q) const { return (p - (*this)).cross(q - (*this)) ; }

  T dot(const Point &p) const { return x * p.x + y * p.y; }
  T dot(const Point &p, const Point &q) const { return (p - (*this)).dot(q - (*this)) ; }

  
};

template<typename T> Point<T> Polar(const T& rho, const T& theta = 0){
  return Point<T>(rho * cos(theta), rho * sin(theta));
}

template<typename T> using Polygon = vector<Point<T>>;

template<class T> int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T fl = a.cross(b, c);
  if(geometry::lt(T(0), fl)) return 1; // CCW
  if(geometry::lt(fl, T(0))) return -1; // CW
  if(geometry::lt(b.dot(a, c), T(0))) return 2; //abc
  if(geometry::lt(a.dot(b, c), T(0))) return -2; //bac
  return 0; // acb
}

template<typename T>
bool cmp_y(const Point<T>& p1, const Point<T> &p2){
  if(p1.y == p2.y) return p1.x < p2.x;
  return p1.y < p2.y;
}

template<typename T>
bool cmp_arg(const Point<T>& p1, const Point<T> &p2){
  if(p1.ort() != p2.ort()) return p1.ort() < p2.ort();
  return p1.cross(p2) > 0;
}

template<typename T>
void arg_sort(Polygon<T> &ps){
  sort(begin(ps), end(ps), cmp_arg<T>);
}
