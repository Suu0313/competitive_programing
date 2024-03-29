#pragma once

template<typename Container>
struct KnuthMorrisPrattAlgorithm{
  Container s;
  vector<int> mp, kmp;
  KnuthMorrisPrattAlgorithm() = default;

  KnuthMorrisPrattAlgorithm(const Container &s): s(s), mp(s.size()+1, -1), kmp(s.size()+1, -1){
    int n = int(s.size());
    for(int i = 0, j = -1; i < n; ){
      while(j >= 0 && (s[i] != s[j])) j = kmp[j];
      ++i; ++j;
      mp[i] = j;
      if(s[i] == s[j]) kmp[i] = kmp[j];
      else kmp[i] = j;
    }
  }

  template<typename T>
  void push_back(T c){
    int i = int(s.size()), j = mp[i];
    s.push_back(c);
    kmp.pop_back();
    kmp.push_back(((j >= 0) && (s[i] == s[j])) ? kmp[j] : j);


    while(j >= 0 && (s[i] != s[j])) j = kmp[j];
    ++i; ++j;
    mp.push_back(j);
    kmp.push_back(j);
  }

  void pop_back(){
    s.pop_back();
    mp.pop_back();
    kmp.pop_back();
    kmp.back() = mp.back();
  }

  // period of [0, i)
  int period(int i) const { return i - mp[i]; }

  // t[i:i+n] == s
  vector<int> match(const Container &t) const {
    int n = int(s.size()), m = int(t.size());
    vector<int> res;

    for(int i = 0, j = 0; j < m; ){
      while(i >= 0 && (s[i] != t[j])) i = kmp[i];
      ++i; ++j;
      if(i >= n){
        res.push_back(j-i); i = kmp[i];
      }
    }
    return res;
  }
};
