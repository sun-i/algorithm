#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;

int h[N], e[N], w[N], ne[N], idx, dist[N];
bool st[N];
int n, m;

void add(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int spfa() {
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	
	while(q.size()) {
		int t = q.front();
		q.pop();
		st[t] = false;
		
		for(int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if(!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
				
		}
	}
	
	if(dist[n] == 0x3f3f3f3f)
		return -1;
	else 
		return dist[n];
}

int main() {
	memset(h, -1, sizeof h);
	cin >> n >> m;
	while(m--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	cout << spfa() << endl;
	
	return 0;
}
