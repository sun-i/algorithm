//二维差分

/*
	输入一个n行m列的整数矩阵，再输入q个操作，每个操作包含五个整数x1, y1, x2, y2, c，其中(x1, y1)和(x2, y2)表示一个子矩阵的左上角坐标和右下角坐标。
	每个操作都要将选中的子矩阵中的每个元素的值加上c。
	请你将进行完所有操作后的矩阵输出。
*/ 
#include <iostream>

using namespace std;

const int N = 10010; 

int a[N][N], b[N][N];

// 二维差分函数 
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
	
	// 构造差分数组 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			insert(i, j, i, j, a[i][j]);
			
	int x1, y1, x2, y2, c;
	while(q--) {
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}
	
	// 还原数组
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j]; 
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
		
	
	return 0;
			
	
}
