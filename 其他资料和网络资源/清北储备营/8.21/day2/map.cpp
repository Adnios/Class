#include <cstdio>
#include <map>

using namespace std;

int main() {
	map <int, int> m;
	
	m.clear();
	
	m.insert(make_pair(1, 1));
	m[2] = 2;
	m[3] = 3;
	
	printf("%d %d\n", m.find(1) == m.end(), m.find(4) == m.end());
	printf("%d %d\n", m[1], m[2]);
	
	m.erase(1);
	printf("%d\n", m.find(1) == m.end());
	return 0;
}