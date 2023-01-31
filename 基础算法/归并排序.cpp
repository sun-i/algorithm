#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int arr[N], tmp[N];
int n;

void merge_sort(int arr[], int l, int r) {
	// �ݹ�߽�
	if(l >= r)
		return;
		
	int mid = l + r >> 1;
	
	// �ݹ���������
	merge_sort(arr, l, mid);
	merge_sort(arr, mid + 1, r);
	
	int k = 0, i = l, j = mid + 1;
	// �ϲ�
	while(i <= mid && j <= r )
		if(arr[i] < arr[j]) 
			tmp[k++] = arr[i++];
		else 
			tmp[k++] = arr[j++];
			
	// ������ʣ��Ĳ���ֱ�ӽӵ����� 
	while(i <= mid) tmp[k++] = arr[i++];
	while(j <= r) tmp[k++] = arr[j++];
	
	// ������ԭ����
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
