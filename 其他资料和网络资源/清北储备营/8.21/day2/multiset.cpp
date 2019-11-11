#include <cstdio>
#include <set>

using namespace std;

int main() {
	multiset <int> m;
	
	m.clear();
	
	m.insert(1);
	m.insert(100);
	printf("%d\n", m.find(10) == m.end());

	m.insert(10);
	printf("%d\n", m.find(10) == m.end());
	
	m.insert(10);
	printf("%d\n", m.count(10));
	
	m.erase(10);
	printf("%d\n", m.find(10) == m.end());
	printf("%d\n", m.count(10));
	
	
	return 0;
}