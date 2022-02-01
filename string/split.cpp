template <typename F>
void split(const string& str, char delim, const F& f){
  istringstream iss{str};
  string token;
  while(getline(iss, token, delim)){
    f(token);
  }
}
vector<string> split(const string& str, char delim=' ', bool rmsp = true){
  vector<string> tokens;
  split(str, delim, [&tokens, &rmsp](const string& token){
    if(!(rmsp && token.empty())) tokens.emplace_back(token);
  });
  return tokens;
}