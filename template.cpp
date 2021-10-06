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
#define ALL(a)  begin(a), end(a)
#define RALL(a) rbegin(a), rend(a)
#define SORT(c) sort(begin(c), end(c))
#define SORTR(c) sort(rbegin(c), rend(c))

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
constexpr LL MASK(int l, int r) { return MASK(r) - MASK(l); }
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

template<typename Container>
constexpr int SZ(const Container &c){ return size(c); }
template<typename Container>
Container Rev(Container c){ reverse(begin(c), end(c)); return c; }
template<typename T = int>
vector<T> iota(int n, T e = 0){ vector<T> v(n); iota(begin(v), end(v), e); return v; }
template<typename Container>
Container Sort(Container c){ sort(begin(c), end(c)); return c; }
template<typename Container, class Compair>
Container Sort(Container c, const Compair &cmp){ sort(begin(c), end(c), cmp); return c; }
template<typename T>
vector<T> subvec(const vector<T> &v,  size_t pos = 0, size_t n = string::npos){
  assert(pos <= v.size()); n = min(n, v.size() - pos);
  return vector<T>(v.begin()+pos, v.begin()+pos+n);
}
template<typename Container>
Container Unique(Container c, bool sorted = false){
  if(!sorted) sort(begin(c), end(c));
  c.erase(unique(begin(c), end(c)), end(c));
  return c;
}
template<typename T>
vector<T> Concat(const vector<T> &a, const vector<T> &b){
  vector<T> res = a; res.reserve(a.size() + b.size());
  res.insert(end(res), begin(b), end(b));
  return res;
}
template<typename T, class Compair = less<T>>
vector<int> KeySort(const vector<T> &a, vector<int> idx, const Compair &cmp = Compair{}){
  sort(begin(idx), end(idx), [&](int i, int j){ return cmp(a[i], a[j]); });
  return idx;
}
template<typename T, class Compair = less<T>>
vector<int> KeySort(const vector<T> &a, const Compair &cmp = Compair{}){
  vector<int> idx(a.size()); iota(begin(idx), end(idx), 0);
  return KeySort<T, Compair>(a, idx, cmp);
}
template<typename T>
vector<T> Reorder(const vector<T> &a, const vector<int> &idx){
  int n = int(a.size());
  vector<T> res(n); for(int i = 0; i < n; ++i) res[i] = a[idx[i]];
  return res;
}
template<typename... Ts>
string format(const string &fmt, Ts... ts){
  size_t len = snprintf(nullptr, 0, fmt.c_str(), ts...);
  vector<char> buf(len + 1);
  snprintf(&buf[0], len + 1, fmt.c_str(), ts...);
  return string(buf.begin(), buf.end()-1);
}

#define WHOLE(some_of, n, i, ...) ([&]{ vector<int> index(n); iota(begin(index), end(index), 0); return some_of(begin(index), end(index) , [&](int i){ __VA_ARGS__; } );})()

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
