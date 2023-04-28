#include <iostream>
#include <algorithm> 
using namespace std;

const int N = 200010;

struct Edge{
	int a, b, w;
} edges[N];

int n, m, p[N];

bool cmp(struct Edge a, struct Edge b) {
	return a.w < b.w;
}

int find(int a) {
	if(a != p[a]) p[a] = find(p[a]);
	return p[a];
}

int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		p[i] = i;  // 初始化并查集
		
	for(int i = 0; i < m; i++) {
		cin >> edges[i].a >> edges[i].b >> edges[i].w;
	}
	
	sort(edges, edges+m, cmp);
	
	int res = 0, cnt = 0;
	for(int i = 0; i < m; i++) {
		int a = edges[i].a, b = edges[i].b, c = edges[i].w;
		a = find(a), b = find(b);
		if(a != b) {
			p[a] = b;
			res += c;
			cnt ++;
		}
	}
	
	if(cnt < n-1)
		cout << "impossible" << endl;
	else 
		cout << res << endl;
}
