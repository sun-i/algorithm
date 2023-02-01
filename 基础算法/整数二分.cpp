#include <iostream>

using namespace std;

/*
	整数二分模板 
*/ 

bool check(int x) {/* ... */} // 检查 x 是否满足某种性质

// 区间 [l, r] 被划分成 [l, mid] [mid + 1, r] 时使用 
int bsearch_1(int l, int r) {
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	} 
}

// 区间 [l, r] 被划分成 [l, mid - 1], [mid, r] 时使用 
int bsearch_2(int l, int r) {
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid))
			l = mid;
		else
			r = mid - 1; 
	}
}



/*  **模板题--数的范围** 
	给定一个按照升序排列的长度为 n 的整数数组，以及 q 个查询。
	对于每个查询，返回一个元素 k 的起始位置和终止位置（位置从0开始计数）。
	如果数组中不存在该元素，则返回 
	
	**输入**
	第一行包含整数n和q，表示数组长度和询问个数。
	第二行包含n个整数（均在1~10000范围内），表示完整数组。
	接下来q行，每行包含一个整数k，表示一个询问元素。 
	
	**输出**
	共q行，每行包含两个整数，表示所求元素的起始位置和终止位置。
	如果数组中不存在该元素，则返回 "-1 -1" 
*/ 

const int N = 1e6 + 10;
int n, q;
int arr[N];

int main() {
	scanf("%d %d", &n, &q);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	int k;
		
	while(q--) {
		scanf("%d", &k);
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = l + r >> 1;
			// 查找第一个位置，将区间分成 [l, mid] [mid + 1, r]
			if(arr[mid] >= k)
				r = mid;
			else
				l = mid + 1;
		}
		
		// 查找失败 
		if(arr[l] != k)
			cout << "-1 -1" << endl;
		else {
			cout << l << " ";
			l = 0, r = n - 1;
			// 查找第二个位置，将区间分成 [l, mid - 1] [mid, r]
			while(l < r) {
				int mid = l + r + 1 >> 1;
				if(arr[mid] <= k)
					l = mid;
				else
					r = mid - 1;
			}
			
			cout << l << endl;
		}
	}
	return 0;
}
