//��ά���

/*
	����һ��n��m�е���������������q��������ÿ�����������������x1, y1, x2, y2, c������(x1, y1)��(x2, y2)��ʾһ���Ӿ�������Ͻ���������½����ꡣ
	ÿ��������Ҫ��ѡ�е��Ӿ����е�ÿ��Ԫ�ص�ֵ����c��
	���㽫���������в�����ľ��������
*/ 
#include <iostream>

using namespace std;

const int N = 10010; 

int a[N][N], b[N][N];

// ��ά��ֺ��� 
void insert(int x1, int y1, int x2, int y2, int c) {
	b[x1][y1] += c;
	b[x1][y2+1] -= c;
	b[x2+1][y1] -= c;
	b[x2+1][y2+1] += c;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	
	// ���������� 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			insert(i, j, i, j, a[i][j]);
			
	int x1, y1, x2, y2, c;
	while(q--) {
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}
	
	// ��ԭ����
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j]; 
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
		
	
	return 0;
			
	
}
