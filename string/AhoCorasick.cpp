template<typename T>
struct AhoCorasick{
  AhoCorasick(): ptr(1), cnt(1) {}

  vector<map<T, int>> ptr;
  vector<int> fail, cnt;

  size_t size() const { return cnt.size(); }
  int operator[](int v) const { return cnt[v]; }

  int succ(int v, const T &c) const {
    while(v != -1){
      auto it = ptr[v].find(c);
      if(it != ptr[v].end()) return it->second;
      v = fail[v];
    }
    return 0;
  }

  int add_node(int v, const T &c){
    auto it = ptr[v].find(c);
    if(it == ptr[v].end()){
      ptr[v][c] = cnt.size();
      ptr.push_back({});
      cnt.push_back(0);
    }
    return ptr[v][c];
  }

  template<class Iter>
  int add(Iter first, Iter last){
    int v = 0;
    for(; first != last; ++first){
      T c = *first;
      v = add_node(v, c);
    }
    ++cnt[v];
    return v;
  }

  template<class Container>
  int add(const Container &c){  return add(begin(c), end(c)); }

  void build(){
    fail.assign(this->size(), -1);
    queue<int> qu;
    for(qu.push(0); !qu.empty(); qu.pop()){
      int v = qu.front();
      for(auto[c, to] : ptr[v]){
        fail[to] = this->succ(fail[v], c);
        cnt[to] += cnt[fail[to]];
        qu.push(to);
      }
    }
  }
};
