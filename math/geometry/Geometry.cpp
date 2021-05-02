template<class T> struct Point{
  T x,y;
  Point(){}
  Point(T x, T y) : x(x), y(y) {}
  Point(const pair<T,T> &p) : x(p.first), y(p.second) {}
  
  Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
  Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
  Point operator*(const T b) const { return Point(x * b, y * b); }
  Point operator/(const T b) const { return Point(x / b, y / b); }
  bool operator==(const Point &b) const {
    return (x == b.x && y == b.y);
    //return Eq(x, b.x) && Eq(y, b.y);
  }
  bool operator<(const Point &b) const { 
    if(x==b.x) return y<b.y;
    return x<b.x; }
  T Norm() const { return x * x + y * y; }
  double Abs() const { return hypot<double>(x, y); }
  double dist(const Point &b) const { return hypot<double>(x-b.x,y-b.y); }
  double arg() const { return atan2<double>(y, x); }
  
  int ort() const {
    //if (abs(x) < EPS && abs(y) < EPS) return 0;
    if (abs(x) == 0 && abs(y) == 0) return 0;
    if(y==0) return x>0 ? 1 : 3;
    if(x==0) return y>0 ? 2 : 4;
    if (y > 0) return x>0 ? 1 : 2;
    else return x>0 ? 4 : 3;
  }
  Point rotate90() const { return Point(-y, x);}
  Point rotate180() const { return Point(-x, -y);}
  Point rotate270() const { return Point(y, -x);}

  Point flip_x(T p = 0) const { return Point(p*2-x, y);}
  Point flip_y(T p = 0) const { return Point(x, p*2-y);}

  Point rotate(double theta) const {
    return Point(cos(theta)*x-sin(theta)*y, sin(theta)*x+cos(theta)*y);
  }

  Point flip(double theta) const {
    return (*this).rotate(-theta).flip_y().rotate(theta);
  }

  Point operator*(const Point &b) const { return Point(x*b.x-y*b.y,x*b.y+y*b.x); }
  Point operator/(const Point &b) const { return Point(x*b.x+y*b.y,y*b.x-x*b.y)/(b.x*b.x+b.y*b.y); }

  friend ostream &operator<<(ostream &os, const Point &p) {
    return os << p.x << " " << p.y;
  }
  friend istream &operator>>(istream &is, Point &p) {
    T a, b; is >> a >> b;
    p = Point<T>(a, b);
    return (is);
  }
};

template<typename T> Point<T> Polar(const T& rho, const T& theta = 0){
  return Point<T>(rho * cos(theta), rho * sin(theta));
}

template<typename T = double>
tuple<Point<T>,Point<T>,Point<T>> ClockHands(const T& h, const T& m = 0, const T& s = 0){
  const double PI  = 3.141592653589793238462643383279;
  double ts = 2*PI / 60 * s, tm = 2*PI / 60 * m + ts / 60 ,th = 2*PI / 12 * h + tm / 12;
  return make_tuple(Polar<T>(1, th), Polar<T>(1, tm), Polar<T>(1, ts));
}

template<typename T> using Polygon = vector<Point<T>>;

template<class T> T Cross(const Point<T> &a, const Point<T> &b) { return a.x * b.y - a.y * b.x; }

template<class T> T Dot(const Point<T> &a, const Point<T> &b) { return a.x * b.x + a.y * b.y; }

template<class T> bool Intersect(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d) {
  return iSP(a, b, c)*iSP(a, b, d)<=0 && iSP(c, d, a)*iSP(c, d, b)<=0;
}

template<class T> int iSP(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T fl = Cross(b-a, c-a);
  if(fl > 0) return 1; // CCW
  if(fl < 0) return -1; // CW
  if(Dot(b-a, c-b) > 0) return 2; //abc
  if(Dot(a-b, c-a) > 0) return -2; //bac
  return 0; // acb
}

template<class T> int angletype(const Point<T> &a, const Point<T> &b, const Point<T> &c){
  T v = Dot(a-b, c-a);
  if(v == 0) return 0; // right angle
  if(v > 0) return 1; // acute angle
  return -1; // obtuse angle
}

template<typename T> T Area(const Polygon<T> &ps){
  if((int)ps.size() < 3) return 0;
  T res = Cross(ps.back(), ps.front());
  for(int i = 0; i < (int)ps.size()-1; i++){
    res += Cross(ps[i], ps[i+1]);
  }
  return res/2;
}

template<typename T> bool isConvex(const Polygon<T> &ps){
  int n = ps.size();
  for(int i = 0; i < n; i++){
    if(iSP(ps[i], ps[(i+1)%n], ps[(i+2)%n]) == -1) return false;
  }
  return true;
}

template<typename T>
Polygon<T> ConvexHull(Polygon<T> ps, bool strict = true){
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  Polygon<T> res(2 * n);
  auto check = [&](int i){
    if(strict) return Cross(res[k-1]-res[k-2], ps[i]-res[k-1]) <= 0;
    return Cross(res[k-1]-res[k-2], ps[i]-res[k-1]) < 0;
  };
  for(int i = 0; i < n; res[k++] = ps[i++]){
    while(k > 1 && check(i)) k--;
  }
  for(int i = n-2, t=k+1; i >= 0; res[k++] = ps[i--]){
    while(k >= t && check(i)) k--;
  }
  res.resize(k-1);
  return res;
}

