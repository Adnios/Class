#include <cstdio>

using namespace std;
typedef double lf;

struct complex {
	lf x, y;
	complex() {
		x = y = 0;
	}
	complex(int _x, int _y) : x(_x), y(_y) {
	}
	
	complex operator + (const complex a) const {
		return complex(x + a.x, y + a.y);
	}
	
	complex operator - (const complex a) const {
		return complex(x - a.x, y - a.y);
	}
	
	complex operator * (const complex a) const {
		return complex(x * a.x - y * a.y, x * a.y + y * a.x);
	}
	
	complex operator / (const lf a) const {
		return complex(x / a, y / a);
	}
	
	complex operator / (const complex b) const {
		//ans = a / b = (a*c) / (b*c)
		complex c = complex(b.x, -b.y);
		return *this * c / (b.x * b.x + b.y * b.y);
	}
	
	void print() {
		printf("%.3lf + %.3lfi\n", x, y);
	}
};

int main() {
	complex tmp1(1, 2), tmp2(3, 4), tmp;
	
	tmp = tmp1 + tmp2;
	tmp.print();
	
	tmp = tmp1 - tmp2;
	tmp.print();
	
	tmp = tmp1 * tmp2;
	tmp.print();
	
	tmp = tmp / tmp2;
	tmp.print();
	return 0;
}