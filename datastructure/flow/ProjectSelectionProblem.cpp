#pragma once

#include "./MaximumFlow.cpp"

template<typename T>
struct ProjectSelectionProblem{
  int n, s, t;
  Dinic<T> dinic;
  vector<T> theta0, theta1;
  unordered_map<int64_t, array<T, 4>> phi;
  T res = 0;

  ProjectSelectionProblem() = default;
  ProjectSelectionProblem(int n): n(n), s(n + 1), t(s + 1), dinic(t + 1), theta0(n), theta1(n) {}


  int64_t f(int i, int j) const { return int64_t(i) * n + j; }
  pair<int, int> f(int64_t x) const { return {x/n, x%n}; }

  void add_theta(int i, bool b, const T &x){
    if(b) theta1[i] += x;
    else theta0[i] += x;
  }

  void add_phi(int i, int j, bool bi, bool bj, const T &x){
    if(i > j) swap(i, j), swap(bi, bj);
    int64_t ij = f(i, j);
    if(phi.find(ij) == phi.end()) phi[ij] = {0, 0, 0, 0};
    phi[ij][int(bi) << 1 | bj] += x;
  }

  T solve(){
    for(auto&[p, v] : phi){
      auto[i, j] = f(p);
      res += v[0];
      add_theta(i, 1, v[2] - v[0]);
      add_theta(j, 1, v[3] - v[2]);
      T x = v[1] + v[2] - v[0] - v[3];
      if(x < 0){
        cerr << "must be submodular function" << endl;
        assert(false);
      }
      if(x > 0) dinic.add_edge(i, j, x);
    }
    for(int i = 0; i < n; ++i){
      if(theta1[i] == theta0[i]){
        res += theta0[i];
      }else if(theta0[i] < theta1[i]){
        dinic.add_edge(s, i, theta1[i] - theta0[i]);
        res += theta0[i];
      }else{
        dinic.add_edge(i, t, theta0[i] - theta1[i]);
        res += theta1[i];
      }
    }
    return res + dinic.flow(s, t);
  }
};
