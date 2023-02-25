#include <iostream>
using namespace std;

// ��һ�����Ķ����Ʊ�ʾ�ĵ� k λ
int getK(int n, int k) {
	// ���� k λ�ƶ����� 0 λ�� & 1 ȡ���� 0 λ
	return n >> k & 1; 
}

// ��һ�����Ķ����Ʊ�ʾ�ĵ�һ�� 1 �Լ�ǰ��� 0   �� lowbit(101000) = 1000
int lowbit(int n) {
	return n & (-n);
} 

// ��һ�����Ķ����Ʊ�ʾ�� 1 �ĸ���
int countOne(int n) {
	int count = 0;
	while(n) {
		n = n - lowbit(n);
		count ++;
	}
	
	return count;
} 

int main() {
	int n = 9;
	cout << countOne(n);
//	for(int i = 3; i >= 0; i--) {
//		cout << getK(n, i);
//	}
	
	return 0;
}
