---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/enumerate_n_ominos.cpp\"\n\r\nvector<vector<vector<bool>>>\
    \ enumerate_n_ominos(int n){\r\n  if(n < 1) return {};\r\n\r\n  int xmid = n-1,\
    \ xlen = n*2-1, ylen = n;\r\n  vector<pair<int,int>> adj({{1, 0}, {0, 1}, {-1,\
    \ 0}, {0, -1}});\r\n\r\n  vector<vector<bool>> visited(xlen, vector<bool>(ylen));\r\
    \n  vector<vector<int>> order(xlen, vector<int>(ylen, -1));\r\n\r\n  visited[xmid][0]\
    \ = true; order[xmid][0] = 0;\r\n  int norder = 1, remain = n - 1;\r\n\r\n  vector<pair<int,int>>\
    \ candidate;\r\n  set<pair<int,int>> candidate_impl;\r\n  stack<tuple<int,int,int,int>>\
    \ histry;\r\n\r\n  int xmx = xmid, xmn = xmid, ymx = 0, ymn = 0;\r\n\r\n  auto\
    \ remove_space = [&](const vector<vector<bool>> &mino){\r\n    vector<vector<bool>>\
    \ ret;\r\n    for(int x = xmn; x <= xmx; ++x)\r\n      ret.emplace_back(begin(mino[x])+ymn,\
    \ begin(mino[x])+ymx+1);\r\n    return ret;\r\n  };\r\n\r\n  vector<vector<vector<bool>>>\
    \ ret;\r\n  auto dfs = [&](auto&self, int x, int y) -> void {\r\n    if(remain\
    \ == 0){\r\n      ret.push_back(remove_space(visited));\r\n      return;\r\n \
    \   }\r\n\r\n    for(auto&&[dx, dy] : adj){\r\n      int nx = x + dx, ny = y +\
    \ dy;\r\n      if(nx<0 || xlen<=nx || ny<0 || ylen<=ny) continue;\r\n      if(ny\
    \ == 0 && nx <= xmid) continue;\r\n      if(order[nx][ny] != -1) continue;\r\n\
    \      order[nx][ny] = norder++;\r\n      histry.emplace(x, y, nx, ny);\r\n  \
    \    if(!candidate_impl.count({nx, ny})) candidate.emplace_back(nx, ny);\r\n \
    \   }\r\n\r\n    for(int i = 0, sz = int(candidate.size()); i < sz; ++i){\r\n\
    \      auto[nx, ny] = candidate[i];\r\n      if(order[nx][ny] <= order[x][y])\
    \ continue;\r\n\r\n      visited[nx][ny] = true;\r\n      candidate.erase(begin(candidate)\
    \ + i);\r\n      candidate_impl.erase({nx, ny});\r\n\r\n      int pxmx = xmx,\
    \ pxmn = xmn, pymx = ymx, pymn = ymn;\r\n\r\n      --remain;\r\n      xmx = max(xmx,\
    \ nx); xmn = min(xmn, nx);\r\n      ymx = max(ymx, ny); ymn = min(ymn, ny);\r\n\
    \      self(self, nx, ny);\r\n      xmx = pxmx, xmn = pxmn, ymx = pymx, ymn =\
    \ pymn;\r\n\r\n      while(!histry.empty()){\r\n        auto[px, py, pnx, pny]\
    \ = histry.top();\r\n        if(px == nx && py == ny){\r\n          order[pnx][pny]\
    \ = -1;\r\n          histry.pop();\r\n        }else{\r\n          break;\r\n \
    \       }\r\n      }\r\n      ++remain;\r\n      candidate.insert(begin(candidate)\
    \ + i, {nx, ny});\r\n      candidate_impl.emplace(nx, ny);\r\n      visited[nx][ny]\
    \ = false;\r\n    }\r\n  };\r\n  dfs(dfs, xmid, 0);\r\n\r\n  return ret;\r\n}\r\
    \n"
  code: "#pragma once\r\n\r\nvector<vector<vector<bool>>> enumerate_n_ominos(int n){\r\
    \n  if(n < 1) return {};\r\n\r\n  int xmid = n-1, xlen = n*2-1, ylen = n;\r\n\
    \  vector<pair<int,int>> adj({{1, 0}, {0, 1}, {-1, 0}, {0, -1}});\r\n\r\n  vector<vector<bool>>\
    \ visited(xlen, vector<bool>(ylen));\r\n  vector<vector<int>> order(xlen, vector<int>(ylen,\
    \ -1));\r\n\r\n  visited[xmid][0] = true; order[xmid][0] = 0;\r\n  int norder\
    \ = 1, remain = n - 1;\r\n\r\n  vector<pair<int,int>> candidate;\r\n  set<pair<int,int>>\
    \ candidate_impl;\r\n  stack<tuple<int,int,int,int>> histry;\r\n\r\n  int xmx\
    \ = xmid, xmn = xmid, ymx = 0, ymn = 0;\r\n\r\n  auto remove_space = [&](const\
    \ vector<vector<bool>> &mino){\r\n    vector<vector<bool>> ret;\r\n    for(int\
    \ x = xmn; x <= xmx; ++x)\r\n      ret.emplace_back(begin(mino[x])+ymn, begin(mino[x])+ymx+1);\r\
    \n    return ret;\r\n  };\r\n\r\n  vector<vector<vector<bool>>> ret;\r\n  auto\
    \ dfs = [&](auto&self, int x, int y) -> void {\r\n    if(remain == 0){\r\n   \
    \   ret.push_back(remove_space(visited));\r\n      return;\r\n    }\r\n\r\n  \
    \  for(auto&&[dx, dy] : adj){\r\n      int nx = x + dx, ny = y + dy;\r\n     \
    \ if(nx<0 || xlen<=nx || ny<0 || ylen<=ny) continue;\r\n      if(ny == 0 && nx\
    \ <= xmid) continue;\r\n      if(order[nx][ny] != -1) continue;\r\n      order[nx][ny]\
    \ = norder++;\r\n      histry.emplace(x, y, nx, ny);\r\n      if(!candidate_impl.count({nx,\
    \ ny})) candidate.emplace_back(nx, ny);\r\n    }\r\n\r\n    for(int i = 0, sz\
    \ = int(candidate.size()); i < sz; ++i){\r\n      auto[nx, ny] = candidate[i];\r\
    \n      if(order[nx][ny] <= order[x][y]) continue;\r\n\r\n      visited[nx][ny]\
    \ = true;\r\n      candidate.erase(begin(candidate) + i);\r\n      candidate_impl.erase({nx,\
    \ ny});\r\n\r\n      int pxmx = xmx, pxmn = xmn, pymx = ymx, pymn = ymn;\r\n\r\
    \n      --remain;\r\n      xmx = max(xmx, nx); xmn = min(xmn, nx);\r\n      ymx\
    \ = max(ymx, ny); ymn = min(ymn, ny);\r\n      self(self, nx, ny);\r\n      xmx\
    \ = pxmx, xmn = pxmn, ymx = pymx, ymn = pymn;\r\n\r\n      while(!histry.empty()){\r\
    \n        auto[px, py, pnx, pny] = histry.top();\r\n        if(px == nx && py\
    \ == ny){\r\n          order[pnx][pny] = -1;\r\n          histry.pop();\r\n  \
    \      }else{\r\n          break;\r\n        }\r\n      }\r\n      ++remain;\r\
    \n      candidate.insert(begin(candidate) + i, {nx, ny});\r\n      candidate_impl.emplace(nx,\
    \ ny);\r\n      visited[nx][ny] = false;\r\n    }\r\n  };\r\n  dfs(dfs, xmid,\
    \ 0);\r\n\r\n  return ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: other/enumerate_n_ominos.cpp
  requiredBy: []
  timestamp: '2023-02-10 14:54:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/enumerate_n_ominos.cpp
layout: document
redirect_from:
- /library/other/enumerate_n_ominos.cpp
- /library/other/enumerate_n_ominos.cpp.html
title: other/enumerate_n_ominos.cpp
---
