#include <iostream> 
#include <cstring>
using namespace std;

const int N = 10010;

int h[N], e[N], ne[N], idx;
int match[N];  // 存储当前匹配的结点编号 
bool st[N]; 
int n1, n2, m;

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

bool find(int x) {
	for(int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			st[j] = true;
			if(match[j] == 0 || find(j)) {
				match[j] = x;
				return true;
			}
		}
	}
	
	return false;
	
} 

int main() {
	cin >> n1 >> n2 >> m;
	
	memset(h, -1, sizeof h);
	
	while(m--) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	
	int cnt = 0;
	for(int i = 1; i <= n1; i++) {
		memset(st, false, sizeof st);
		if(find(i))
			cnt ++;
	}
	
	cout << cnt << endl;
	
	return 0;
}
