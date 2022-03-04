template<typename T = unsigned,  int B = 32>
struct BinaryTrie{
  vector<array<int, 2>> to;
  vector<size_t> sz;

  BinaryTrie(): to(1, {0, 0}), sz(1) {}

  size_t size() const { return sz[0]; }

  bool empty() const { return !sz[0]; }

  size_t count(T x) const {
    int pos = 0;
    for(int i = B-1; i >= 0; --i){
      int j = x >> i & 1;
      if(to[pos][j] == 0) return 0;
      pos = to[pos][j];
    }
    return sz[pos];
  }

  int insert(T x){
    int pos = 0; ++sz[pos];
    for(int i = B-1; i >= 0; --i){
      int j = x >> i & 1;
      if(to[pos][j] == 0) to[pos][j] = add_node();
      ++sz[pos = to[pos][j]];
    }
    return pos;
  }

  int erase(T x){
    int pos = 0;
    for(int i = B-1; i >= 0; --i){
      int j = x >> i & 1;
      if(to[pos][j] == 0 || !sz[to[pos][j]]) return -1;
      pos = to[pos][j];
    }

    pos = 0; --sz[pos];
    for(int i = B-1; i >= 0; --i){
      int j = x >> i & 1;
      --sz[pos = to[pos][j]];
    }
    return pos;
  }

  T min(T x = 0) const {
    int pos = 0;
    T mn = 0;
    for(int i = B-1; i >= 0; --i){
      int j = x >> i & 1, k = j;
      if(to[pos][j] == 0 || !sz[to[pos][j]]) j ^= 1;
      if(to[pos][j] == 0 || !sz[to[pos][j]]) break;
      if(j != k) mn |= T(1) << i;
      pos = to[pos][j];
    }
    return mn;
  }

  /*
  ToDo: lb, ub, kth, max
  //*/

private:
  size_t add_node(){
    size_t i = to.size();
    to.push_back({0, 0});
    sz.push_back(0);
    return i;
  }
};
