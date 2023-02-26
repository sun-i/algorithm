// 单调队列
// 滑动窗口求最值 
//给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int a[N], q[N]; 

int main() {
	int hh = 0, tt = -1;
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]); 
	
	for(int i = 0; i < n; i++) {
		// 队列为空 ||  队头超出滑动窗口范围 
		if(hh <= tt && i - k + 1 > q[hh]) 
			hh ++; 
		while(hh <= tt && a[q[tt]] >= a[i])
			tt --;
		
		q[++tt] = i;
		if(i >= k - 1)
			printf("%d ", a[q[hh]]);
	}
	
	cout << endl;
	hh = 0, tt = -1; 
	for(int i = 0; i < n; i++) {
		// 队列为空 ||  队头超出滑动窗口范围 
		if(hh <= tt && i - k + 1 > q[hh]) 
			hh ++; 
		while(hh <= tt && a[q[tt]] <= a[i])
			tt --;
		
		q[++tt] = i;
		if(i >= k - 1)
			printf("%d ", a[q[hh]]);
	}
	
	return 0;
}




