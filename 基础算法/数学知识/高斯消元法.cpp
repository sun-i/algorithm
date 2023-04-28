#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 10010;
const int eps = 1e-6;

double a[N][N];  // ������� 
int n;

int guass() {
	int c, r;
	for(c = 0, r = 0; c < n; c++) {
		int t = r;
		for(int i = r; i < n; i++)
			if(fabs(a[i][c]) > fabs(a[t][c]))
				t = i;  // �ҵ���ǰ�о���ֵ����һ�� 
		if(fabs(a[t][c]) < eps)
			continue;  // ���Ϊ 0 ��˵����ǰ��ȫΪ 0 ��������һ�� 
			
		for(int i = c; i <= n; i++)
			swap(a[t][i], a[r][i]);  // ������ֵ����һ�л�����һ��
		
		for(int i = n; i >= c; i--) {
			a[r][i] /= a[r][c];  // ��ǰ�е���λ��� 1 
		} 
		
		for(int i = r + 1; i < n; i++) {
			// �õ�ǰ������ÿһ�еĵ�ǰ�б�� 0 
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
				return 2;  // �޽� 
		return 1;  // ���������� 
	} 
	
	return 0;  // ��Ψһ�� 
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
 
