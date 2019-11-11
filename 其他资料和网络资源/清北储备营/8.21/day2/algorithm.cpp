#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int x = 1, y = 2;
	
	printf("%d\n", min(x, y));
	printf("%d\n", max(x, y));
	
	swap(x, y);
	printf("%d %d\n", x, y);
	
	int a[10];
	a[1] = 5;
	a[2] = 6;
	a[3] = 3;
	a[4] = 4;
	
	sort(a + 1, a + 4 + 1); //end should be a+4 + 1!!!
	printf("%d %d %d %d\n", a[1], a[2], a[3], a[4]);
	
	reverse(a + 1, a + 4 + 1);
	printf("%d %d %d %d\n", a[1], a[2], a[3], a[4]);
	
	random_shuffle(a + 1, a + 4 + 1);
	printf("%d %d %d %d\n", a[1], a[2], a[3], a[4]);
	
	puts("");
	a[1] = 1, a[2] = 2, a[3] = 3;
	for (int i = 1; i <= 6; ++i) {
		printf("%d %d %d\n", a[1], a[2], a[3]);
		next_permutation(a + 1, a + 3 + 1);
	}
	return 0;
}