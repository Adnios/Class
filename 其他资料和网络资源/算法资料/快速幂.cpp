a ^ b =
(a ^ (b/2 + b/2)) = a ^ (b/2) * a ^ (b/2) (b % 2 == 0)
(a ^ (b/2 + b/2 + 1)) = a ^ (b/2) * a ^ (b/2) * a (b % 2 == 1)

a ^ (101) = a ^ (100) * a ^ 1

ll power(ll x, int y) {
	ll z = 1;
	while (y) {
		if (y & 1) (z *= x) %= mod;
		(x *= x) %= mod; y >>= 1;
	}
	return z;
}


