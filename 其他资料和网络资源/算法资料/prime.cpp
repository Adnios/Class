notp[1] = 1;
for (int i = 2; i <= n; i ++) { //if (!notp[i]) {
	for (int j = i * 2; j <= n; j += i) notp[j] = 1;
}
n * (1/2 + 1/3 + ... + 1/n)

1 + (1/2 + 1/3) + (1/4 + ... + 1/7) + .. + 1/n
1 + (1/2 + 1/2) + (1/4 + 1/4 + 1/4 + 1/4) + ..
1 + 1 + 1...


notp[1] = phi[1] = mu[1] = 1;
for (int i = 2; i <= n; i ++) {
	if (!notp[i]) pri[++ psz] = i, phi[i] = i - 1, mu[i] = -1;
	for (int j = 1; j <= psz; j ++) {
		int k = i * pri[j];
		if (k > n) break ;
		notp[i * pri[j]] = 1;
		if (i % pri[j] == 0) {
			phi[k] = phi[i] * pri[j];
			mu[k] = 0;
			break ;
		} else {
			phi[k] = phi[i] * (pri[j] - 1);
			mu[k] = -mu[i];
		}
	}
}

30

//6 * 5
//10 * 3
15 * 2

for (int i = 1; i <= psz; i ++) {
	int p = pri[i];
	for (int j = (l - 1) / p + 1; j <= r / p; j ++) notp[j * p - l] = 1;
}
