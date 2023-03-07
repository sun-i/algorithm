#include <iostream>
using namespace std;

const int N = 10010;

int primes[N]; // 存储所有质数
int cnt; 
bool st[N];  // 标记该数有没有被筛掉 


// 找出从 1 到 n 的所有质数 
void get_prime(int n) {
	for(int i = 2; i <= n; i++) {
		if(!st[i]) {
			primes[cnt ++] = i;
			for(int j = i; j <= n; j += i)
				st[j] = true;
		}
	} 
}

int main() {
	int n;
	cin >> n;
	get_prime(n);
	cout << cnt << endl;
	for(int i = 0; i < cnt; i++) 
		cout << primes[i] << " ";
		
	return 0;
}
