//差分
/*
	差分可以看成前缀和的逆运算。
	差分数组：
	首先给定一个原数组a：a[1], a[2], a[3],,,,,, a[n];
	然后我们构造一个数组b ： b[1] ,b[2] , b[3],,,,,, b[i];
	使得 a[i] = b[1] + b[2]+ b[3] +,,,,,, + b[i]
	也就是说，a数组是b数组的前缀和数组，反过来我们把b数组叫做a数组的差分数组。换句话说，每一个a[i]都是b数组中从头开始的一段区间和。
	
	给a数组中的[ l, r]区间中的每一个数都加上c,只需对差分数组b做 b[l] + = c, b[r+1] - = c。时间复杂度为O(1)
*/

/*
	输入一个长度为n的整数序列。
	接下来输入m个操作，每个操作包含三个整数l, r, c，表示将序列中[l, r]之间的每个数加上c。
	请你输出进行完所有操作后的序列。
*/
#include <iostream>

using namespace std;

const int N = 10010;

int a[N], b[N];
 
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
		
	// 构造差分数组
	for(int i = 1; i <=n; i++) 
		b[i] = a[i] - a[i-1];
		
	int l , r, c;
	while(m--) {
		cin >> l >> r >>c;
		b[l] += c;
		b[r+1] -= c;
	}
	
	for(int i = 1; i <= n; i++) {
		a[i] = a[i-1] + b[i]; // 还原前缀和数组
		cout << a[i] << " "; 
	}
		
	return 0;
	
} 
