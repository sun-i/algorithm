#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;

// ����ͼ���ڽӾ���洢��ϡ��ͼ���ڽӱ�洢 
int g[N][N];
int dist[N];
bool st[N];

int n, m;

int dijkstra() {
	// ��ʼ������
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; 
	
	
	for(int i = 1; i <= n; i++) {
		int t = -1;
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t  = j;  // �ҵ�Ŀǰ����������̵ĵ� 
		st[t] = true;  // ���õ���뼯��
		// ���¼���� t ��ÿ���㵽������̾��� 
		for(int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		} 
	}
	
	if(dist[n] == 0x3f3f3f3f)
		return -1;
	else
		return dist[n]; 
}

int main() {
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	
	for(int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b]  = min(g[a][b], c);  // ֻ����Ȩֵ��С�ı� 
	}
	
	cout << dijkstra() << endl;
	return 0; 
} 
