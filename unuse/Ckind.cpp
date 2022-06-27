int Ckind(char c){
  if(isdigit(c)) return 0;
  if(isupper(c)) return 1;
  if(islower(c)) return 2;
  if(isspace(c)) return 3;
  
  return 4;
}

void Cchange(char &c){
  if(isupper(c)) c = tolower(c);
  else if(islower(c)) c = toupper(c);
  return;
}

bool isvowel(char c){
  VC vowel = {'a','i','u','e','o'};
  for(auto a : vowel) if(a == c) return true;
  return false;
}