// ���ز��鼯
// �����ж��������Ƿ���ͬһ�������С����ٺϲ�����
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
// �洢ÿ��������ڽڵ� 
int p[N];

// ����ÿ��������ڽڵ� 
int find(int x) {
	if(p[x] != x) // �������ڽڵ�
		p[x] = find(p[x]);
		
	return p[x];
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		p[i] = i;
		
	while(m--) {
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if(op[0] == 'M')
			p[find(a)] = find(b);
		else {
			if(find(a) == find(b))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		
	}
	
	return 0;
} 

/*
	һ���� n ����������� 1 �� n �ʼÿ����������һ�������С�
	����Ҫ���� m �����������������֣�
	M a b�������Ϊ a �� b�����������ڵļ��Ϻϲ�������������Ѿ���ͬһ�������У���������������
	Q a b��ѯ�ʱ��Ϊ a  �� b bb ���������Ƿ���ͬһ�������У�
	
	�����ʽ
	��һ���������� n �� m ��
	������ m �У�ÿ�а���һ������ָ�ָ��Ϊ M a b �� Q a b �е�һ�֡�
	
	�����ʽ
	����ÿ��ѯ��ָ�� Q a b����Ҫ���һ���������� a �� b ��ͬһ�����ڣ������ Yes��������� No��
	ÿ�����ռһ�С�
*/

