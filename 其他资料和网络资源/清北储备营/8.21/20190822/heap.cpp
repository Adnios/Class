#include <cstdio>
#include <algorithm>

using namespace std;

int cnt;

struct heap {
	int value;
	int depth;
	int lson, rson;
} h[10000];

int new_heap(int x) {
	++cnt;
	h[cnt].lson = h[cnt].rson = h[cnt].depth = 0;
	h[cnt].value = x;
	return cnt;
}

int merge(int x, int y) {
	if (x == 0 || y == 0) return x + y;
	if (h[x].value > h[y].value) swap(x, y);
	h[x].rson = merge(h[x].rson, y);
	if (h[h[x].lson].depth < h[h[x].rson].depth)
		swap(h[x].lson, h[x].rson);
	h[x].depth = h[h[x].rson].depth + 1;
	return x;
}

int top(int x) {
	return h[x].value;
}

int pop(int x) {
	return merge(h[x].lson, h[x].rson);
}

int main() {
	int _h, tmp;
	
	//new heap with 100
	_h = new_heap(100);
	
	//insert 10
	tmp = new_heap(10);
	_h = merge(_h, tmp);
	
	//insert 25
	tmp = new_heap(25);
	_h = merge(_h, tmp);
	
	//insert 20
	tmp = new_heap(20);
	_h = merge(_h, tmp);
	
	printf("%d\n", top(_h));
	
	//pop the smallest
	_h = pop(_h);	
	printf("%d\n", top(_h));
	
	
	return 0;
}