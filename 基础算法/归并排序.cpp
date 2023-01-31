#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int arr[N], tmp[N];
int n;

void merge_sort(int arr[], int l, int r) {
	// 递归边界
	if(l >= r)
		return;
		
	int mid = l + r >> 1;
	
	// 递归左右两边
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	// 合并
	while(i <= mid && j <= r )
		if(arr[i] < arr[j]) 
			tmp[k++] = arr[i++];
		else 
			tmp[k++] = arr[j++];
			
	// 将序列剩余的部分直接接到后面 
	while(i <= mid) tmp[k++] = arr[i++];
	while(j <= r) tmp[k++] = arr[j++];
	
	// 拷贝回原数组
	for(i = l, j = 0; i <= r; i++, j++)
		arr[i] = tmp[j]; 
			 
}

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	merge_sort(arr, 0, n - 1);
	
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
