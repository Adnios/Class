#include <cstdio>
#include <queue>

using namespace std;

int main() {
	queue <int> q;
	
	while (!q.empty()) q.pop(); //clear
	
	q.push(1);
	q.push(2);
	q.push(3);
	printf("%d\n", q.front());
	printf("%d\n", q.back());
	
	q.pop();
	printf("%d\n", q.front());
	printf("%d\n", q.back());
	
	return 0;
}