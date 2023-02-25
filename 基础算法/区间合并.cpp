// ����ϲ�
/* 
	��Ŀ����
		����n������[l, r]��
		�ϲ������н��������䡣
		����ϲ���ɺ�����������
		���磺[1,3]��[2,6]���Ժϲ�Ϊһ������[1,6]��

	�����ʽ
		��һ�а�������n��
		������n�У�ÿ�а����������� l �� r��

	�����ʽ
		��һ�У�����һ����������ʾ�ϲ�������ɺ�����������
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

typedef pair<int, int> PII;

vector<PII> segs;

void merge(vector<PII>& segs) {
	vector<PII> res;
	int st = -2e9, ed = -2e9; // ��ʼ�����Ҷ˵� 
	for(auto seg : segs) {
		if(ed < seg.first) {  // �޽��� 
			if(st != -2e9)
				res.push_back({st, ed});
			st = seg.first;
			ed = seg.second; 
		}
		else
			ed = max(seg.second, ed);  // �н��� 
	}
	
	if(st != -2e9)
		res.push_back({st, ed});
		
	segs = res;
}

int main() {
	int n;
	cin >> n;
	int l, r;
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		segs.push_back({l, r});
	}
	
	merge(segs);
	
	cout << segs.size();
	
	return 0;
}
