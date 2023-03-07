#include <iostream> 
using namespace std;

// 欧几里得算法 求最大公约数
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
} 

int main() {
	int a, b;
	cin >> a >> b;
	cout << gcd(a, b) << endl;
	
	return 0; 
}
