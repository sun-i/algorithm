#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N], s[N];

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++ ) 
		cin >> a[i];
		
	for(int i =1; i <= n; i++) {
		s[i] = s[i-1] + a[i];  // ����ǰ׺�� 
	} 
	int l, r;
	// [l, r] ֮�� = s[r] - s[l-1];
	while(m--) {
		scanf("%d %d", &l , &r);
		cout << s[r] - s[l-1] << endl;
	} 
	
	
	return 0;
}
