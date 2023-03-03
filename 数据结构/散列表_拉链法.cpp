#include <iostream>
#include <string.h>
using namespace std;

const int N = 1e6 + 3;

int h[N], e[N], ne[N], idx;

void insert(int x) {
	// 考虑负数，需要 (% N + N） % N
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx++;
}

bool find(int x) {
	int k = (x % N + N) % N;
	for(int i = h[k]; i != -1; i = ne[i]) {
		if(e[i] == x)
			return true;
	}
	
	return false;
}

int main() {
	int n;
	cin >> n;
	memset(h, -1, sizeof h);
	int x;
	while(n--) {
		char op[2];
		scanf("%s %d", op, &x);
		if(op[0] == 'I')
			insert(x);
		else
			cout << find(x) << endl;
	}
	
	return 0;
} 
