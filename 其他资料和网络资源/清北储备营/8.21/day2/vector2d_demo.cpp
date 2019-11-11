#include <cstdio>

using namespace std;
typedef double lf;

struct vector2d {
	lf x, y;
	vector2d() {
	}
	vector2d(int _x, int _y) : x(_x), y(_y) {
	}
	
	friend vector2d operator + (const vector2d a, const vector2d b);
	friend vector2d operator - (const vector2d a, const vector2d b);
	friend lf operator * (const vector2d a, const vector2d b);
	friend lf operator / (const vector2d a, const vector2d b);
	
	void print() {
		printf("(%.3lf, %.3lf)\n", x, y);
	}
};

vector2d operator + (const vector2d a, const vector2d b) {
	return vector2d(a.x + b.x, a.y + b.y);
}

vector2d operator - (const vector2d a, const vector2d b) {
	return vector2d(a.x - b.x, a.y - b.y);
}

lf operator * (const vector2d a, const vector2d b) {
	return a.x * b.x + a.y * b.y;
}

lf operator / (const vector2d a, const vector2d b) {
	return a.x * b.y - a.y * b.x;
}


int main() {
	vector2d tmp1(1, 2), tmp2(3, 4), tmp;
	lf TMP;
	
	tmp = tmp1 + tmp2;
	tmp.print();
	
	tmp = tmp1 - tmp2;
	tmp.print();
	
	printf("%.3lf\n%.3lf\n", tmp1 * tmp2, tmp1 / tmp2);	
	
	return 0;
}