template<typename T>
pair<vector<int>, vector<T>> compress(const vector<T> &v, int base = 0){
  int n = v.size();
  vector<int> idx(n); iota(idx.begin(), idx.end(), 0);
  sort(idx.begin(), idx.end(), [&](int i, int j){ return v[i] < v[j]; });
  vector<int> res(n, base);
  vector<T> dict(1, v[idx[0]]);

  for(int i = 1; i < n; i++){
    int a = idx[i-1], b = idx[i];
    if(v[a] == v[b]) res[b] = res[a];
    else{
      res[b] = res[a] + 1;
      dict.emplace_back(v[b]);
    }
  }

  return {res, dict};
}
