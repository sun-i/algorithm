#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 110;
typedef pair<int, int> PII;

int g[N][N];  // �Թ���ͼ
int d[N][N];  // ÿ���㵽�Թ��ľ���

int n, m;

queue<PII> q;  

int bfs() {
	memset(d, -1, sizeof d);
	d[0][0] = 0;
	q.push({0, 0});
	int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
	while(!q.empty()) {
		auto t = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int x = t.first + dx[i], y = t.second + dy[i];
			if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) {
				d[x][y] = d[t.first][t.second] + 1;
				q.push({x, y});
			}
				
		} 
	}

	return d[n-1][m-1];
}

int main() {
	cin >> n >> m;
	
	for(int i = 0; i < n; i++ )
		for(int j = 0; j < m; j++)
			cin >> g[i][j];
			
	cout << bfs() << endl;
}

/*
	����һ��n*m�Ķ�ά�������飬������ʾһ���Թ���������ֻ����0��1������0��ʾ�����ߵ�·��1��ʾ����ͨ����ǽ�ڡ�
	�������һ����λ�����Ͻ�(1, 1)������֪����ÿ�ο������ϡ��¡���������һ�������ƶ�һ��λ�á�
	���ʣ����˴����Ͻ��ƶ������½�(n, m)����������Ҫ�ƶ����ٴΡ�
	���ݱ�֤(1, 1)����(n, m)��������Ϊ0����һ�����ٴ���һ��ͨ·��
	
	�����ʽ
	��һ�а�����������n��m��
	������n�У�ÿ�а���m��������0��1������ʾ�����Ķ�ά�����Թ���
	
	�����ʽ
	���һ����������ʾ�����Ͻ��ƶ������½ǵ������ƶ�������
*/

