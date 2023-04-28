#include <iostream>
using namespace std;

// ¿ìËÙÃÝ Çó a^k % p 
int qmi(int a, int k, int p) {
	int res = 1;
	while(k) {
		if(k & 1)
			res = res * a % p;
		k >>= 1;
		a = a * a % p;
	} 
	
	return res;
} 


int main() {
	int a, k, p;
	cin >> a >> k >> p;
	
	cout << qmi(a, k, p);
	
	return 0;
}
