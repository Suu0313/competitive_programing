template<class Container> auto myref(Container &c, size_t i){ return ref(c[i]); }
template<class Container> auto myref(Container &&c, size_t i){ return c[i]; }

template<class... Cs>
auto inzip(Cs&&... cs){
  vector<tuple<conditional_t<is_lvalue_reference_v<Cs>, add_lvalue_reference_t<typename remove_reference_t<Cs>::value_type>, typename remove_reference_t<Cs>::value_type>...>> v;
  size_t n = min({size(cs)...}); v.reserve(n);
  for(size_t i = 0; i < n; i++) v.emplace_back(myref(std::forward<Cs>(cs), i)...);
  return v;
}

template<class... Cs>
auto enumerate(Cs&&... cs){
  auto iota_impl = [&]{ vector<int> idx(min({size(cs)...})); iota(begin(idx), end(idx), 0); return idx; };
  return inzip(iota_impl(), cs...);
}
