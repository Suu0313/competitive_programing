template<typename T>
struct Trie{
  Trie(): ptr(1), sz(1) {}

  vector<map<T, size_t>> ptr;
  vector<size_t> sz;

  template<class Iter>
  int add(Iter first, Iter last){
    int i = 0; ++sz[0];
    for(; first != last; ++first){
      T c = *first;
      if(auto it = ptr[i].find(c); it == ptr[i].end()){
        ptr[i][c] = sz.size();
        sz.push_back(0);
        ptr.push_back({});
      }
      sz[i = ptr[i][c]] += 1;
    }
    return i;
  }

  template<class Container>
  int add(const Container &c){  return add(begin(c), end(c)); }

  template<class Iter>
  int cnt(Iter first, Iter last) const {
    int i = 0;
    for(; first != last; ++first){
      T c = *first;
      if(const auto it = ptr[i].find(c); it == ptr[i].end()){
        return 0;
      }
      i = ptr[i][c];
    }
    return sz[i];
  }

  template<class Container>
  size_t cnt(const Container &c) const { return cnt(begin(c), end(c)); }

  vector<vector<int>> get_graph() const {
    int n = int(sz.size());
    vector<vector<int>> g(n);
    for(int i = 0; i < n; ++i){
      for(const auto[c, to] : ptr[i]) g[i].push_back(to);
    }
    return g;
  }

  int succ(int p, const T &c) const {
    if(ptr[p].find(c) == ptr[p].end()) return -1;
    return ptr[p].at(c);
  }

  size_t size() const { return sz.size(); }
};
