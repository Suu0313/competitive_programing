#pragma once

#include "./Formalpowerseries.cpp"

#include "./multipoint_evaluation.cpp"


template<typename T>
Formalpowerseries<T> polynomial_interpolation(const vector<T> &xs, const vector<T> &ys){
  using fps = Formalpowerseries<T>;
  int n = int(xs.size());
  
  queue<fps> fs;
  for(auto&&x : xs) fs.push({-x, 1});
  while(int(fs.size()) > 1){
    fps f = fs.front(); fs.pop();
    fs.push(f * fs.front()); fs.pop();
  }
  fps g = fs.front();
  vector<T> dys = multipoint_evaluation(g.diff(), xs);
  
  queue<pair<fps, fps>> qu;
  for(int i = 0; i < n; ++i){
    qu.emplace(fps{ys[i] / dys[i]}, fps{-xs[i], 1});
  }
  while(int(qu.size()) > 1){
    auto[f1, g1] = qu.front(); qu.pop();
    auto[f2, g2] = qu.front(); qu.pop();
    qu.emplace(f1 * g2 + f2 * g1, g1 * g2);
  }
  auto[f1, g1] = qu.front();
  return (g * f1 * g1.inv()).pre(n);
}
