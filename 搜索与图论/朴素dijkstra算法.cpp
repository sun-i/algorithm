#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;

// 稠密图用邻接矩阵存储，稀疏图用邻接表存储 
int g[N][N];
int dist[N];
bool st[N];

int n, m;

int dijkstra() {
	// 初始化距离
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0; 
	
	
	for(int i = 1; i <= n; i++) {
		int t = -1;
		for(int j = 1; j <= n; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j]))
				t  = j;  // 找到目前到起点距离最短的点 
		st[t] = true;  // 将该点加入集合
		// 更新加入点 t 后每个点到起点的最短距离 
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
		g[a][b]  = min(g[a][b], c);  // 只保留权值最小的边 
	}
	
	cout << dijkstra() << endl;
	return 0; 
} 
