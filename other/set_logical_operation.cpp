template<typename Container>
Container SetAnd(const Container &a, const Container &b){
  Container res;
  std::set_intersection(
    std::begin(a), std::end(a),
    std::begin(b), std::end(b),
    std::inserter(res, std::end(res))
  );
  return res;
}
template<typename Container>
Container SetOr(const Container &a, const Container &b){
  Container res;
  std::set_union(
    std::begin(a), std::end(a),
    std::begin(b), std::end(b),
    std::inserter(res, std::end(res))
  );
  return res;
}
template<typename Container>
Container SetXor(const Container &a, const Container &b){
  Container res;
  std::set_symmetric_difference(
    std::begin(a), std::end(a),
    std::begin(b), std::end(b),
    std::inserter(res, std::end(res))
  );
  return res;
}
template<typename Container>
Container SetDiff(const Container &a, const Container &b){
  Container res;
  std::set_difference(
    std::begin(a), std::end(a),
    std::begin(b), std::end(b),
    std::inserter(res, std::end(res))
  );
  return res;
}