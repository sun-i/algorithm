#include <iostream>
#include <algorithm>
using namespace std; 

const int N = 100010;

int h[N], size;

 
void down(int u) {
	int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u) {
	while(u / 2 && h[u/2] > h[u]) {
		swap(h[u/2], h[u]);
		u /= 2;
	}
}

void insert(int x) {
	size ++;
	h[size] = x;
	up(x);
}

void remove(int x) {
	h[x] = h[size];
	up(x);
	down(x);
}

void change(int x, int k) {
	h[x] = k;
	up(x);
	down(x); 
} 


int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> h[i];
		
	size = n;
		
	// O(n) ���ӶȽ���
	for(int i = n / 2; i ; i--) 
		down(i);
		
	// �����Сֵ
	cout << h[1];
	return 0; 
}
