#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 10010, M = 2 * N;

int h[N], e[M], ne[M], idx;
int n;
int d[N]; // 记录每个节点的入度
queue<int> q, path;

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
	d[b] ++; // 入度加一 
}

bool topSort() {
	for(int i = 1; i <= n; i++)
		if(!d[i]) {
			q.push(i);
			path.push(i);
		}
			
		
	while(!q.empty()) {
		int t = q.front();
		q.pop();
		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			d[j]--;
			if(!d[j]) {
				q.push(j);
				path.push(j);
			}
		}
	}
	
	return path.size() == n;
}

int main() {
	memset(h, -1, sizeof h);
	int m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
//	topSort();
	if(topSort()) {
		while(!path.empty()) {
			cout << path.front() << " ";
			path.pop();
		}
	}
	else
		cout << "-1";
	
	return 0;
} 
