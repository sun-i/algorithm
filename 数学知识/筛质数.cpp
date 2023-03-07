#include <iostream>
using namespace std;

const int N = 10010;

int primes[N]; // �洢��������
int cnt; 
bool st[N];  // ��Ǹ�����û�б�ɸ�� 


// �ҳ��� 1 �� n ���������� 
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
