template <typename F>
void split(const string& str, char delim, const F& f){
  istringstream iss{str};
  string token;
  while(getline(iss, token, delim)){
    f(token);
  }
}
vector<string> split(const string& str, char delim=' '){
  vector<string> tokens;
  split(str, delim, [&tokens](const string& token){
    if(!token.empty()) tokens.EB(token);
  });
  return tokens;
}