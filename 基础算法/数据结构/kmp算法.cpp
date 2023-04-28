// kmp�㷨
/*	 
	����һ��ģʽ�� S ���Լ�һ��ģ�崮 P �������ַ�����ֻ������СдӢ����ĸ�Լ����������֡�
	ģ�崮 P ��ģʽ�� S �ж����Ϊ�Ӵ����֡�
	���ģ�崮 P ��ģʽ�� S �����г��ֵ�λ�õ���ʼ�±ꡣ
*/

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

char s[N], p[N];
int ne[N];

int main() {
	int n, m;
	cin >> n >> p + 1 >> m >> s + 1;
	
	// ��Next���� 
	for(int i = 2, j = 0; i <= n; i++) {
		while(j && p[i] != p[j+1])
			j = ne[j];
			
		if(p[i] == p[j+1])
			j++;
			
		ne[i] = j;
	}
	
	for(int i = 1, j = 0; i <= m; i++) {
		while(j && s[i] != p[j+1])
			j = ne[j];
			
		if(s[i] == p[j+1])
			j++;
		
		if(j == n) {
			j = ne[j];
			printf("%d ", i - n);
		}
	}
	
	return 0;
}
