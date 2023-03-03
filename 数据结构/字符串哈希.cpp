#include <iostream>
using namespace std;

typedef unsigned long long ULL;

const int N = 100010;
const int P = 131;  // ���ݾ���ȡ131��Ϊ���ƿ��Ա����ͻ 
char str[N];
ULL h[N], p[N]; // p[N]�洢 P �� i �η���ULL 64 λ������������Ӷ��ﵽ mod 2^64 ������ 

// ���ش� l �� r ���Ӵ���Ӧ�� hash ֵ 
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
