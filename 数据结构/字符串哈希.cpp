#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010;
const int P = 131;  // 根据经验取131作为进制可以避免冲突 
char str[N];
ULL h[N], p[N]; // p[N]存储 P 的 i 次方，ULL 64 位，超出会溢出从而达到 mod 2^64 的作用 

// 返回从 l 到 r 的子串对应的 hash 值 
ULL get(int l, int r) {
	return h[r] - h[l-1] * p[r-l+1];
}

int main() {
	int n, m;
	scanf("%d %d %s", &n, &m, str+1);
	p[0] = 1;
	for(int i = 1; i <= n; i++) {
		p[i] = p[i-1] * P;
		h[i] = h[i-1] * P + str[i];
	}
	int l1, r1, l2, r2;
	while(m --) {
		cin >> l1 >> r1 >> l2 >> r2;
		if(get(l1, r1) == get(l2, r2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl; 
	}
	
	return 0;
}
