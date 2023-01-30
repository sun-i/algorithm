#include <iostream>

using namespace std; 

const int N = 1e6 + 10;

int n;
int arr[N]; 

// ����
void quick_sort(int arr[], int l, int r) {
	// �ݹ�߽�
	if(l >= r)
		return;
	
	int i = l - 1, j = r + 1, x = arr[(l + r) >> 1];
		
	while(i < j) {
		
		// ���ʼ�մ��ڻ���� x 
		do i ++; while(x > arr[i]);
		
		// �ұ�ʼ��С�ڻ���� x 
		do j --; while(x < arr[j]);
		
		// ����  
		if(i < j) swap(arr[i], arr[j]); 
	} 
	
	// �ݹ���������
	quick_sort(arr, l, j);
	quick_sort(arr, j+1, r); 
} 

int main() {
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
		
	// ����
	quick_sort(arr, 0 , n-1);
	 
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
