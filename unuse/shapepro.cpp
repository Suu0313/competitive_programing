
// a == b �Ȃ� true (�덷�Ɋ��e)
inline bool Eq(double a, double b) { return fabs(b - a) < EPS; }
 
// ���[�N���b�h���ʏ�̓_��\���\����
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
 
        // �傫���̓���Ԃ��܂�
        double Norm() { return x * x + y * y; }
        // �t����(y = 0 ����� rad �� [-��, ��] �͈̔͂ŕ\��������)��Ԃ��܂�
        double Atan2() { return atan2(y, x); }
        // �傫����Ԃ��܂�
        double Abs() { return sqrt(Norm()); }
        // ���_�𒆐S�Ƃ��Ĕ����v����� theta (rad)�x��]�������W��Ԃ��܂�
        Point Rotate(double theta) { return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y); }
        // ���_�𔽎��v����� ��/2 ��]�������W��Ԃ��܂�
        Point Rotate90() { return Point(-y, x); }
};
 
// 2 �_�̊O��
double Cross(const Point &a, const Point &b) { return a.x * b.y - a.y * b.x; }
// 2 �_�̓���
double Dot(const Point &a, const Point &b) { return a.x * b.x + a.y * b.y; }
// ���W�A�����p�x��
double RadianToDegree(double r) { return (r * 180.0 / acos(-1)); }
// �p�x�����W�A����
double DegreeToRadian(double d) { return (d * acos(-1) / 180.0); }
// a->b->c �Ƃ��ǂ����Ƃ��� b �̊p�x(���W�A�� [0, ��])
double GetAngle(const Point &a, const Point &b, const Point &c)
{
  const Point v = a - b, w = c - b;
  double alpha = atan2(v.y, v.x), beta = atan2(w.y, w.x);
  if(alpha > beta) { swap(alpha, beta); }
  double theta = (beta - alpha);
  return min(theta, 2 * acos(-1) - theta);
}
 
// ������\���N���X
class Line
{
    public:
        Point a, b;
    public:
        Line() {};
        Line(Point a, Point b) : a(a), b(b) {};
        // Ax + By = C �Ƃ��������^����ꂽ�Ƃ��̒�����̔C�ӂ� 2 �_��ۑ�
        Line(double A, double B, double C)
        {
            if(Eq(A, 0)) { a = Point(0, C / B); b = Point(1, C / B); }
            else if(Eq(B, 0)) { a = Point(C / A, 0); b = Point(C / A, 1); }
            else { a = Point(0, C / B); b = Point(C / A, 0); }
        }
        // �X���Ƃ̎擾
        enum LineResult {
            INF_SLOPE,  // �X�������̃O���t (x = n �̃O���t)
            NO_SLOPE,   // �ؕЂ݂̂̃O���t (y = b �̃O���t)
            VALID_SLOPE // �X���ƐؕЂ̂���O���t
        };
        // out_a �ɌX�����A out_b �ɐؕЂ��A�Ԃ�l�Ƃ��� LineResult ���Ԃ�
        // INF_SLOPE �̎��� out_b �� x = n �� n ������
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
        // x ���W��n�������ɑΉ����� y ���W��Ԃ��܂�
        double GetY(double x) {
            double slope, intercept;
            // x = a �̏ꍇ�͓K���ȓ_��Ԃ�
            if(GetAB(slope, intercept) == INF_SLOPE) { return a.y; }
            return slope * x + intercept;
        }
        // y ���W��n�������ɑΉ����� x ���W��Ԃ��܂�
        double GetX(double y) {
            double slope, intercept;
            // y = b �̏ꍇ�͓K���ȓ_��Ԃ�
            if(GetAB(slope, intercept) == INF_SLOPE) { return a.x; }
            return (y - intercept) / slope;
        }
};
 
// ������\���N���X
// �����ƈႢ�[�_����`�ł���ꍇ�͂�����
class Segment
{
    public:
        Point a, b;
        Segment() {};
        Segment(Point a, Point b) : a(a), b(b) {};
        // ���_�����߂�
        Point Center() { return Point((a.x + b.x) / 2, (a.y + b.y) / 2); }
        // �����񓙕��������߂�
        Line PerpBisector() {
            Point center = this->Center();
            return Line((a - center).Rotate90() + center, center);
        }
};
 
// �~��\���N���X
class Circle
{
    public:
        Point p;  // ���S
        double r; // ���a
 
        Circle() {};
        Circle(Point p, double r) : p(p), r(r) {};
};
 
// ���̑��}�`��\���^��`
typedef vector< Point > Polygon;            // ���p�`
typedef vector< Segment > Segments;         // �����W��
typedef vector< Line > Lines;               // �����W��
typedef vector< Circle > Circles;           // �~�W��
typedef pair< Point, Point > PointPoint;    // 2 �_
 
// �_�̐i�s�����𒲂ׂ�
enum DotDir {
    Counterclockwise = 1,   // a -> b �����v����̕����� c
    Clockwise = -1,         // a -> b ���v����̕����� c
    CAB = 2,                // c -> a -> b �̏��ɕ���
    ABC = -2,               // a -> b -> c �̏��ɕ���
    ACB = 0                 // a -> c -> b �̏��ɕ���
};
// a -> b -> c �̏��ɓ_�����ǂ����Ƃ��̐i�s���� DotDir ��Ԃ