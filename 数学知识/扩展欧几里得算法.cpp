#include <iostream>
using namespace std;


// ��չŷ������㷨
// �� a*x + b*y = res  res Ϊ a b ����С��Լ�� 
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
