#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;

int dist[N], backup[N];  // 用于备份 dist  保证每一次迭代只使用上一次迭代的结果

struct Edge{
	int a, b, w;
}edges[N]; 

int n, m, k;

// 求带负权且路径不超过 k 条边的最短路 
int bellman_ford() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	
	for(int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);  // 备份
		for(int j = 0; j < m; j++) {
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			dist[b] = min(dist[b], backup[a] + w); 
		}
	} 
	
	if(dist[n] > 0x3f3f3f3f / 2)
		return -1;
	else
		return dist[n];
}

int main() {
	cin >> n >> m >> k;
	
	for(int i = 0; i < m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}
	
	cout << bellman_ford() << endl;
	
	return 0;
}
