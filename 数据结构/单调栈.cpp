// ����ջ
//����һ������Ϊ N ���������У����ÿ������ߵ�һ������С�������������������� -1��
#include <iostream>
using namespace std;

const int N = 10010;

int s[N], tt;

int main() {
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		while(tt && s[tt] >= x) tt --;
		if(tt) 
			cout << s[tt] << " ";
		else
			cout << -1 << " ";
			
		s[++ tt] = x;
	}
	
	return 0;
}
