#pragma once

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
