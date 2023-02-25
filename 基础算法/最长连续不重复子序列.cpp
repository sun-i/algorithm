//最长连续不重复子序列
//给定一个长度为n的整数序列，请找出最长的不包含重复数字的连续区间，输出它的长度。

#include <iostream>
using namespace std;

const int N = 1e6;

int a[N], s[N];

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	int res = 0, j = 0;
	for(int i = 0; i < n; i++) {
		s[a[i]] ++; // 记录当前 [j, i] 区间中每个数字的数量
		while(s[a[i]] > 1) {
			s[a[j]] --; // 当加入 i 后 出现重复数字 a[i]，则 j 右移直到 a[i] 不再重复 
			j ++;
		} 
		
		res = max(res, i - j + 1); 
	}
	
	cout << res;
	
	return 0;
}

 
