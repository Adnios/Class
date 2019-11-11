#include <cstdio>
#include <vector>

using namespace std;

int main() {
	vector <int> vec;
	
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	printf("%d %d %d\n", vec[0], vec[1], vec[2]);
	printf("size = %d\n", vec.size());
	
	vec.clear();
	printf("size = %d\n", vec.size());
	return 0;
}