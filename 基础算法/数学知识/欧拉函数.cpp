#include<iostream>
using namespace std;

// 欧拉函数
// 求 1-n 中与 n 互质的数的个数 

int main() {
	int n;
	cin >> n;
	int res = n;
	for(int i = 2; i <= n / i; i++) {
		if(n % 1 == 0) {
			res = res / i * (i-1);
			while(n % i == 0)
				n /= i; 
		}
	}
	if(n > 1) 
		res = res / n * (n-1);
	
	cout << res << endl;
	
	return 0;
} 
