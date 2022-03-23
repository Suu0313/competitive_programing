vector<vector<vector<bool>>> enumerate_n_ominos(int n){
  if(n < 1) return {};

  int xmid = n-1, xlen = n*2-1, ylen = n;
  vector<pair<int,int>> adj({{1, 0}, {0, 1}, {-1, 0}, {0, -1}});

  vector<vector<bool>> visited(xlen, vector<bool>(ylen));
  vector<vector<int>> order(xlen, vector<int>(ylen, -1));

  visited[xmid][0] = true; order[xmid][0] = 0;
  int norder = 1, remain = n - 1;

  vector<pair<int,int>> candidate;
  set<pair<int,int>> candidate_impl;
  stack<tuple<int,int,int,int>> histry;

  int xmx = xmid, xmn = xmid, ymx = 0, ymn = 0;

  auto remove_space = [&](const vector<vector<bool>> &mino){
    vector<vector<bool>> ret;
    for(int x = xmn; x <= xmx; ++x)
      ret.emplace_back(begin(mino[x])+ymn, begin(mino[x])+ymx+1);
    return ret;
  };

  vector<vector<vector<bool>>> ret;
  auto dfs = [&](auto&self, int x, int y) -> void {
    if(remain == 0){
      ret.push_back(remove_space(visited));
      return;
    }

    for(auto&&[dx, dy] : adj){
      int nx = x + dx, ny = y + dy;
      if(nx<0 || xlen<=nx || ny<0 || ylen<=ny) continue;
      if(ny == 0 && nx <= xmid) continue;
      if(order[nx][ny] != -1) continue;
      order[nx][ny] = norder++;
      histry.emplace(x, y, nx, ny);
      if(!candidate_impl.count({nx, ny})) candidate.emplace_back(nx, ny);
    }

    for(int i = 0, sz = int(candidate.size()); i < sz; ++i){
      auto[nx, ny] = candidate[i];
      if(order[nx][ny] <= order[x][y]) continue;

      visited[nx][ny] = true;
      candidate.erase(begin(candidate) + i);
      candidate_impl.erase({nx, ny});

      int pxmx = xmx, pxmn = xmn, pymx = ymx, pymn = ymn;

      --remain;
      xmx = max(xmx, nx); xmn = min(xmn, nx);
      ymx = max(ymx, ny); ymn = min(ymn, ny);
      self(self, nx, ny);
      xmx = pxmx, xmn = pxmn, ymx = pymx, ymn = pymn;

      while(!histry.empty()){
        auto[px, py, pnx, pny] = histry.top();
        if(px == nx && py == ny){
          order[pnx][pny] = -1;
          histry.pop();
        }else{
          break;
        }
      }
      ++remain;
      candidate.insert(begin(candidate) + i, {nx, ny});
      candidate_impl.emplace(nx, ny);
      visited[nx][ny] = false;
    }
  };
  dfs(dfs, xmid, 0);

  return ret;
}
