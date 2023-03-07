#include <iostream>
using namespace std;

bool is_prime(int n) {
	if(n < 2)
		return false;
	for(int i = 2; i <= n / i; i ++) {
		if(n % i == 0)
			return false;
	}
	
	return true;
} 

// 分解质因数 
void divide(int n) {
	for(int i = 2; i <= n / i; i++) {
		if(n % i == 0) {
			int s = 0;
			while(n % i == 0) {
				n /= i;
				s++;
			}
			
			cout << i << " " << s << endl;
		}
	} 
	
	if(n > 1)
		cout << n << " " << 1 << endl;
} 

int main() {
//	cout << is_prime(2) << endl;
	divide(18);
	
	return 0;
}
