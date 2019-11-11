int solve(int *a, int n, int t) {
	while (n && a[n] == t) n --;
	if (!n) return 0;
	int x = 6 - a[n] - t;
	return solve(a, n - 1, x) + 1 + s[n - 1];
}
