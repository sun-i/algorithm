#include <iostream>
using namespace std;

// 求一个数的二进制表示的第 k 位
int getK(int n, int k) {
	// 将第 k 位移动到第 0 位再 & 1 取出第 0 位
	return n >> k & 1; 
}

// 求一个数的二进制表示的第一个 1 以及前面的 0   如 lowbit(101000) = 1000
int lowbit(int n) {
	return n & (-n);
} 

// 求一个数的二进制表示中 1 的个数
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
