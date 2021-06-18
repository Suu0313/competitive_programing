#pragma region mytemplates

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL,LL> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
#define umap unordered_map
#define uset unordered_set
#define umset unordered_multiset

template<typename T> struct Queue : queue<T>{
  using queue<T>::queue;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->front(); this->pop(); return res; }
  void clear(){ (*this) = Queue(); }
};
template<typename T> struct Stack : stack<T>{
  using stack<T>::stack;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->top(); this->pop(); return res; }
  void clear(){ (*this) = Stack(); }
};
template<typename T, typename Container = vector<T>, typename Compare = less<typename Container::value_type>>
struct prque : priority_queue<T, Container, Compare> {
  using priority_queue<T, Container, Compare>::priority_queue;
  explicit operator bool() const { return !(*this).empty(); }
  T Pop(){ T res = this->top(); this->pop(); return res; }
  void clear(){ (*this) = prque(); }
};
template<typename Container, typename Compare>
prque(Compare, Container) -> prque<typename Container::value_type, Container, Compare>;
template<typename T> using prquer = prque<T, vector<T>, greater<T>>;

template<typename T> struct Deque : deque<T>{
  using deque<T>::deque;
  explicit operator bool() const { return !(*this).empty(); }
  T Popf(){ T res = this->front(); this->pop_front(); return res; }
  T Popb(){ T res = this->back(); this->pop_back(); return res; }
};

