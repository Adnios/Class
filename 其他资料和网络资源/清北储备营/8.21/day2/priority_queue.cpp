#include <cstdio>
#include <queue>

using namespace std;

int main() {
	priority_queue <int> q; //大根堆
	//priority_queue <int, vector<int>, greater<int> > q; //小根堆
	
	while (!q.empty()) q.pop(); //clear
	
	q.push(1);
	printf("%d\n", q.top());
	q.push(2);
	printf("%d\n", q.top());
	q.push(3);
	printf("%d\n", q.top());
	q.push(4);
	printf("%d\n", q.top());
	
	q.pop();
	printf("%d\n", q.top());
	
	return 0;
}