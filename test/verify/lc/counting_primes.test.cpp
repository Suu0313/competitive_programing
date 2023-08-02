#define PROBLEM "https://judge.yosupo.jp/problem/counting_primes"

#include <bits/stdc++.h>
using namespace std;

#include "math/prime/count_primes.cpp"

int main(){
  int64_t n; cin >> n;
  cout << count_primes(n) << "\n";
}