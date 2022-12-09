#define MATCH1(a) break; case a:
#define MATCH2(a, b) break; case a: case b:
#define MATCH3(a, b, c) break; case a: case b: case c:
#define MATCH4(a, b, d) break; case a: case b: case c: case d:
#define MATCH(...) OVERLOAD4(__VA_ARGS__, MATCH4, MATCH3, MATCH2, MATCH1)(__VA_ARGS__)
#define OW break; default:

/*
switch(x){
  MATCH(0){
    COUT(0);

  }MATCH(1, 2){
    COUT(1);

  }OW{
    COUT(2);

  }
}
//*/