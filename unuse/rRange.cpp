template<typename rbIterator, typename reIterator>
struct rRange{
  rbIterator m_rbegin;
  reIterator m_rend;
  rRange(rbIterator m_rbegin, reIterator m_rend): m_rbegin(m_rbegin), m_rend(m_rend) {}
  rbIterator &begin() { return m_rbegin; };
  rbIterator &end() { return m_rend; };
};

template<typename Container>
auto rev(const Container &c){ return rRange(rbegin(c), rend(c)); }
