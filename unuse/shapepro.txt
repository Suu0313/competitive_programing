
// a == b なら true (誤差に寛容)
inline bool Eq(double a, double b) { return fabs(b - a) < EPS; }
 
// ユークリッド平面上の点を表す構造体
class Point
{
    public:
        double x, y;
    public:
        Point() {}
        Point(double x, double y) : x(x), y(y) {}
        Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
        Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
        Point operator*(const double b) const { return Point(x * b, y * b); }
        Point operator*(const Point &b) const { return Point(x * b.x - y * b.y, x * b.y + y * b.x); }
 
        Point operator/(const double b) const { return Point(x / b, y / b); }
        bool operator<(const Point &b) const { return x != b.x ? x < b.x : y < b.y; }
        bool operator==(const Point &b) const { return Eq(x, b.x) && Eq(y, b.y); }
 
        // 大きさの二乗を返します
        double Norm() { return x * x + y * y; }
        // 逆正接(y = 0 からの rad を [-π, π] の範囲で表したもの)を返します
        double Atan2() { return atan2(y, x); }
        // 大きさを返します
        double Abs() { return sqrt(Norm()); }
        // 原点を中心として反時計周りに theta (rad)度回転した座標を返します
        Point Rotate(double theta) { return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y); }
        // 原点を反時計周りに π/2 回転した座標を返します
        Point Rotate90() { return Point(-y, x); }
};
 
// 2 点の外積
double Cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
// 2 点の内積
double Dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
// ラジアンを角度に
double RadianToDegree(double r) { return (r * 180.0 / acos(-1)); }
// 角度をラジアンに
double DegreeToRadian(double d) { return (d * acos(-1) / 180.0); }
// a->b->c とたどったときの b の角度(ラジアン [0, π])
double GetAngle(const Point &a, const Point &b, const Point &c)
{
  const Point v = a - b, w = c - b;
  double alpha = atan2(v.y, v.x), beta = atan2(w.y, w.x);
  if(alpha > beta) { swap(alpha, beta); }
  double theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}
 
// 直線を表すクラス
class Line
{
    public:
        Point a, b;
    public:
        Line() {};
        Line(Point a, Point b) : a(a), b(b) {};
        // Ax + By = C という式が与えられたときの直線上の任意の 2 点を保存
        Line(double A, double B, double C)
        {
            if(Eq(A, 0)) { a = Point(0, C / B); b = Point(1, C / B); }
            else if(Eq(B, 0)) { a = Point(C / A, 0); b = Point(C / A, 1); }
            else { a = Point(0, C / B); b = Point(C / A, 0); }
        }
        // 傾きとの取得
        enum LineResult {
            INF_SLOPE,  // 傾き無限のグラフ (x = n のグラフ)
            NO_SLOPE,   // 切片のみのグラフ (y = b のグラフ)
            VALID_SLOPE // 傾きと切片のあるグラフ
        };
        // out_a に傾きが、 out_b に切片が、返り値として LineResult が返る
        // INF_SLOPE の時は out_b に x = n の n が入る
        int GetAB(double& out_a, double& out_b) {
            if(abs(a.x - b.x) < EPS) { return INF_SLOPE; }
            if(abs(a.y - b.y) < EPS) {
                out_b = a.y;
                return NO_SLOPE;
            }
            out_a = (a.y - b.y) / (a.x - b.x);
            out_b = a.y - out_a * a.x;
            return VALID_SLOPE;
        }
        // x 座標を渡した時に対応する y 座標を返します
        double GetY(double x) {
            double slope, intercept;
            // x = a の場合は適当な点を返す
            if(GetAB(slope, intercept) == INF_SLOPE) { return a.y; }
            return slope * x + intercept;
        }
        // y 座標を渡した時に対応する x 座標を返します
        double GetX(double y) {
            double slope, intercept;
            // y = b の場合は適当な点を返す
            if(GetAB(slope, intercept) == INF_SLOPE) { return a.x; }
            return (y - intercept) / slope;
        }
};
 
// 線分を表すクラス
// 直線と違い端点が定義できる場合はこちら
class Segment
{
    public:
        Point a, b;
        Segment() {};
        Segment(Point a, Point b) : a(a), b(b) {};
        // 中点を求める
        Point Center() { return Point((a.x + b.x) / 2, (a.y + b.y) / 2); }
        // 垂直二等分線を求める
        Line PerpBisector() {
            Point center = this->Center();
            return Line((a - center).Rotate90() + center, center);
        }
};
 
// 円を表すクラス
class Circle
{
    public:
        Point p;  // 中心
        double r; // 半径
 
        Circle() {};
        Circle(Point p, double r) : p(p), r(r) {};
};
 
// その他図形を表す型定義
typedef vector< Point > Polygon;            // 多角形
typedef vector< Segment > Segments;         // 線分集合
typedef vector< Line > Lines;               // 直線集合
typedef vector< Circle > Circles;           // 円集合
typedef pair< Point, Point > PointPoint;    // 2 点
 
// 点の進行方向を調べる
enum DotDir {
    Counterclockwise = 1,   // a -> b 反時計周りの方向に c
    Clockwise = -1,         // a -> b 時計周りの方向に c
    CAB = 2,                // c -> a -> b の順に並ぶ
    ABC = -2,               // a -> b -> c の順に並ぶ
    ACB = 0                 // a -> c -> b の順に並ぶ
};
// a -> b -> c の順に点をたどったときの進行方向 DotDir を返す