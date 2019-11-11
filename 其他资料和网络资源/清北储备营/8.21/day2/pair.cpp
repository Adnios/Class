#include <cstdio>
#include <utility>

using namespace std;

int main() {
	pair <int, int> _pair1, _pair2;
	_pair1.first = 1, _pair1.second = 2;
	_pair2.first = 2, _pair2.second = 2;
	printf("%d\n", _pair1 < _pair2);
	return 0;
}