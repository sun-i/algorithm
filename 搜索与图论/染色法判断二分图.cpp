#include <iostream>
#include <cstring>
using namespace std;

const int N = 10010;
int h[N], e[N], ne[N], idx;
int color[N];  // -1 表示未染色，0表示白色，1表示黑色 
int n, m; 
void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

bool dfs(int u, int c) {
	color[u] = c;
	for(int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(color[j] == -1) {
			if(!dfs(j, !c))
				return false;
		}
		else if(color[j] == c)
			return false;
	}
	
	return true;
}

bool check() {
	memset(color, -1, sizeof color);
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		if(color[i] == -1) {
			if(!dfs(i, 0)) {
				flag = false;
				break;
			}
		}
	}
	
	return flag;
} 

int main() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	
	while(m--) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	
	cout << check();
	
	return 0;
	
}
