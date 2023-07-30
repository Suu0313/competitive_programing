#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_C"

#include <bits/stdc++.h>
using namespace std;

#include "math/geometry/Point.cpp"

int main() {
  cout << fixed << setprecision(12);
  
  Point<int> a, b; cin >> a >> b;

  int q; cin >> q;
  while(q--){
    Point<int> p; cin >> p;
    int c = iSP(a, b, p);

    if(c == geometry::CCW) cout << "COUNTER_CLOCKWISE\n";
    if(c == geometry::CW) cout << "CLOCKWISE\n";
    if(c == geometry::BAC) cout << "ONLINE_BACK\n";
    if(c == geometry::ABC) cout << "ONLINE_FRONT\n";
    if(c == geometry::ACB) cout << "ON_SEGMENT\n";
  }
}