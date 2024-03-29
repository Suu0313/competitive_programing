#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_1_A"
#define ERROR 0.00000001

#include <bits/stdc++.h>
using namespace std;

#include "math/geometry/Geometry.cpp"

int main() {
  cout << fixed << setprecision(12);
  
  Line<double> l; cin >> l.a >> l.b;
  int q; cin >> q;
  while(q--){
    Point<double> p; cin >> p;
    cout << l.projection(p) << "\n";
  }
}