template<typename T>
double ConvexDiameter(const Polygon<T> &ps){
  Polygon<T> qs = ConvexHull(ps);
  int n = qs.size();
  if(n == 2) return qs[0].dist(qs[1]);
  int i=0, j=0;
  for(int k = 0; k < n; k++){
    if(!(qs[i] < qs[k])) i = k;
    if(qs[j] < qs[k]) j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while(i!=sj || j!=si){
    res = max(res, qs[i].dist(qs[j]));
    if(Cross(qs[(i+1)%n]-qs[i], qs[(j+1)%n]-qs[j]) < 0){
      i = (i + 1)%n;
    }else{
      j = (j + 1)%n;
    }
  }
  return res;
}

template<class T> struct Line{
  Point<T> a, b;
  Line() {}
  Line(const Point<T> &a, const Point<T> &b): a(a), b(b) {}
  Line(T A, T B, T C){ // Ax + By = C
    if(A == 0){ a = Point<T>(0, C/B); b = Point<T>(1, C/B); }
    else if(B == 0){ a = Point<T>(C/A, 0); b = Point<T>(C/A, 1); }
    else{ a = Point<T>(0, C/B); b = Point<T>(C/A, 0); }
  }
  //Line(const Segment<T> &s): a(s.a), b(s.b) {}
  Point<T> flip(const Point<T> &p) const {
    return (p - a).flip((b-a).arg()) + a;
  }
  Point<T> projection(const Point<T> &p) const {
    return (p + flip(p))/2;
  }
  int angletype(const Line &l) const {
    if(Cross(b-a, l.b-l.a) == 0) return 1;
    if(Dot(a-b, l.b-l.a) == 0) return -1;
    return 0;
  }
  bool Intersect(const Line &l) const {
    return angletype(l) != 1;
  }
  Point<T> Cross_Point(const Line &l) const {
    if(Cross(b-a,l.b-l.a) == 0) return l.a;
    return (b-a)*Cross(l.a-a, l.b-l.a)/Cross(b-a,l.b-l.a) + a;
  }
  double dist(const Point<T> &p) const {
    return abs(Cross(p-a, b-a)/ (b-a).Abs());
  }
  double dist(const Line &l) const {
    if(Intersect(l)) return 0;
    return dist(l.a);
  }
};

template<class T> struct Segment{
  Point<T> a, b;
  Segment() {}
  Segment(const Point<T> &a, const Point<T> &b): a(a), b(b) {}

  double length() const { return a.dist(b); }
  bool Intersect(const Segment &s) const {
    return iSP(a, b, s.a)*iSP(a, b, s.b)<=0 && iSP(s.a, s.b, a)*iSP(s.a, s.b, b)<=0;
  }
  Point<T> Center() const { return (a + b) / 2; }
  Line<T> PerpBisector() const {
    Point<T> center = this->Center();
    return Line<T>((a-center).rotate90() + center, center);
  }
  int angletype(const Segment &s) const {
    if(Cross(b-a, s.b-s.a) == 0) return 1;
    if(Dot(a-b, s.b-s.a) == 0) return -1;
    return 0;
  }
  Point<T> Cross_Point(const Segment &s) const {
    if(Cross(b-a,s.b-s.a) == 0) return s.a;
    return (b-a)*Cross(s.a-a, s.b-s.a)/Cross(b-a,s.b-s.a) + a;
  }
  double dist(const Point<T> &p) const {
    if(Dot(b-a, p-a) < 0) return p.dist(a);
    if(Dot(a-b, p-b) < 0) return p.dist(b);
    return abs(Cross(p-a, b-a)/ (b-a).Abs());
  }
  double dist(const Segment &s) const {
    if(Intersect(s)) return 0;
    return min({dist(s.a), dist(s.b), s.dist(a), s.dist(b)});
  }
};

template<typename T>
struct Triangle{
  Point<T> a, b, c;
  Triangle() {}
  Triangle(const Point<T> &a, const Point<T> &b, const Point<T> &c): a(a), b(b), c(c){}

  double angle_a() const {
    double ab = a.dist(b), bc = b.dist(c), ca = c.dist(a);
    return acos((ca*ca + ab*ab - bc*bc)/(2*ca*ab));
  }
  double angle_b() const {
    double ab = a.dist(b), bc = b.dist(c), ca = c.dist(a);
    return acos((ab*ab + bc*bc - ca*ca)/(2*ab*bc));
  }
  double angle_c() const {
    double ab = a.dist(b), bc = b.dist(c), ca = c.dist(a);
    return acos((bc*bc + ca*ca - ab*ab)/(2*bc*ca));
  }
  Point<T> divpoint(double p, double q, double r) const {
    return (a*p + b*q + c*r)/(p + q + r);
  }

  Point<T> centerofgravity() const {
    return (a + b + c)/3;
  }
  Point<T> circumcenter() const {
    Segment<T> s1(a, b), s2(a, c);
    return s1.PerpBisector().Cross_Point(s2.PerpBisector());
  }
  Point<T> orthocenter() const {
    return centerofgravity()*3 - circumcenter()*2;
  }
  Point<T> innercenter() const {
    return divpoint(b.dist(c), c.dist(a), a.dist(b));
  }
  Point<T> excenterA() const {
    return divpoint(-b.dist(c), c.dist(a), a.dist(b));
  }
  Point<T> excenterB() const {
    return divpoint(b.dist(c), -c.dist(a), a.dist(b));
  }
  Point<T> excenterC() const {
    return divpoint(b.dist(c), c.dist(a), -a.dist(b));
  }
};

template<class T> struct Circle{
  Point<T> o;
  T r;
  Circle() {}
  Circle(const Point<T> &o, const T &r): o(o), r(r) {}
  Circle(const Point<T> &a, const Point<T> &b): o((a+b)/2), r(a.dist(b)/2) {}
  Circle(const Point<T> &a, const Point<T> &b, const Point<T> &c)
    : o(Triangle(a,b,c).circumcenter()), r(o.dist(a)) {}

  int Intersect(const Circle&c) const {
    if(r < c.r) return c.Intersect(*this);
    double d = o.dist(c.o);
    if(r+c.r < d) return 4;
    if(r+c.r - d < (1e-10)) return 3;
    if(r-c.r < d) return 2;
    if(r-c.r - d < (1e-10)) return 1;
    return 0;
  }
  int Contains(const Point<T> &p) const {
    double d = o.dist(p);
    if(d == r) return 1; // on
    return (d > r) ? 2 : 0; // out/in
  }
};



template<typename T>
bool cmp_y(const Point<T>& p1, const Point<T> &p2){
  if(p1.y == p2.y) return p1.x < p2.x;
  return p1.y < p2.y;
}

template<typename T>
bool cmp_arg(const Point<T>& p1, const Point<T> &p2){
  if(p1.ort() != p2.ort()) return p1.ort() < p2.ort();
  return iSP(Point<T>(0,0), p1, p2) > 0;
}

template<typename T>
int Contains(const Polygon<T> &ps, const Point<T>& p){
  bool in = false;
  int n = ps.size();
  for(int i = 0; i < n; i++){
    Point<T> a = ps[i] - p, b = ps[(i+1)%n] - p;
    if(a.y > b.y) swap(a, b);
    if(a.y <= 0 && 0 < b.y && Cross(a,b) < 0) in = !in;
    if(Cross(a, b) == 0 && Dot(a, b) <= 0) return 1; // on
  }
  return in? 2 : 0; // out/in
}

template<typename T>
pair<Polygon<T>,Polygon<T>> ConvexCut(const Polygon<T> &ps, const Line<T> &l){
  Polygon<T> lres, rres;
  int n = ps.size();
  for(int i = 0; i < n; i++){
    int a = iSP(l.a, l.b, ps[i]), b = iSP(l.a, l.b, ps[(i+1)%n]);
    if(a != -1) lres.emplace_back(ps[i]);
    if(a != 1) rres.emplace_back(ps[i]);
    if(a*b < 0){
      auto p = Line(ps[i], ps[(i+1)%n]).Cross_Point(l);
      lres.emplace_back(p); rres.emplace_back(p);
    }
  }
  return make_pair(lres, rres);
}

template<typename T>
double ClosestPair(Polygon<T> &a, int l, int r){
  if(r - l <= 1) return numeric_limits<T>::max();
  int mid = (l + r)/2;
  double x =a[mid].x;
  double d = min(ClosestPair(a,l,mid),ClosestPair(a,mid,r));
  inplace_merge(a.begin()+l,a.begin()+mid,a.begin()+r,cmp_y<T>);

  Polygon<T> b;
  for(int i = l; i < r; i++){
    if(abs(a[i].x-x) >= d) continue;
    for(int j = (int)b.size()-1; j >= 0; j--){
      if(abs(a[i].y-b[j].y) >= d) break;
      d = min(d, a[i].dist(b[j]));
    }
    b.emplace_back(a[i]);
  }
  return d;
}

template<typename T>
double ClosestPair(Polygon<T> &a){
  sort(a.begin(), a.end());
  return ClosestPair(a, 0, a.size());
}

template<typename T>
Circle<T> SmallestEnclosingCircle(Polygon<T> ps){
  int n = ps.size();
  if(n == 1) return Circle<T>(ps[0], 0);
  random_device seed;
  mt19937 rng(seed());
  shuffle(ps.begin(), ps.end(), rng);
  Circle<T> c(ps[0], ps[1]);
  for(int i = 2; i < n; i++){
    if(c.Contains(ps[i]) != 2) continue;
    c = Circle<T>(ps[0], ps[i]);
    for(int j = 1; j < i; j++){
      if(c.Contains(ps[j]) != 2) continue;
      c = Circle<T>(ps[i], ps[j]);
      for(int k = 0; k < j; k++){
        if(c.Contains(ps[k]) != 2) continue;
        c = Circle<T>(ps[i], ps[j], ps[k]);
      }
    }
  }
  return c;
}
