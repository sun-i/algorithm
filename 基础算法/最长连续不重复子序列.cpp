//��������ظ�������
//����һ������Ϊn���������У����ҳ���Ĳ������ظ����ֵ��������䣬������ĳ��ȡ�

#include <iostream>
using namespace std;

const int N = 1e6;

int a[N], s[N];

int main() {
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> a[i];
		
	int res = 0, j = 0;
	for(int i = 0; i < n; i++) {
		s[a[i]] ++; // ��¼��ǰ [j, i] ������ÿ�����ֵ�����
		while(s[a[i]] > 1) {
			s[a[j]] --; // ������ i �� �����ظ����� a[i]���� j ����ֱ�� a[i] �����ظ� 
			j ++;
		} 
		
		res = max(res, i - j + 1); 
	}
	
	cout << res;
	
	return 0;
}

 
