#pragma once

template<typename T = char>
struct PalindromicTree{
private:
  struct Node{
    map<T, int> link;
    int link_rev = -1;
    int suffix_link = -1; // same suffix maximum pal
    int len; // palindrome length
    int cnt; // freq of this
    int idx; // one of the start pos

    Node() = default;
    Node(int len, int cnt, int idx = -1): len(len), cnt(cnt), idx(idx) {}

    int succ(const T &c) const {
      auto it = link.find(c);
      if(it == link.end()) return -1;
      return it->second;
    }
  };

  // find longest P s.t. c + P + c is pal
  int find_next_pal(int k) const {
    int pos = int(seq.size()) - 1;
    while(true){
      int i = pos - 1 - nodes[k].len;
      if(i >= 0 && seq[i] == seq[pos]) return k;
      k = nodes[k].suffix_link;
    }
  }

public:

  vector<Node> nodes;
  vector<T> seq;
  vector<int> ston;
  int suffix_max;


  PalindromicTree(){
    nodes.emplace_back(-1, 0); // odd node
    nodes.emplace_back(0, 0); // even node
    nodes[1].suffix_link = 0;
    suffix_max = 0;
  }
  template<class Iiter>
  PalindromicTree(Iiter first, Iiter last): PalindromicTree() {
    add(first, last);
  }
  template<class Container>
  PalindromicTree(const Container &c): PalindromicTree() {
    add(c);
  }

  void add(const T &c){
    seq.push_back(c);
    int k = find_next_pal(suffix_max);

    // c + P + c is already exists
    if(int p = nodes[k].succ(c); p != -1){
      ++nodes[p].cnt;
      suffix_max = p;
      ston.push_back(p);
      return;
    }

    // unique
    nodes[k].link[c] = suffix_max = int(nodes.size());
    ston.push_back(suffix_max);
    int len = nodes[k].len + 2;
    nodes.emplace_back(len, 1, int(seq.size()) - len);
    
    nodes.back().link_rev = k;

    if(len == 1) nodes.back().suffix_link = 1;
    else nodes.back().suffix_link = 
      nodes[find_next_pal(nodes[k].suffix_link)].link[c];
  }

  template<class Iiter>
  void add(Iiter first, Iiter last){
    for(; first != last; ++first) add(*first);
  }
  
  template<class Container>
  void add(const Container &c){
    add(begin(c), end(c));
  }

  // seq[i] = node[k].last
  int get_node_idx(int i) const { return ston[i]; }

  // idx of suffix palindromes of node k
  vector<int> suffix_palindromes(int k) const {
    vector<int> ret;
    for(; nodes[k].len > 0; k = nodes[k].suffix_link){
      ret.push_back(k);
    }
    return ret;
  }

  // idx of suffix palindromes of seq
  vector<int> suffix_palindromes() const {
    return suffix_palindromes(suffix_max);
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
        if(u == -1) continue;
        if(!seen[u]) qu.push(u), seen[u] = 1;
      }
    }
    return ret;
  }

  // not count ""
  int count() const { return int(nodes.size()) - 2; }

  vector<int> palindromes_frequency() const {
    int n = int(nodes.size());
    vector<int> freq(n);
    for(int i = n - 1; i >= 1; --i){
      freq[i] += nodes[i].cnt;
      freq[nodes[i].suffix_link] += freq[i];
    }
    return freq;
  }

  const Node &operator[](int k) const { return nodes[k]; }
};
