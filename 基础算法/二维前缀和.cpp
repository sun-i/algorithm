// 二维前缀和
// S[i, j] = 第i行j列格子左上部分所有元素的和 

#include <iostream>
using namespace std;

const int N = 1000;


int a[N][N]; 
int s[N][N];

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
			
	// 初始化二维前缀和
	for(int i = 1; i <= n; i++) 
	for(int j = 1; j <= m; j++)
		s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
	
	int x1, y1, x2, y2; 
	while(q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		cout << s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1] << endl;
	}
} 
