LL ExtGcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL d = ExtGcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}

//ax+by=d=gcd(a,b)