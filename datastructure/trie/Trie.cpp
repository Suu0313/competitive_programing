template<int W = 10>
struct Trie{
  vector<array<int, W>> to;
  // vector<size_t> sz, cnt;

  // Trie(): to(1, array<int, W>{0}), sz(1), cnt(1) {}

  // Trie(int n): to(1, array<int, W>{0}), sz(1), cnt(1) {
  //   to.reserve(n); sz.reserve(n); cnt.reserve(n);
  // }

  // size_t size() const { return sz[0]; }

  // bool empty() const { return !sz[0]; }

  // size_t count(const vector<int> &v) const {
  //   int pos = 0;
  //   for(int x : v){
  //     if(to[pos][x] == 0) return 0;
  //     pos = to[pos][x];
  //   }
  //   return cnt[pos];
  // }

  Trie(): to(1, array<int, W>{0}) {}

  int insert(const vector<int> &v){
    int pos = 0; // ++sz[pos];
    for(int x : v){
      if(to[pos][x] == 0) to[pos][x] = add_node();
      // ++sz[pos = to[pos][x]];
      pos = to[pos][x];
    }
    // ++cnt[pos];
    return pos;
  }

  // int erase(const vector<int> &v){
  //   int pos = 0;
  //   for(int x : v){
  //     if(to[pos][x] == 0 || !sz[to[pos][x]]) return -1;
  //     pos = to[pos][x];
  //   }
  //   if(!cnt[pos]) return -1;

  //   pos = 0; --sz[pos];
  //   for(int x : v){
  //     --sz[pos = to[pos][x]];
  //   }
  //   --cnt[pos];
  //   return pos;
  // }

  vector<int> ord;
  void build(){
    ord.resize(to.size());
    stack<int> st; st.push(0);
    int t = 0;

    while(!st.empty()){
      int pos = st.top(); st.pop();
      ord[pos] = t++;
      for(int x = W-1; x >= 0; --x){
        if(to[pos][x] != 0) st.push(to[pos][x]);
      }
    }
  }

  int get_ord(const vector<int> &v) const {
    int pos = 0;
    for(int x : v){
      if(to[pos][x] == 0) return -1;
      pos = to[pos][x];
    }
    return ord[pos];
  }

  int next(int pos, int x) const {
    return to[pos][x];
  }

private:
  size_t add_node(){
    size_t i = to.size();
    to.push_back({0, 0});
    //sz.push_back(0);
    //cnt.push_back(0);
    return i;
  }
};
