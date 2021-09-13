template<class Container>
struct Enumerate{
  struct itr{
    int idx;
    typename Container::iterator it;
    bool operator!=(typename Container::iterator e){ return it != e; }
    void operator++(){ ++idx; ++it; }
    pair<int, typename Container::value_type> operator*(){ return {idx, *it}; }
  };

  Container c;
  Enumerate(const Container &c): c(c){ }

  itr begin(){ return {0, std::begin(c)}; }
  typename Container::iterator end(){ return std::end(c); }
};
