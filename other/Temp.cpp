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
template<typename T>
using prque = priority_queue<T,vector<T>>;
template<typename T>
using prquer = priority_queue<T,vector<T>,greater<T>>;
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
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define SZ(a) (int)((a).size())
#define EXIST(s,e) (find((s).begin(),(s).end(),(e))!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define SORTR(c) sort((c).rbegin(), (c).rend())
#define REVERSE(c) reverse((c).begin(),(c).end())
#define NEXP(a) next_permutation((a).begin(),(a).end())
#define AAI(a,b,c) (a).begin(),(a).end(), (b).begin(),(b).end(), inserter(c,(c).end())

#define FOR(i,a,b) for(auto i = decltype(b){a}, i##_r=(b); i<i##_r; i++)
#define REP(i,n) FOR(i,0,n)
#define FORR(i,a,b) for(auto i=decltype(b){b-1}, i##_l=(a); i>=i##_l; i--)
#define REPR(i,n) FORR(i,0,n)
#define CFOR(i,a,b) for(auto i = decltype(b){a}, i##_r=(b); i<=i##_r; i++)
#define CREP(i,n) CFOR(i,0,n)
#define SREP(i,n) CFOR(i,1,n)
#define CFORR(i,a,b) for(auto i=decltype(b){b}, i##_l=(a); i>=i##_l; i--)
#define CREPR(i,n) CFORR(i,0,n)
#define SREPR(i,n) CFORR(i,1,n)
#define BFOR(bit,a,b) for(LL bit=(a); bit<(1ll<<(b)); bit++)
#define BREP(bit,n) BFOR(bit,0,n)
#define EACH(ptr,c) for(auto ptr=(c).begin(); ptr!=(c).end(); )
#define EACHR(ptr,c) for(auto ptr=(c).rbegin(); ptr!=(c).rend(); )
#define PERM(c) for(bool c##per=1; c##per; c##per=NEXP(c))

constexpr double EPS = 1e-10;
constexpr double PI  = 3.141592653589793238462643383279;
constexpr int INF = numeric_limits<int>::max()/2;
constexpr LL LINF = numeric_limits<LL>::max()/3;
constexpr int RINF = numeric_limits<int>::min()/2;
constexpr LL RLINF = numeric_limits<LL>::min()/3;
constexpr LL MOD = 1e9+7;
constexpr LL MODD = 998244353;
constexpr int MAX = 510000;
constexpr LL TEN(int n) { return n? 10*TEN(n-1) : 1; };

#define ADD_OVERFLOW(a, b) __builtin_add_overflow_p (a, b, (decltype((a)+(b))) 0)
#define SUB_OVERFLOW(a, b) __builtin_sub_overflow_p (a, b, (decltype((a)+(b))) 0)
#define MUL_OVERFLOW(a, b) __builtin_mul_overflow_p (a, b, (decltype((a)+(b))) 0)

template<class T> inline T sqr(T x) { return x*x; }
inline bool Eq(double a, double b) { return fabs(b - a) < EPS; }
template<class T> inline T CEIL(T x, T y) { return (x+y-1)/y; }
inline int Pcnt(uint64_t x) { return __builtin_popcountll(x); }
template<typename T>
T mypow(T a, LL n, T m = 0, T e = 1){
  T res = e;
  while(n > 0){
    if(n&1){ res *= a; if(m) res %= m; }
    a *= a; n >>= 1; if(m) a %= m;
  }
  return res;
}

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename T>
T Vsum(vector<T> &v){ return reduce(v.begin(), v.end()); }
template<typename T>
T Vgcd(vector<T> &v){ return reduce(v.begin(), v.end(), T(0), [](auto&&a, auto&&b){ return gcd(a,b); }); }
template<typename T>
T Vlcm(vector<T> &v){ return reduce(v.begin(), v.end(), T(1), [](auto&&a, auto&&b){ return lcm(a,b); }); }

template<typename T> T Vmax(vector<T> &v){return *max_element(v.begin(), v.end()); }
template<typename T> T Vmin(vector<T> &v){return *min_element(v.begin(), v.end()); }
template<typename T> void Vadd(vector<T> &v, T a){for(auto&& x : v) x += a; }

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...)); }

template<typename T>
vector<tuple<T>> in_zip(vector<T> &v){
  vector<tuple<T>> vt(v.size());
  for(int i = 0; i < (int)v.size(); i++) vt[i] = make_tuple(v[i]);
  return vt;
}

template<typename T, typename... Ts>
auto in_zip(vector<T> &v, Ts&&... vs){
  auto vt = in_zip(v); auto vts = in_zip(vs...);
  vector res(v.size(), tuple_cat(vt[0], vts[0]));
  for(int i = 1; i < (int)v.size(); i++) res[i] = tuple_cat(vt[i], vts[i]);
  return res;
}

template<typename T>
vector<tuple<int, T>> in_enumerate(vector<T> &v){
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0);
  return in_zip(idx, v);
}

