#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> primes;
 
// �Գ����� n ������Լ�� 
vector<int> get_divisors(int n) {
	vector<int> res;
	for(int i = 1; i <= n / i; i++) {
		if(n % i == 0) {
			res.push_back(i);
			if( i != n / i)
				res.push_back(n / i);
		}
	} 
	
	sort(res.begin(), res.end());
	return res;
}

// �� n ��Լ������ 
int count_divisors(int n) {

	for(int i = 2; i <= n / i; i++) {
		if(n % i == 0) {
			n /= i;
			primes[i] ++;
		}
	}
	if(n > 1) primes[n] ++;
	int res = 1;
	for(auto prime : primes)
		res *= (prime.second + 1);
		
	return res; 
} 

// �� n ��Լ��֮��
int sum_divisors(int n) {
	int res = 1;
	for(auto prime : primes) {
		int t = 1, p = prime.first, a = prime.second;
		while(a--)
			t = (t * p + 1);
		res *= t;
	}
	
	return res;
}

int main() {
	int n;
	cin >> n;
	auto res = get_divisors(n);
	for(auto i : res)
		cout << i << " ";
		
	cout << endl; 

	cout << "count: " << count_divisors(n) << endl;
	cout << "sum: " << sum_divisors(n) << endl;
		
	return 0;	
} 
