struct bign {
    int n[N], l;
    bign() { memset(n, 0, sizeof(n)), l = 0; }
    void cl() { memset(n, 0, sizeof(n)), l = 0; }
    int& operator[] (int i) { return n[i]; }
    void rd() {
        scanf ("%s", sn + 1);
        int k = 1, ls = strlen(sn + 1);
        Rep(i, 1, ls) {
            n[l] += (sn[ls - i + 1] - '0') * k, k *= 10;
            if (i % 4 == 0 || i == ls) l ++, k = 1;
        }
        l --;
    }
    void pr() {
        int len = 0;
        Rep(i, 0, l) {
            int k = n[i];
            Rep(j, 1, 4) sn[++ len] = '0' + k % 10, k /= 10;
        }
        while (len > 1 && sn[len] == '0') len --;
        Dwn(i, len, 1) printf("%c", sn[i]);
        puts("");
    }
} ans, sum;
bign make(LL x) {
    bign a;
    while (x) a[a.l ++] = x % lm, x /= lm;
    if (a.l) a.l --;
    return a;
}
bign operator+ (bign a, bign b) {
    bign c = a; c.l = max(a.l, b.l);
    Rep(i, 0, c.l) {
        c[i] += b[i];
        c[i + 1] += c[i] / lm, c[i] %= lm;
    }
    while (c[c.l + 1]) c.l ++, c[c.l + 1] += c[c.l] / lm, c[c.l] %= lm;
    return c;
}
bign operator- (bign a, bign b) {
    bign c = a;
    Rep(i, 0, c.l) {
        c[i] -= b[i];
        if (c[i] < 0) c[i] += lm, c[i + 1] --;
    }
    while (c.l && !c[c.l]) c.l --;
    return c;
}
bign operator* (bign a, bign b) {
    bign c; c.l = a.l + b.l;
    Rep(i, 0, a.l) {
        Rep(j, 0, b.l) {
            c[i + j] += a[i] * b[j];
            //c[i + j + 1] += c[i + j] / lm;
            //c[i + j] %= lm;
        }
    }
    Rep(i, 0, c.l) c[i + 1] += c[i] / lm, c[i] %= lm;
    while (c[c.l + 1]) c.l ++, c[c.l + 1] += c[c.l] / lm, c[c.l] %= lm;
    return c;
}
bign operator+ (bign a, LL x) { return a + make(x); }
bign operator- (bign a, LL x) { return a - make(x); }
bign operator* (bign a, LL x) { return a * make(x); }
bign operator/ (bign a, LL b) {
    bign c; LL d = 0;
    c.l = a.l;
    Dwn(i, a.l, 0) d = d * lm + a[i], c[i] = d / b, d %= b;
    while (c.l && !c[c.l]) c.l --;
    return c;
}
