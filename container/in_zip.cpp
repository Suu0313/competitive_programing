template<class Container> auto myref(Container &c, size_t i){ return ref(c[i]); }
template<class Container> auto myref(Container &&c, size_t i){ return c[i]; }

template<class... Cs>
auto in_zip_ref(Cs&&... cs){
  vector<tuple<conditional_t<is_lvalue_reference_v<Cs>, add_lvalue_reference_t<typename remove_reference_t<Cs>::value_type>, typename remove_reference_t<Cs>::value_type>...>> v;
  size_t n = min({size(cs)...}); v.reserve(n);
  for(size_t i = 0; i < n; i++) v.emplace_back(myref(std::forward<Cs>(cs), i)...);
  return v;
}

template<class... Cs>
auto enumerate_ref(Cs&&... cs){
  auto iota_impl = [&]{ vector<int> idx(min({size(cs)...})); iota(begin(idx), end(idx), 0); return idx; };
  return inzip(iota_impl(), cs...);
}

template<class... Cs>
auto in_zip(Cs&&... cs){
  vector<tuple<typename remove_reference_t<Cs>::value_type ...>> v;
  size_t n = min({size(cs)...}); v.reserve(n);
  for(size_t i = 0; i < n; i++) v.emplace_back(cs[i]...);
  return v;
}

template<class... Cs>
auto enumerate(Cs&&... cs){
  vector<int> idx(min({size(cs)...}));
  iota(begin(idx), end(idx), 0);
  return in_zip(idx, cs...);
}

template<typename T, size_t... Is>
auto unpack_impl(const vector<T> &v, index_sequence<Is...>){
  tuple<vector<typename tuple_element<Is, T>::type>...> res;
  size_t n = v.size();
  for(size_t i = 0; i < n; ++i){
    [[maybe_unused]] bool a[] = {(get<Is>(res).push_back(get<Is>(v[i])), false)...};
  }
  return res;
}

template<typename T>
auto unpack(const vector<T> &v){
  return unpack_impl(v, make_index_sequence<tuple_size<T>::value>());
}
