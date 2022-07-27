#pragma region mytemplates

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII; typedef pair<LL,LL> PLL;
typedef vector<int> VI; typedef vector<VI> VVI;
typedef vector<LL> VLL; typedef vector<VLL> VVLL;
typedef vector<bool> VB; typedef vector<VB> VVB;
typedef vector<double> VD; typedef vector<VD> VVD;
typedef vector<string> VS; typedef vector<VS> VVS;
typedef vector<char> VC; typedef vector<VC> VVC;
typedef vector<PII> VPII; typedef vector<PLL> VPLL;

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

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template<typename T> T accumulate(const vector<T> &v){ return accumulate(begin(v), end(v), T(0)); }
template<typename T>
T gcd(const vector<T> &v){ return accumulate(begin(v), end(v),T(0),[](auto&&a, auto&&b){ return gcd(a,b); }); }
template<typename T>
T lcm(const vector<T> &v){ return accumulate(begin(v), end(v),T(1),[](auto&&a, auto&&b){ return lcm(a,b); }); }
template<typename T> T max(const vector<T> &v){ return *max_element(begin(v), end(v)); }
template<typename T> T min(const vector<T> &v){ return *min_element(begin(v), end(v)); }

template<class T> vector<T> &operator++(vector<T> &v){ for(auto&&e : v){ ++e; } return v; }
template<class T> vector<T> &operator--(vector<T> &v){ for(auto&&e : v){ --e; } return v; }
template<class T1, class T2> pair<T1,T2> &operator++(pair<T1, T2> &p){ ++p.first, ++p.second; return p; }
template<class T1, class T2> pair<T1,T2> &operator--(pair<T1, T2> &p){ --p.first, --p.second; return p; }

template<typename T> vector<T> make_v(size_t a,T b){ return vector<T>(a, b); }
template<typename... Ts> auto make_v(size_t a,Ts... ts){ return vector(a,make_v(ts...)); }

template<typename T = int> vector<T> stov(const string &s, char c = '0'){
  vector<T> res(s.size());
  for(size_t i = 0; i < s.size(); ++i) res[i] = s[i] - c;
  return res;
}

vector<int> iota(int s, int t, int d){
  vector<int> idx;
  for(int i = s; (s <= i && i < t) || (t < i && i <= s); i += d) idx.push_back(i);
  return idx;
}
template<typename T = int> vector<T> iota(int n, T e = 0){ vector<T> v(n); iota(begin(v), end(v), e); return v; }
template<typename Container> constexpr int isz(const Container &c){ return size(c); }
template<typename Container> void reverse(Container &c){ reverse(begin(c), end(c));}
template<typename Container> Container reversed(Container c){ reverse(c); return c; }
template<typename Container> void sort(Container &c){ sort(begin(c), end(c)); }
template<typename Container> Container sorted(Container c){ sort(c); return c; }
template<typename Container, class Compair> void sort(Container &c, const Compair &cmp){ sort(begin(c), end(c), cmp); }
template<typename Container, class Compair> Container sorted(Container c, const Compair &cmp){ sort(c, cmp); return c; }
template<typename T>
vector<T> subvec(const vector<T> &v,  size_t pos = 0, size_t n = string::npos){
  assert(pos <= v.size()); n = min(n, v.size() - pos);
  return vector<T>(v.begin()+pos, v.begin()+pos+n);
}
template<typename Container> Container unique(Container c){ c.erase(unique(begin(c), end(c)), end(c)); return c; }
template<typename T>
vector<T> concat(const vector<T> &a, const vector<T> &b){
  vector<T> res = a; res.reserve(a.size() + b.size());
  res.insert(end(res), begin(b), end(b));
  return res;
}
template<typename T, class Compair = less<T>>
vector<int> sorted_idx(const vector<T> &a, vector<int> idx, const Compair &cmp = Compair{}){
  sort(begin(idx), end(idx), [&](int i, int j){ return cmp(a[i], a[j]); });
  return idx;
}
template<typename T, class Compair = less<T>>
vector<int> sorted_idx(const vector<T> &a, const Compair &cmp = Compair{}){
  vector<int> idx(a.size()); iota(begin(idx), end(idx), 0);
  return sorted_idx<T, Compair>(a, idx, cmp);
}
template<typename T>
vector<T> re_order(const vector<T> &a, const vector<int> &idx){
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
template<typename Container>
string join(const Container&v, const string &sep = "", const string &en = ""){
  stringstream s;
  for(size_t i = 0; i < size(v); i++) s << v[i] << (i+1 != size(v) ? sep : en);
  return s.str();
}
template<typename T>
vector<T> preffix_sum(const vector<T> &v){
  int n = int(v.size());
  vector<T> ps(n + 1, 0);
  for(int i = 0; i < n; ++i) ps[i + 1] = ps[i] + v[i];
  return ps;
}
template<typename T>
vector<T> get_pow_vector(int n, T p){
  vector<T> res(n + 1, 1);
  for(int i = 0; i < n; ++i) res[i + 1] = res[i] * p;
  return res;
}
template<class Container> auto myref(Container &c, size_t i){ return ref(c[i]); }
template<class Container> auto myref(Container &&c, size_t i){ return c[i]; }

template<class... Cs>
auto in_zip(Cs&&... cs){
  vector<tuple<conditional_t<is_lvalue_reference_v<Cs>, add_lvalue_reference_t<typename remove_reference_t<Cs>::value_type>, typename remove_reference_t<Cs>::value_type>...>> v;
  size_t n = min({size(cs)...}); v.reserve(n);
  for(size_t i = 0; i < n; i++) v.emplace_back(myref(std::forward<Cs>(cs), i)...);
  return v;
}

template<class... Cs>
auto enumerate(Cs&&... cs){
  auto iota_impl = [&]{ vector<int> idx(min({size(cs)...})); iota(begin(idx), end(idx), 0); return idx; };
  return in_zip(iota_impl(), cs...);
}

bool cYN(bool fl=true,bool fl2=false){cout << (fl?"Yes":"No") << '\n'; if(fl2){ exit(0); } return fl; }
bool CYN(bool fl=true,bool fl2=false){cout << (fl?"YES":"NO") << '\n'; if(fl2){ exit(0); } return fl; }
template<typename T = int> void error(T t=-1,bool fl=true){cout << t << '\n'; if(fl){ exit(0); } }
void COUT(){ cout << "\n"; }
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
  for(auto&&in : v){ is >> in; } return is;
}
template< typename T > ostream &operator<<(ostream &os, const vector<T> &v) {
  for(size_t i = 0; i < v.size(); i++) os << v[i] << (i + 1 != v.size() ? " " : "");
  return os;
}

template<typename... Ts, size_t... Is>
ostream &tuple_output_impl(ostream &os, const tuple<Ts...> &tp, index_sequence<Is...>){
  [[maybe_unused]] bool a[] = {(os << get<Is>(tp) << " ", false)...};
  return os << get<tuple_size<tuple<Ts...>>::value-1>(tp);
}

template<typename... Ts>
ostream &operator<<(ostream &os, const tuple<Ts...> &tp){
  return tuple_output_impl(os, tp, make_index_sequence<tuple_size<tuple<Ts...>>::value-1>());
}

void Vcin([[maybe_unused]] size_t i) {}
template<class T, class... Ts> void Vcin(size_t i, vector<T> &v, Ts&&... vs){ cin >> v[i]; Vcin(i, vs...); }
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
