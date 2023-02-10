#pragma once

template<typename T>
auto make_ref_vector(vector<T> &v, const vector<int> &idx){
  vector<reference_wrapper<T>> res;
  for(int i : idx) res.push_back(v[i]);
  return res;
}

template<typename T>
auto make_ref_vector(vector<T> &v, initializer_list<int> idx){
  return make_ref_vector(v, idx);
}

template<typename T>
auto make_ref_vector(vector<T> &v, const vector<bool> &use){
  vector<reference_wrapper<T>> res;
  int n = int(min(v.size(), use.size()));
  for(int i = 0; i < n; ++i){
    if(use[i]) res.push_back(v[i]);
  }
  return res;
}
