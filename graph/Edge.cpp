template<typename T>
struct edge{
  int src, to;
  T cost;
  edge(){}
  edge(int to, T cost):src(-1),to(to), cost(cost) {}
  edge(int src, int to, T cost):src(src),to(to), cost(cost) {}
  edge &operator=(const int &x){
    to = x;
    return *this;
  }
  operator int() const { return to; }
};
using Edge = edge<LL>;
using VE = vector<Edge>;
using VVE = vector<VE>;
