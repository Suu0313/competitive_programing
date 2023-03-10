#pragma once

template<typename T = char>
struct MultiPalindromicTree{
private:
  struct Node{
    map<T, int> link;
    int link_rev = -1;
    int suffix_link = -1; // same suffix maximum pal
    int len; // palindrome length
    vector<int> cnt; // freq of this
    pair<int, int> idx; // one of the start pos

    Node() = default;
    Node(int n, int len): len(len), cnt(n, 0), idx(-1, -1) {}

    int succ(const T &c) const {
      auto it = link.find(c);
      if(it == link.end()) return -1;
      return it->second;
    }
  };

  // find longest P s.t. c + P + c is pal
  int find_next_pal(int p, int k) const {
    int pos = int(seq[p].size()) - 1;
    while(true){
      int i = pos - 1 - nodes[k].len;
      if(i >= 0 && seq[p][i] == seq[p][pos]) return k;
      k = nodes[k].suffix_link;
    }
  }

public:

  int n;
  vector<Node> nodes;
  vector<vector<T>> seq;
  vector<vector<int>> ston;
  vector<int> suffix_max;


  MultiPalindromicTree(int n): n(n), seq(n), ston(n), suffix_max(n){
    nodes.emplace_back(n, -1); // odd node
    nodes.emplace_back(n, 0); // even node
    nodes[1].suffix_link = 0;
  }

  void add(int i, const T &c){
    seq[i].push_back(c);
    int k = find_next_pal(i, suffix_max[i]);

    // c + P + c is already exists
    if(int p = nodes[k].succ(c); p != -1){
      ++nodes[p].cnt[i];
      suffix_max[i] = p;
      ston[i].push_back(p);
      return;
    }

    // unique
    nodes[k].link[c] = suffix_max[i] = int(nodes.size());
    ston[i].push_back(suffix_max[i]);
    int len = nodes[k].len + 2;
    nodes.emplace_back(n, len);
    
    nodes.back().cnt[i] = 1;
    nodes.back().idx = {i, int(seq[i].size()) - len};
    nodes.back().link_rev = k;

    if(len == 1) nodes.back().suffix_link = 1;
    else nodes.back().suffix_link = 
      nodes[find_next_pal(i, nodes[k].suffix_link)].link[c];
  }

  template<class Iiter>
  void add(int i, Iiter first, Iiter last){
    for(; first != last; ++first) add(i, *first);
  }
  
  template<class Container>
  void add(int i, const Container &c){
    add(i, begin(c), end(c));
  }

  // idx of suffix palindromes of node k
  vector<int> suffix_palindromes(int k) const {
    vector<int> ret;
    for(; nodes[k].len > 0; k = nodes[k].suffix_link){
      ret.push_back(k);
    }
    return ret;
  }

  // idx of substring palindromes of node k
  vector<int> substr_palindroms(int k) const {
    vector<int> ret, seen(nodes.size());
    queue<int> qu;
    qu.push(k); seen[k] = 1;
    for(; !qu.empty(); qu.pop()){
      int v = qu.front();
      ret.push_back(v);
      for(int u : {nodes[v].suffix_link, nodes[v].link_rev}){
        if(!seen[u]) qu.push(u), seen[u] = 1;
      }
    }
    return ret;
  }

  // not count ""
  int count() const { return int(nodes.size()) - 2; }

  vector<vector<int>> palindromes_frequency() const {
    int m = int(nodes.size());
    vector<vector<int>> freq(m, vector<int>(n));
    for(int i = m - 1; i >= 1; --i){
      for(int j = 0; j < n; ++j){
        freq[i][j] += nodes[i].cnt[j];
        freq[nodes[i].suffix_link][j] += freq[i][j];
      }
    }
    return freq;
  }

  const Node &operator[](int k) const { return nodes[k]; }
};
