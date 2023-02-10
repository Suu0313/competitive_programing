#pragma once

struct GridGraph{
  int h, w;
  vector<pair<int, int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  GridGraph() = default;
  GridGraph(int h, int w): h(h), w(w) {}
  GridGraph(int h, int w, vector<pair<int, int>> delta): h(h), w(w), delta(delta) {}
  GridGraph(int h, int w, vector<int> dx, vector<int> dy): h(h), w(w), delta(dx.size()) {
    for(size_t i = 0; i != delta.size(); ++i){
      delta[i] = make_pair(dx[i], dy[i]);
    }
  }

  vector<pair<int, int>> adj(int i, int j) const {
    vector<pair<int, int>> ps;
    for(const auto [dx, dy] : delta){
      int x = i + dx, y = j + dy;
      if(x < 0 || h <= x || y < 0 || w <= y) continue;
      ps.emplace_back(x, y);
    }
    return ps;
  }

  template<class F>
  vector<vector<int>> bfs(int si, int sj, const F &can_move) const {
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[si][sj] = 0;
    queue<pair<int, int>> qu; qu.emplace(si, sj);
    while(!qu.empty()){
      auto[i, j] = qu.front(); qu.pop();
      for(const auto[x, y] : adj(i, j)){
        if(dist[x][y] != -1) continue;
        if(!can_move(x, y)) continue;
        dist[x][y] = dist[i][j] + 1;
        qu.emplace(x, y);
      }
    }
    return dist;
  }

  template<typename T>
  vector<vector<int>> bfs_sp(int si, int sj, const vector<vector<T>> space, const T& sp = 0) const {
    return bfs(si, sj, [&](int i, int j){ return space[i][j] == sp; });
  }

  template<typename T>
  vector<vector<int>> bfs_bl(int si, int sj, const vector<vector<T>> block, const T& bl = 1) const {
    return bfs(si, sj, [&](int i, int j){ return block[i][j] != bl; });
  }

  vector<vector<int>> bfs_sp(int si, int sj, const vector<string> space, char sp = '.') const {
    return bfs(si, sj, [&](int i, int j){ return space[i][j] == sp; });
  }

  vector<vector<int>> bfs_bl(int si, int sj, const vector<string> block, char bl = '#') const {
    return bfs(si, sj, [&](int i, int j){ return block[i][j] != bl; });
  }
};
