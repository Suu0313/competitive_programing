template<typename T>
struct Edge{
  int src, to;
  T cost;
  Edge(){}
  Edge(int to, T cost):src(-1),to(to), cost(cost) {}
  Edge(int src, int to, T cost):src(src),to(to), cost(cost) {}
  Edge &operator=(const int &x){
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
using edge = Edge<int>;
using VE = vector<edge>;
using VVE = vector<VE>;
