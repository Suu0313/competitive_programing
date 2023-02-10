#pragma once

template<typename T = char>
struct SuffixAutomaton{
  using Mp = map<T, int>;

  struct Node{
    Mp next;
    int len, link, id;
    bool is_clone;
    Node(const Mp &next, int len, int link, int id, bool is_clone)
    : next(next), len(len), link(link), id(id), is_clone(is_clone) {}

    Node(Node&&) = default;
    bool contains(T c) const { return next.find(c) != next.end(); }
  };

  vector<Node> nodes;
  int last = 0, gen = 0;

  SuffixAutomaton() { make_node(0); }
  template<typename Container>
  SuffixAutomaton(const Container &s): SuffixAutomaton() {
    for(auto&&c : s) push(c);
    sort_topologically();
  }
  SuffixAutomaton(const SuffixAutomaton&) = default;
  SuffixAutomaton(SuffixAutomaton&&) = default;

  int make_node(int len){
    int p = int(nodes.size());
    nodes.emplace_back(Mp{}, len, -1, gen++, false);
    return p;
  }

  int make_node(const Mp &next, int len, int link, bool is_clone){
    int p = int(nodes.size());
    nodes.emplace_back(next, len, link, gen++, is_clone);
    return p;
  }

  void push(T c){
    int cur = make_node(nodes[last].len + 1);
    int p = last;

    for(; (p != -1) && !nodes[p].contains(c); p = nodes[p].link){
      nodes[p].next[c] = cur;
    }

    int q = (p == -1 ? 0 : nodes[p].next[c]);
    if(p == -1 || nodes[p].len+1 == nodes[q].len){
      nodes[cur].link = q;
    }else{
      int nq = make_node(nodes[q].next, nodes[p].len + 1, nodes[q].link, true);
      nodes[q].link = nq;
      nodes[cur].link = nq;

      for(; p != -1 && nodes[p].next[c] == q; p = nodes[p].link){
        nodes[p].next[c] = nq;
      }
    }
    last = cur;
  }

  void sort_topologically(){
    vector<int> idx; idx.reserve(gen);
    {
      vector<vector<int>> base(gen + 1);
      for(int i = 0; i < gen; ++i) base[nodes[i].len].push_back(i);
      for(auto&v : base){
        if(v.empty()) continue;
        idx.insert(end(idx), begin(v), end(v));
      }
    }
    vector<int> rev(gen);
    for(int i = 0; i < gen; ++i) rev[idx[i]] = i;
    {
      vector<Node> tmp; tmp.reserve(gen);
      for(int i = 0; i < gen; ++i) tmp.emplace_back(move(nodes[idx[i]]));
      swap(nodes, tmp);
    }

    for(auto&node : nodes){
      for(auto&[c, j] : node.next) j = rev[j];
      if(node.link != -1) node.link = rev[node.link];
    }
  }

  size_t size() const { return nodes.size(); }

  template<typename Container>
  int find(const Container &s) const {
    int cur = 0;
    for(auto&&c : s){
      if(!nodes[cur].contains(c)) return -1;
      cur = nodes[cur].next.at(c);
    }
    return cur;
  }


  int64_t number_of_substrings() const {
    int64_t res = 0;
    for(int i = 1; i < gen; ++i){
      res += nodes[i].len - nodes[nodes[i].link].len;
    }
    return res;
  }

  int64_t number_of_substrings_dp(){
    vector<int64_t> dp(gen);
    dp[0] = 1;
    int64_t res = 0;
    for(int i = 0; i < gen; ++i){
      res += dp[i];
      for(auto&[c, j] : nodes[i].next){
        dp[j] += dp[i];
      }
    }
    --res;
    return res;
  }

  vector<int> enum_number_of_substrs(){
    vector<int> dp(gen);
    for(int i = gen-1; i >= 1; --i){
      if(!nodes[i].is_clone) ++dp[i];
      dp[nodes[i].link] += dp[i];
    }
    return dp;
  }

  template<typename Container>
  int number_of_substring(const Container &s){
    int cur = this->find(s);
    if(cur == -1) return 0;
    return enum_number_of_substrs[cur];
  }

  vector<vector<T>> enumerate_substrs() const {
    vector<vector<T>> res;
    stack<pair<int, vector<T>>> st;
    st.emplace(0, vector<T>{});
    while(!st.empty()){
      auto[i, s] = st.top(); st.pop();
      res.emplace_back(s);
      for(auto&[c, j] : nodes[i].next){
        s.push_back(c);
        st.emplace(j, s);
        s.pop_back();
      }
    }
    return res;
  }

  template<typename Container>
  vector<T> longest_common_substr(const Container &s) const {
    int n = int(s.size());
    if(n == 0) return {};
    int v = 0, mx = 0, mxp = 0;
    for(int i = 0, l = 0; i < n; ++i){
      while(v != 0 && !nodes[v].contains(s[i])){
        v = nodes[v].link;
        l = nodes[v].len;
      }
      if(nodes[v].contains(s[i])){
        v = nodes[v].next.at(s[i]);
        ++l;
      }
      if(mx < l){
        mx = l; mxp = i;
      }
    }
    return {begin(s) + mxp-mx+1, begin(s)+mxp+1};
  }

  vector<int> enum_first_occurs() const {
    vector<int> to(gen, 1e9);
    for(int i = gen-1; i >= 0; --i){
      if(!nodes[i].is_clone) to[i] = nodes[i].len;
      
      if(i && nodes[nodes[i].link].is_clone && to[i] > to[nodes[i].link]){
        to[nodes[i].link] = to[i];
      }
    }
    return to;
  }
  
  vector<int64_t> number_of_substrings_dp2() const {
    vector<int64_t> dp(gen);
    for(int i = gen-1; i >= 0; --i){
      dp[i] = 1;
      for(const auto&[c, j] : nodes[i].next){
        dp[i] += dp[j];
      }
    }
    return dp;
  }

  vector<T> kth_substring(int64_t k) const {
    if(k <= 0) return {};
    vector<int64_t> dp = number_of_substrings_dp2();
    if(dp[0] <= k) return {};

    int i = 0;
    vector<T> res;
    while(k > 0){
      --k;
      for(const auto&[c, j] : nodes[i].next){
        if(k < dp[j]){
          res.push_back(c);
          i = j;
          break;
        }else{
          k -= dp[j];
        }
      }
    }
    return res;
  }
};
