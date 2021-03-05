template<typename T>
vector<int> TopoSort(const vector<vector<T>> &G){
  vector<int> ans;
  int n = G.size();
  vector<int> ind(n,0);
  for(int i = 0; i < n; i++){
    for(auto e : G.at(i)){
      ind.at(e)++;
    }
  }
  queue<int> que;
  for(int i = 0; i < n; i++){
    if(ind.at(i)==0) que.push(i);
  }
  while(!que.empty()){
    int now = que.front(); que.pop();
    ans.emplace_back(now);
    for(auto e : G.at(now)){
      ind.at(e)--;
      if(ind.at(e)==0) que.emplace(e);
    }
  }
  return ans;
}
