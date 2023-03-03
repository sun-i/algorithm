#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 10010, M = 2 * N;

int  h[N], e[M], ne[M], idx;
bool st[N]; // ���ĳ���ڵ��Ƿ񱻱����� 
queue<int> q;
int d[N];

// ͼ�Ĵ洢 
// ��� a b �Ľ��֮���б� 
void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++; 
} 

// ͼ��������ȱ���
void dfs(int u) {
	st[u] = true;
	cout << u << " ";
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			dfs(j);
		}
			
	}
} 

// ͼ�Ĺ�����ȱ���
void bfs() {
	memset(d, -1, sizeof d);
	q.push(1);
	d[1] = 0;
	while(!q.empty()) {
		int t = q.front();
		cout << t << " ";
		q.pop();
		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(d[j] == -1) {
				d[j] = d[t] + 1;
				q.push(j);
			}
		}
	}
	
} 

int main() {
	memset(h, -1, sizeof h);
	int n;
	cin >> n;
	int a, b;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		add(a, b);
	}
	cout << "dfs: ";
	dfs(1);
	cout << endl << "bfs: ";
	bfs();
	return 0;
}
