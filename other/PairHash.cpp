struct PairHash{
  static size_t hash0;

  template<typename T1, typename T2>
  size_t operator()(const pair<T1, T2> &p) const {
    auto hash1 = hash<T1>{}(p.first);
    auto hash2 = hash<T2>{}(p.second);

    size_t seed = 0;
    seed ^= hash1 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    seed ^= hash0 + 0x9e3779b9 + (seed << 6) + (seed >> 2);

    return seed;
  }
};
size_t PairHash::hash0 = (size_t) random_device{}();
