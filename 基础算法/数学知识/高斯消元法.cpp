#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 10010;
const int eps = 1e-6;

double a[N][N];  // 增广矩阵 
int n;

int guass() {
	int c, r;
	for(c = 0, r = 0; c < n; c++) {
		int t = r;
		for(int i = r; i < n; i++)
			if(fabs(a[i][c]) > fabs(a[t][c]))
				t = i;  // 找到当前列绝对值最大的一行 
		if(fabs(a[t][c]) < eps)
			continue;  // 如果为 0 则说明当前列全为 0 ，进入下一列 
			
		for(int i = c; i <= n; i++)
			swap(a[t][i], a[r][i]);  // 将绝对值最大的一行换到第一行
		
		for(int i = n; i >= c; i--) {
			a[r][i] /= a[r][c];  // 当前行的首位变成 1 
		} 
		
		for(int i = r + 1; i < n; i++) {
			// 让当前行下面每一行的当前列变成 0 
			if(fabs(a[i][c]) > eps)
				for(int j = n; j >= c; j--) {
					a[i][j] -= a[r][j] * a[i][c];
				}
		} 
		
		r++; 
				
	} 
	
	for(int i = n-1; i >= 0; i--) {
		for(int j = i+1; j < n; j++) {
			a[i][n] -= a[i][j] * a[j][n];
		}
	}
	
	if(r < n) {
		for(int i = r; i < n; i++)
			if(fabs(a[i][n]) > eps)
				return 2;  // 无解 
		return 1;  // 有无穷多组解 
	} 
	
	return 0;  // 有唯一解 
}

int main() {
	cin >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= n; j++)
			cin >> a[i][j];
			
	int t = guass();
	
	if(t == 1)
		cout << 0 << endl;
	else if(t == 2)
		cout << -1 << endl;
	else {
		for(int i = 0; i < n; i++)
			printf("x%d=%.2lf\n", i+1, a[i][n]);
	}	 
	
	return 0;
}
 
