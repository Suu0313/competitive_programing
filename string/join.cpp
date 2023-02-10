#pragma once

template<typename Container>
string join(const Container&v, const string &sep = "", const string &en = ""){
  stringstream s;
  for(size_t i = 0; i < size(v); i++) s << v[i] << (i+1 != size(v) ? sep : en);
  return s.str();
}