template<typename T>
struct Set : set<T> {
  using set<T>::set;
  explicit operator bool() const { return !(*this).empty(); }
  Set operator|(const Set &s) const {
    Set res;
    set_union((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set &operator|=(const Set &s){
    for(auto&&e : s) this->insert(e);
    return (*this);
  }
  Set operator&(const Set &s) const {
    Set res;
    set_intersection((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set operator&=(const Set &s){ return (*this) = (*this) & s; }
  Set operator^(const Set &s) const {
    Set res;
    set_symmetric_difference((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set &operator^=(const Set &s){
    for(auto&&e : s){
      if(this->exist(e)) this->erase(e);
      else this->insert(e);
    }
    return (*this);
  }
  Set operator-(const Set &s) const {
    Set res;
    set_difference((*this).begin(), (*this).end(), s.begin(), s.end(), inserter(res, res.end()));
    return res;
  }
  Set &operator-=(const Set &s){
    for(auto&&e : s) this->erase(e);
    return (*this);
  }
  const T &operator[](int k) const {
    if(k >= 0) return *std::next(this->begin(), k);
    else return *std::prev(this->end(), -k);
  }
  bool exist(const T &x) const { return (*this).find(x) != (*this).end(); }
};

#define LB lower_bound
#define UB upper_bound
#define FI first
#define SE second
#define EF emplace_front
#define EB emplace_back
#define PF push_front
#define PB push_back
#define POF pop_front
#define POB pop_back
#define MP make_pair
#define MT make_tuple
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SZ(a) (int)((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define SORTR(c) sort((c).rbegin(), (c).rend())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define AAI(a,b,c) (a).begin(),(a).end(), (b).begin(),(b).end(), inserter((c),(c).end())
#define UNIQUE(v) (v).erase(unique((v).begin(),(v).end()), (v).end())

#define FOR(i,a,b) for(decay_t<decltype(b)> i=(a), i##_r=(b); i<i##_r; i++)
#define REP(i,n) FOR(i,0,n)
#define FORR(i,a,b) for(decay_t<decltype(b)> i=(b)-1, i##_l=(a); i>=i##_l; i--)
#define REPR(i,n) FORR(i,0,n)
#define CFOR(i,a,b) for(decay_t<decltype(b)> i=(a), i##_r=(b); i<=i##_r; i++)
#define CREP(i,n) CFOR(i,0,n)
#define SREP(i,n) CFOR(i,1,n)
#define CFORR(i,a,b) for(decay_t<decltype(b)> i=(b), i##_l=(a); i>=i##_l; i--)
#define CREPR(i,n) CFORR(i,0,n)
#define SREPR(i,n) CFORR(i,1,n)
#define BFOR(bit,a,b) for(long long bit=(a); bit<(1ll<<(b)); bit++)
#define BREP(bit,n) BFOR(bit,0,n)

#define OVERLOAD4(a,b,c,d,name,...) name
#define EACH1(a, v) for(auto&&a : v)
#define EACH2(a,b, v) for(auto&&[a,b] : v)
#define EACH3(a,b,c, v) for(auto&&[a,b,c] : v)
#define EACH(...) OVERLOAD4(__VA_ARGS__, EACH3, EACH2, EACH1)(__VA_ARGS__)

#define elif else if
#define unless(a) if(!(a))

constexpr double EPS = 1e-10;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr LL LINF = numeric_limits<LL>::max()/3;
constexpr LL MOD = 1e9+7;
constexpr LL MODD = 998244353;
constexpr LL TEN(int n) { return n? 10*TEN(n-1) : 1; }
constexpr LL MASK(int n) { return (1ll << n)-1; }
constexpr bool BITAT(LL bit, int n){ return (bit>>n) & 1; }

#define ADD_OVERFLOW(a, b) __builtin_add_overflow_p (a, b, (decltype(a)) 0)
#define SUB_OVERFLOW(a, b) __builtin_sub_overflow_p (a, b, (decltype(a)) 0)
#define MUL_OVERFLOW(a, b) __builtin_mul_overflow_p (a, b, (decltype(a)) 0)

template<typename T>
T ADD(const T &a, const T &b, const T &lim = numeric_limits<T>::max()){
  if(ADD_OVERFLOW(a,b)){ return lim; } return min(a+b, lim);
}
template<typename T>
T SUB(const T &a, const T &b, const T &lim = numeric_limits<T>::lowest()){
  if(SUB_OVERFLOW(a,b)){ return lim; } return max(a-b, lim);
}
template<typename T>
T MUL(const T &a, const T &b, const T &lim = numeric_limits<T>::max()){
  if(MUL_OVERFLOW(a,b)){ return lim; } return min(a*b, lim);
}

template<class T> constexpr T Sqr(T x) { return x*x; }
inline bool Eq(double a, double b) { return fabs(b - a) < EPS; }
inline int Pcnt(unsigned long long x) { return __builtin_popcountll(x); }
template<class T> constexpr T Ceil(T x, T y) {
  if(y < 0) x = -x, y = -y;
  if(x >= 0) return (x + y - 1) / y;
  return x / y;
}
template<class T> constexpr T Floor(T x, T y) {
  if(y < 0) x = -x, y = -y;
  if(x >= 0) return x / y;
  return (x - y + 1) / y;
}
template<typename T>
T ModInv(T a, T m){
  T b = m, u= 1, v = 0;
  while(b){
    T t = a/b;
    a -= t*b; swap(a,b);
    u -= t*v; swap(u,v);
  }
  u %= m; if(u<0) u+= m;
  return u;
}
template<typename T>
T Pow(T a, LL n, T m = 0, T e = 1){
  if(n < 0){ assert(m != 0); return ModInv(Pow(a, -n, m, e), m); }
  T res = e;
  while(n > 0){ if(n&1){ res *= a; if(m) res %= m; } a *= a; n >>= 1; if(m) a %= m; }
  return res;
}
uint64_t Sqrt(uint64_t x){
  uint64_t res = 0, over = 1;
  while(over*over <= x) over <<= 1;
  while(over-res > 1){
    uint64_t wj = res + ((over-res) >> 1);
    ((wj*wj <= x) ? res : over) = wj;
  }
  return res;
}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename T>
T Sum(const vector<T> &v){ return reduce(v.begin(),v.end()); }
template<typename T>
T gcd(const vector<T> &v){ return reduce(v.begin(),v.end(),T(0),[](auto&&a, auto&&b){ return gcd(a,b); }); }
template<typename T>
T lcm(const vector<T> &v){ return reduce(v.begin(),v.end(),T(1),[](auto&&a, auto&&b){ return lcm(a,b); }); }

template<typename T> T max(const vector<T> &v){ return *max_element(v.begin(), v.end()); }
template<typename T> T min(const vector<T> &v){ return *min_element(v.begin(), v.end()); }

template<class T> vector<T> &operator++(vector<T> &v){ for(auto&&e : v){ ++e; } return v; }
template<class T> vector<T> &operator--(vector<T> &v){ for(auto&&e : v){ --e; } return v; }
template<class T1, class T2> pair<T1,T2> &operator++(pair<T1, T2> &p){ ++p.first, ++p.second; return p; }
template<class T1, class T2> pair<T1,T2> &operator--(pair<T1, T2> &p){ --p.first, --p.second; return p; }

template<typename T> vector<T> make_v(size_t a,T b){ return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a,Ts... ts){ return vector(a,make_v(ts...)); }

template<typename T> valarray<T> make_va(size_t a,T b){ return valarray<T>(b, a); }
template<typename... Ts> auto make_va(size_t a,Ts... ts){ return valarray(make_va(ts...), a); }

template<typename T>
vector<tuple<T>> Zip(vector<T> &v){
  vector<tuple<T>> vt(v.size());
  for(size_t i = 0; i < v.size(); i++) vt[i] = make_tuple(v[i]);
  return vt;
}
template<typename T, typename... Ts>
auto Zip(vector<T> &v, Ts&&... vs){
  auto vt = Zip(v); auto vts = Zip(vs...);
  size_t m = min(vt.size(), vts.size());
  auto te = decltype(vt)(1)[0]; auto tse = decltype(vts)(1)[0];
  vector res(m, tuple_cat(te, tse));
  for(size_t i = 0; i < m; i++) res[i] = tuple_cat(vt[i], vts[i]);
  return res;
}

template<typename T>
vector<tuple<int, T>> Enumerate(vector<T> &v){
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0);
  return Zip(idx, v);
}
template<typename T, typename... Ts>
auto Enumerate(vector<T> &v, Ts&&... vs){
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0);
  return Zip(idx, v, vs...);
}

template<typename Container>
Container Rev(Container c){reverse(c.begin(), c.end()); return c; }
template<typename T = int>
vector<T> iota(int n, T e = 0){ vector<T> res(n); iota(res.begin(), res.end(), e); return res; }
template<typename Container>
Container Sort(Container c){ sort(c.begin(), c.end()); return c; }
template<typename Container, class Compair>
Container Sort(Container c, const Compair &cmp){ sort(c.begin(), c.end(), cmp); return c; }
template<typename T>
vector<T> subvec(const vector<T> &v,  size_t pos = 0, size_t n = string::npos){
  assert(pos <= v.size()); n = min(n, v.size() - pos);
  return vector<T>(v.begin()+pos, v.begin()+pos+n);
}

template<typename... Ts>
string format(const string &fmt, Ts... ts){
  size_t len = snprintf(nullptr, 0, fmt.c_str(), ts...);
  vector<char> buf(len + 1);
  snprintf(&buf[0], len + 1, fmt.c_str(), ts...);
  return string(buf.begin(), buf.end()-1);
}

bool cYN(bool fl=true,bool fl2=false){cout << (fl?"Yes":"No") << '\n'; if(fl2){ exit(0); } return fl; }
bool CYN(bool fl=true,bool fl2=false){cout << (fl?"YES":"NO") << '\n'; if(fl2){ exit(0); } return fl; }
template<typename T = int> void error(T t=-1,bool fl=true){cout << t << '\n'; if(fl){ exit(0); } }
template<class T> void COUT(T&& t){ cout << t << '\n'; }
template<class T,class... Ts> void COUT(T&& t,Ts&&... ts){ cout << t << " "; COUT(ts...); }
template<class... Ts> void CIN(Ts&&... ts){ (cin >> ... >> ts); }
#define INPUT(T, ...) T __VA_ARGS__; CIN(__VA_ARGS__)

template< typename T1, typename T2 > istream &operator>>(istream &is, pair<T1, T2> &p) {
  is >> p.first >> p.second; return is;
}
template< typename T1, typename T2 > ostream &operator<<(ostream &os, const pair<T1, T2>& p) {
  os << p.first << " " << p.second; return os;
}
template< typename T > istream &operator>>(istream &is, vector<T> &v) {
  for(auto&&in : v) is >> in;
  return is;
}
template< typename T > ostream &operator<<(ostream &os, const vector<T> &v) {
  for(size_t i = 0; i < v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : "");
  return os;
}

void Vcin([[maybe_unused]] size_t i) {}
template<class T, class... Ts>
void Vcin(size_t i, vector<T> &v, Ts&&... vs){ cin >> v[i]; Vcin(i, vs...); }
template<class T, class... Ts>
void Vcin(vector<T> &v,Ts&&... vs){ for(size_t i = 0; i < v.size(); i++) Vcin(i, v, vs...); }

template< typename T >
void Vcout(const vector<T> &v, const string &sep = "\n", const string &en = "\n"){
  for(size_t i = 0; i < v.size(); i++) cout << v[i] << (i+1 != v.size() ? sep : en);
}

constexpr int dx[] = {1,0,-1,0,1,1,-1,-1}, dy[] = {0,1,0,-1,1,-1,1,-1};

#pragma endregion





int main(){
  // cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);




  return 0;
}
