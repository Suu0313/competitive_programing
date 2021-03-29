LL gcd(LL a, LL b) { return b?gcd(b,a%b):a;}
LL lcm(LL a, LL b) { return a/gcd(a,b)*b;}