template<typename T, typename... Ts>
auto in_enumerate(vector<T> &v, Ts&&... vs){
  vector<int> idx(v.size()); iota(idx.begin(), idx.end(), 0);
  return in_zip(idx, v, vs...);
}

bool cYN(bool fl=true,bool fl2=false){cout << (fl?"Yes":"No") << endl; if(fl2){ exit(0); } return fl; }
bool CYN(bool fl=true,bool fl2=false){cout << (fl?"YES":"NO") << endl; if(fl2){ exit(0); } return fl; }
template<typename T = int>
void error(T t=-1,bool fl=true){cout << t << endl; if(fl){ exit(0); } }
template<class T> void COUT(T&& t){ cout << t << endl; }
template<class T,class... Ts>
void COUT(T&& t,Ts&&... ts){ cout << t << " "; COUT(ts...); }
void CIN() {}
template<class T,class... Ts> void CIN(T&& t,Ts&&... ts){ cin >> t; CIN(ts...); }

template< typename T1, typename T2 >
istream &operator>>(istream &is, pair< T1, T2 > &p) {
  is >> p.first >> p.second; return is;
}
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << p.first << " " << p.second; return os;
}
template< typename T >
istream &operator>>(istream &is, vector< T > &v) {
  for(auto&&in : v) is >> in;
  return is;
}
template< typename T >
ostream &operator<<(ostream &os, const vector< T > &v) {
  for(int i = 0; i < SZ(v); i++) os << v[i] << (i + 1 != SZ(v) ? " " : "");
  return os;
}

void Vcin([[maybe_unused]] int i) {}
template<class T, class... Ts>
void Vcin(int i, vector<T> &v, Ts&&... vs){ cin >> v[i]; Vcin(i, vs...); }
template<class T, class... Ts>
void Vcin(vector<T> &v,Ts&&... vs){ for(int i = 0; i < SZ(v); i++) Vcin(i, v, vs...); }

template< typename T >
void Vcout(const vector<T> &v, string sep = "\n", string en = "\n"){
  for(int i = 0; i < SZ(v); i++) cout << v[i] << (i + 1 != SZ(v) ? sep : en);
}

const vector<int> dx = {1,0,-1,0,1,1,-1,-1};
const vector<int> dy = {0,1,0,-1,1,-1,1,-1};

namespace debugger{
  template<typename T>
  void view(const T &a){ cout << a; }
  template<typename T1, typename T2>
  void view(const pair<T1, T2>& p){
    cout << "(" << p.first << ", " << p.second << ")";
  }
  template<typename T>
  void view(const vector<T>& v){
    cout << "{ ";
    for(int i = 0; i < SZ(v); i++) cout << v[i] << (i + 1 != SZ(v) ? ", " : "");
    cout << " }";
  }
  template<typename T>
  void view(const vector<vector<T>>& vv){
    cout << "{\n";
    for(auto&&v : vv){ cout << "\t"; view(v); cout << "\n"; }
    cout << "}";
  }
  template<typename T>
  void view(const set<T>& s){ view(vector<T>(s.begin(), s.end())); }
  template<typename T1, typename T2>
  void view(const map<T1, T2>& mp){
    cout << "{\n";
    for(auto&&[f,s] : mp) cout << "\t[" << f << "]: " << s << "\n";
    cout << "}";
  }
}

#ifdef _DEBUG
template<typename T>
void debug_out(T &&t) { debugger::view(t); cout << "\n"; }
template <typename T, typename... Ts>
void debug_out(T&& t, Ts&&... ts){ debugger::view(t); cout << ", "; debug_out(ts...); }

#define debug(...) do{ cout <<"L: "<<__LINE__<<" [ " << #__VA_ARGS__ << " ]: "; debug_out(__VA_ARGS__); }while(false)
#else
#define debug(...)

using int128 = __int128_t;

istream& operator>>(istream& is, __int128_t &a){
  string s; is >> s;
  __int128_t res = 0;
  for(auto&&c : s) if('0' <= c && c <= '9') res = 10*res + c-'0';
  a = res * (s[0]=='-' ? -1 : 1);
  return is;
}

ostream& operator<<(ostream& os, __int128_t &a){
  ostream::sentry s(os);
  if(s){
    __uint128_t tmp = a<0 ? -a : a;
    char buffer[128];
    char *d = std::end(buffer);
    do{
      --d;
      *d = "0123456789"[tmp%10];
      tmp /= 10;
    }while(tmp != 0);
    if(a < 0){
      --d; *d = '-';
    }
    int len = std::end(buffer) - d;
    if(os.rdbuf()->sputn(d, len) != len){
      os.setstate(ios_base::badbit);
    }
  }
  return os;
}

#endif

#pragma endregion



int main(){
  // cin.tie(0); ios::sync_with_stdio(false);
  cout << fixed << setprecision(12);


  return 0;
}