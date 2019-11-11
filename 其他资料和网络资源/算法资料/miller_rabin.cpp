#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <ctime>
#define Rep(i, x, y) for (int i = x; i <= y; i ++)
#define RepE(i, x) for (int i = pos[x]; i; i = g[i].nex)
#define C 240
#define TIME 10
using namespace std;
typedef long long LL;
LL ans;
int T;
LL Mult(LL x, LL y, LL md) {
	LL z = 0;
	while (y) {
		if (y & 1) (z += x) %= md;
		(x += x) %= md, y >>= 1;
	}
	return z;
}
LL Pow(LL x, LL y, LL md) {
	LL z = 1; x %= md;
	while (y) {
		if (y & 1) z = Mult(z, x, md);
		x = Mult(x, x, md), y >>= 1;
	}
	return z;
}
LL gcd(LL x, LL y) {
	if (x == 0) return 1;
	if (x < 0) return gcd(-x, y);
	return !y ? x : gcd(y, x % y);
}
bool Witness(LL a, LL n) {
	LL t = 0, u = n - 1;
	while (!(u & 1)) t ++, u /= 2;
	LL x0 = Pow(a, u, n);
	if (x0 == 1) return 0;
	for (int i = 0; i < t; i ++) {
		if (x0 == n - 1) return 0;
		x0 = Mult(x0, x0, n);
	}
	return 1;
}
bool Miller_Rabin(LL n, int t) {
	if (n == 2) return 1;
	if ((n & 1) == 0) return 0;
	srand(time(0));
	for (int i = 0; i < t; i ++) {
		LL a = rand() % (n-1) + 1;
		if (Witness(a, n)) return 0;
	}
	return 1;
}
/*
LL Pollard_Rho(LL n, LL c) {
	LL x = rand() % n, y = x, k = 2;
	for (int i = 2; ;i ++) {
		x = (Mult(x, x, n) + c) % n;
		LL d = gcd(y - x, n);
		if (d != 1 && d != n) return d;
		if (x == y) return n;
		if (i == k) y = x, k *= 2;
	}
}
void get_small(LL n, LL c) {
	if (n == 1) return ;
	if (Miller_Rabin(n, TIME)) { ans = min(n, ans); return ; }
	LL p = n;
	while (p >= n) p = Pollard_Rho(p, c --);
	get_small(p, c);
	get_small(n/p, c);
}
*/
int main()
{
	srand(time(0));
	scanf ("%d", &T);
	while (T --) {
		LL n; scanf("%I64d", &n);
		if (Miller_Rabin(n, TIME)) printf ("Prime\n");
		else { 
			printf ("NotPrime\n");
			// ans = n, get_small(n, C);
			//printf ("%I64d\n", ans);
		}
	}

    return 0;
}

