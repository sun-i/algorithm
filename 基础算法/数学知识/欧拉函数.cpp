#include<iostream>
using namespace std;

// ŷ������
// �� 1-n ���� n ���ʵ����ĸ��� 

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
