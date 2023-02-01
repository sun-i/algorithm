#include <iostream>

using namespace std;

/*
	��������ģ�� 
*/ 

bool check(int x) {/* ... */} // ��� x �Ƿ�����ĳ������

// ���� [l, r] �����ֳ� [l, mid] [mid + 1, r] ʱʹ�� 
int bsearch_1(int l, int r) {
	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	} 
}

// ���� [l, r] �����ֳ� [l, mid - 1], [mid, r] ʱʹ�� 
int bsearch_2(int l, int r) {
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid))
			l = mid;
		else
			r = mid - 1; 
	}
}



/*  **ģ����--���ķ�Χ** 
	����һ�������������еĳ���Ϊ n ���������飬�Լ� q ����ѯ��
	����ÿ����ѯ������һ��Ԫ�� k ����ʼλ�ú���ֹλ�ã�λ�ô�0��ʼ��������
	��������в����ڸ�Ԫ�أ��򷵻� 
	
	**����**
	��һ�а�������n��q����ʾ���鳤�Ⱥ�ѯ�ʸ�����
	�ڶ��а���n������������1~10000��Χ�ڣ�����ʾ�������顣
	������q�У�ÿ�а���һ������k����ʾһ��ѯ��Ԫ�ء� 
	
	**���**
	��q�У�ÿ�а���������������ʾ����Ԫ�ص���ʼλ�ú���ֹλ�á�
	��������в����ڸ�Ԫ�أ��򷵻� "-1 -1" 
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
			// ���ҵ�һ��λ�ã�������ֳ� [l, mid] [mid + 1, r]
			if(arr[mid] >= k)
				r = mid;
			else
				l = mid + 1;
		}
		
		// ����ʧ�� 
		if(arr[l] != k)
			cout << "-1 -1" << endl;
		else {
			cout << l << " ";
			l = 0, r = n - 1;
			// ���ҵڶ���λ�ã�������ֳ� [l, mid - 1] [mid, r]
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
