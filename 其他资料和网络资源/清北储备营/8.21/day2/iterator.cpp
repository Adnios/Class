#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

int main() {
	srand(time(0));
	set<int> s;
	for (int i = 1; i <= 10; ++i) {
		int x = rand() % 100000;
		if (s.find(x) == s.end()) s.insert(x);
	}
	
	for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
		printf("%d ", *iter);
	}
	puts("");
	
	set<int>::iterator lower_iter = s.lower_bound(10000);
	set<int>::iterator upper_iter = s.upper_bound(10000);
	
	printf("%d %d\n", *lower_iter, *upper_iter);
	
	return 0;
}