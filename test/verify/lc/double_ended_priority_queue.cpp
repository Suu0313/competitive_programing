#define PROBLEM "https://judge.yosupo.jp/problem/double_ended_priority_queue"

#include <bits/stdc++.h>
using namespace std;

#include "datastructure/heap/DoubleEndedPriorityQueue.cpp"

int main(){
  int n, q; cin >> n >> q;
  vector<int> s(n); for(int &e : s) cin >> e;
  DoubleEndedPriorityQueue<int> pq(s);

  while(q--){
    int t; cin >> t;
    if(t == 0){
      int x; cin >> x; pq.push(x);
    }

    if(t == 1) cout << pq.get_min() << "\n", pq.pop_min();
    if(t == 2) cout << pq.get_max() << "\n", pq.pop_max();
  }
}