#include <iostream>
using namespace std;


// 扩展欧几里得算法
// 求 a*x + b*y = res  res 为 a b 的最小公约数 
int exgcd(int a, int b, int &x, int &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	} 
	
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	
	return d;
}

int main() {
	int a, b;
	cin >> a >> b;
	int x, y;
	exgcd(a, b, x, y);
	cout << x << " " << y << endl;
	
	return 0;
}
