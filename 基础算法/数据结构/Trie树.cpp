// Trie ��
// ���ڴ洢�Ͳ�ѯ�ַ���

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

// son[p][s] �����洢 p �ڵ�� s ��ĸ��cnt �����洢�� p �ڵ��β���ַ������� 
int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[]) {
	int p = 0;
	for(int i = 0; str[i]; i++) {
		int u = str[i] - 'a'; 
		if(!son[p][u])
			son[p][u] = ++ idx;  // û�������򴴽�
		p = son[p][u];
	}
	
	cnt[p] ++;
} 


int query(char str[]) {
	int p = 0;
	for(int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if(!son[p][u])
			return -1;
		p = son[p][u];
	}
	
	return cnt[p];
}


int main() {
	int n;
	cin >> n;
	while(n--) {
		char op[2];
		cin >> op;
		if(op[0] == 'I') {
			cin >> str;
			insert(str);
		}
		else
		{
			cin >> str;
			cout << query(str) << endl;
		}
	} 
	
	return 0;
} 



/*
	ά��һ���ַ������ϣ�֧�����ֲ�����
	��I x���򼯺��в���һ���ַ���x��
	��Q x��ѯ��һ���ַ����ڼ����г����˶��ٴΡ�
	����N��������������ַ����ܳ��Ȳ����� 105���ַ���������СдӢ����ĸ��
	
	�����ʽ
	��һ�а�������N����ʾ��������
	������N�У�ÿ�а���һ������ָ�ָ��Ϊ��I x����Q x���е�һ�֡�
	
	�����ʽ
	����ÿ��ѯ��ָ�Q x������Ҫ���һ��������Ϊ�������ʾx�ڼ����г��ֵĴ�����
	ÿ�����ռһ�С�
*/
