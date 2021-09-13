template<class Container>
struct Enumerate{
  struct itr{
    int idx;
    typename Container::iterator it;
    bool operator!=(itr &e){ return it != e.it; }
    void operator++(){ ++idx; ++it; }
    pair<int, typename Container::value_type> operator*(){ return {idx, *it}; }
  };

  Container c;
  Enumerate(const Container &c): c(c){ }

  itr begin(){ return {0, std::begin(c)}; }
  itr end(){ return {0, std::end(c)}; }
};
