#include <cstdio>
#include <set>

using namespace std;

int main() {
	set <int> s;
	
	s.clear();
	
	s.insert(1);
	s.insert(100);
	printf("%d\n", s.find(10) == s.end());

	s.insert(10);
	printf("%d\n", s.find(10) == s.end());
	
	s.erase(10);
	printf("%d\n", s.find(10) == s.end());
	
	return 0;
}