// kmp算法
/*	 
	给定一个模式串 S ，以及一个模板串 P ，所有字符串中只包含大小写英文字母以及阿拉伯数字。
	模板串 P 在模式串 S 中多次作为子串出现。
	求出模板串 P 在模式串 S 中所有出现的位置的起始下标。
*/

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

char s[N], p[N];
int ne[N];

int main() {
	int n, m;
	cin >> n >> p + 1 >> m >> s + 1;
	
	// 求Next数组 
	for(int i = 2, j = 0; i <= n; i++) {
		while(j && p[i] != p[j+1])
			j = ne[j];
			
		if(p[i] == p[j+1])
			j++;
			
		ne[i] = j;
	}
	
	for(int i = 1, j = 0; i <= m; i++) {
		while(j && s[i] != p[j+1])
			j = ne[j];
			
		if(s[i] == p[j+1])
			j++;
		
		if(j == n) {
			j = ne[j];
			printf("%d ", i - n);
		}
	}
	
	return 0;
}
