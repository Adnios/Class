#include <cstdio>
#include <deque>

using namespace std;

int main() {
	deque <int> d;
	
	d.clear();
	
	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	printf("%d\n", d.front());
	printf("%d\n", d.back());
	
	d.pop_back();
	printf("%d\n", d.front());
	printf("%d\n", d.back());
	
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);
	printf("%d\n", d.front());
	printf("%d\n", d.back());
	
	d.pop_front();
	printf("%d\n", d.front());
	printf("%d\n", d.back());
	
	return 0;
}