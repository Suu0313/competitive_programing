template<class Container> auto myref(Container &c, size_t i){ return ref(c[i]); }
template<class Container> auto myref(Container &&c, size_t i){ return c[i]; }

template<class... Cs>
auto inzip(Cs&&... cs){
  vector v(1, make_tuple(myref(std::forward<Cs>(cs), 0)...));
  size_t n = min({size(cs)...});
  for(size_t i = 1; i < n; i++) v.push_back(make_tuple(myref(std::forward<Cs>(cs), i)...));
  return v;
}

template<class... Cs>
auto enumerate(Cs&&... cs){
  auto iota_impl = [&]{ vector<int> idx(min({size(cs)...})); iota(begin(idx), end(idx), 0); return idx; };
  return inzip(iota_impl(), cs...);
}
