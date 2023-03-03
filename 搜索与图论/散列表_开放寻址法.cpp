#include <iostream>
#include <string.h>
using namespace std;

const int N = 200003; // һ�㿪�������ݷ�Χ��������С����
const int null = 0x3f3f3f3f; // ȡһ���������ݷ�Χ�ڵ������ĳ��λ���Ƿ��Ѿ�����

int h[N];

// ���� x �ڹ�ϣ���е�λ�� 
int find(int x) {
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x) {
		k++;
		if(k == N)
			k = 0;
	} 
	
	return k;
}

int main() {
	int n;
	cin >> n;
	memset(h, 0x3f, sizeof h);
	while(n--) {
		char op[2];
		int x;
		scanf("%s %d", op, &x);
		int k = find(x);
		if(op[0] == 'I')
			h[k] = x;
		else {
			if(h[k] == x)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
			
	}
	
	return 0;
} 
