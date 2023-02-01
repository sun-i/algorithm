#include <iostream>

using namespace std; 

const int N = 1e6 + 10;

int n;
int arr[N]; 

// 快排
void quick_sort(int arr[], int l, int r) {
	// 递归边界
	if(l >= r)
		return;
		
	int i = l - 1, j = r + 1, x = arr[l + r >> 1];
	
	while(i < j) {
		// 左边全部小于 x 
		do i ++; while(arr[i] < x);
		//右边全部大于 x
		do j --; while(arr[j] > x);
		
		// 交换
		if(i < j)
			swap(arr[i], arr[j]); 
	} 
	// 递归左右 
	quick_sort(arr, l, j);
	quick_sort(arr, j + 1, r);
} 

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	// 快排
	quick_sort(arr, 0 , n-1);
	 
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
