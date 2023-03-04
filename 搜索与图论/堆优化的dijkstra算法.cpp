#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> PII;
const int N = 100010;

int h[N], e[N], ne[N], idx;  // 稀疏图用邻接表存储 
int dist[N], w[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}


// 堆优化的 dijkstra 算法 
int dijkstra() {
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII> , greater<PII> > heap;
	heap.push({0, 1});
	dist[1] = 0;
	
	while(heap.size()) {
		auto t = heap.top();
		heap.pop();
		
		int ver = t.second;
		int distence = t.first;
		if(st[ver])
			continue;
		st[ver] = true;
		
		for(int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > distence + w[i]) {
				dist[j] = distence + w[i];
				heap.push({dist[j], j});
			}
		}
	}
	
	if(dist[n] == 0x3f3f3f3f)
			return -1;
	else
		return dist[n];
	
	
}

int main() {
	cin >> n >> m;
	
	memset(h, -1, sizeof h);
	
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	cout << dijkstra() << endl;
	
}

 
