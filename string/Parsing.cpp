struct Parsing{
  using State = string::const_iterator;

  void consume(State &pos, char expected){
    if(*pos == expected) ++pos;
    else{
      cerr << "expected : '" << expected << "'\n";
      cerr << "pos : '" << *pos << "'\n";

      exit(0);
    }
  }

  int number(State &pos){
    int res = 0;
    for(; isdigit(*pos); ++pos){
      res = res*10 + *pos-'0';
    }
    return res;
  }

  int factor(State &pos){
    if(*pos == '('){
      consume(pos, '(');
      int res = expression(pos);
      consume(pos, ')');
      return res;
    }else{
      return number(pos);
    }
  }

  int term(State &pos){
    int res = factor(pos);
    while(true){
      if(*pos == '*'){
        consume(pos, '*');
        res *= factor(pos);
      }else if(*pos == '/'){
        consume(pos, '/');
        res /= factor(pos);
      }else break;
    }
    return res;
  }

  int expression(State &pos){
    int res = term(pos);
    while(true){
      if(*pos == '+'){
        consume(pos, '+');
        res += term(pos);
      }else if(*pos == '-'){
        consume(pos, '-');
        res -= term(pos);
      }else break;
    }
    return res;
  }

  int parse(const string &s){
    State pos = s.begin();
    return expression(pos);
  }
};
