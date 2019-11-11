#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
const int MOD = 10;

struct bigNum {
	int len;
	int a[100];
	
	bigNum() {
		len = 0;
		memset(a, 0, sizeof(a));
	}
	
	void zero() {
		len = 1;
		memset(a, 0, sizeof(a));
	}
	
	int& operator [] (int x) {
		return a[x];
	}
	
	void get() {
		static char st[100];
		gets(st);
		len = strlen(st);
		
		for (int i = 0; i < len; ++i) {
			a[i] = st[i] - '0';
		}
		reverse(a + 0, a + len);
	}
	
	bigNum operator = (const int b) {
		int c = b;
		if (c == 0) {
			zero();
			return *this;
		}
		while (c) {
			a[len] = c % MOD;
			len++;
			c /= MOD;
		}
		return *this;
	}
	
	bigNum operator + (bigNum b) {
		bigNum res;
		res.len = max(len, b.len) + 1;
		for (int i = 0; i < res.len; ++i) {
			res[i] += a[i] + b[i];
			res[i + 1] = res[i] / MOD;
			res[i] = res[i] % MOD;
		}
		while (res[res.len - 1] == 0) res.len--;
		return res;
	}
	
	bigNum operator * (bigNum b) {
		bigNum res;
		res.zero();
		res.len = len + b.len + 2;
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < b.len; ++j)
				res[i + j] += a[i] * b[j];
		for (int i = 0; i < res.len; ++i) {
			res[i + 1] += res[i] / MOD;
			res[i] = res[i] % MOD;
		}
		while (res[res.len - 1] == 0) res.len--;
		return res;
	}
	
	bigNum operator / (int x) {
		bigNum res;
		res = *this;
		for (int i = res.len - 1; ~i; --i) {
			if (i) res[i - 1] += res[i] % x * MOD;
			res[i] = res[i] / x;
		}
		while (res[res.len - 1] == 0 && res.len) res.len--;
		return res;
	}
	
	bool operator < (bigNum b) const {
		if (len < b.len) return 1;
		if (len > b.len) return 0;
		for (int i = len - 1; ~i; --i) {
			if (a[i] < b[i]) return 1;
			if (a[i] > b[i]) return 0;
		}
		return 0;			
	}
	
	void print() {
		if (len == 0) {
			puts("0");
			return;
		}
		for (int i = len - 1; ~i; --i)
			printf("%d", a[i]);
		puts("");
	}
};

bool cmp(bigNum a, bigNum b) {
	if (a.len < b.len) return 1;
	if (a.len > b.len) return 0;
	for (int i = a.len - 1; ~i; --i) {
		if (a[i] < b[i]) return 1;
		if (a[i] > b[i]) return 0;
	}
	return 0;
}

int main() {
	bigNum tmp, tmp1, tmp2;
	
	puts("operator testing:");
	tmp = 123456789;
	tmp.print();
	
	tmp1 = 123456789;
	tmp2 = 997755331;
	
	tmp = tmp1 + tmp2;
	tmp.print();
	
	tmp = tmp1 * tmp2;
	tmp.print();
	
	tmp1.get();
	tmp = tmp / 12345;
	tmp.print();
	
	bigNum tmp[4];
	tmp[0] = 123456789;
	tmp[1] = 12345678;
	tmp[2] = 1234567890;
	tmp[3] = 1234567;
	
	puts("sorting with operator <:");
	sort(tmp, tmp + 4);
	for (int i = 0; i < 4; ++i)
		tmp[i].print();
	
	puts("sorting with cmp function:");
	sort(tmp, tmp + 4, cmp);
	for (int i = 0; i < 4; ++i)
		tmp[i].print();
	
	return 0;
}