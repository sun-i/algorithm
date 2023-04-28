#include <iostream>
#include <string.h>
using namespace std;

const int N = 200003; // 一般开大于数据范围两倍的最小质数
const int null = 0x3f3f3f3f; // 取一个不在数据范围内的数标记某个位置是否已经有数

int h[N];

// 返回 x 在哈希表中的位置 
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
