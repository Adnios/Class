#include <cstdio>

using namespace std;
const int N = 100005;
const int mod = 1000000007;

int n = 10	;
int fac[N], inv[N];

int pow(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod;
		y >>= 1;
	}
	return res;
}

int C(int n, int m) {
	return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}

int main() {
	fac[1] = 1;
	for (int i = 2; i <= n; ++i)
		fac[i] = 1ll * fac[i - 1] * i % mod;
	
	inv[n] = pow(fac[n], mod - 2);
	for (int i = n - 1; i; --i)
		inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
	
	printf("%d %d\n", C(5, 2), C(10, 4));
	return 0;
}