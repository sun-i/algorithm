/*
	��Ŀ������
		�ٶ���һ�����޳������ᣬ������ÿ�������ϵ�������0��
		���ڣ��������Ƚ��� n �β�����ÿ�β�����ĳһλ��x�ϵ�����c��
		������������ m ��ѯ�ʣ�ÿ��ѯ�ʰ�����������l��r������Ҫ���������[l, r]֮����������ĺ͡�

	�����ʽ
		��һ�а�����������n��m��
		������ n �У�ÿ�а�����������x��c��
		�ٽ����� m �У�ÿ�а�����������l��r��

	�����ʽ
		��m�У�ÿ�����һ��ѯ������������������ֺ͡�
*/

#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6;

vector<int> alls;  // �洢��Ҫ��ɢ������ 
int a[N]; // �洢��ɢ������� 
int s[N]; // ǰ׺�� 
vector<PII>  add, query;   

// ������� x ��Ӧ����ɢ�����ֵ 
int find(int x) {
	int l = 0, r = alls.size()-1;
	while(l < r) {
		int mid = (l+r) >> 1;
		if(alls[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	} 
	
	return r + 1; // ӳ�䵽 1, 2, 3, ... 
}



int main() {
	int n,  m;
	cin >> n >> m; 
	int x, c;
	for(int i = 0; i < n; i++) {
		cin >> x >> c;
		add.push_back({x, c});
		alls.push_back(x);
	} 
	int l, r;
	for(int i = 0; i < m; i++) {
		cin >> l >> r;
		query.push_back({l, r});
		alls.push_back(l);
		alls.push_back(r); 
	}
	
	sort(alls.begin(), alls.end());  // ����
	alls.erase(unique(alls.begin(), alls.end()), alls.end());  // ȥ�� 

	for(auto item : add) {
		int x = find(item.first);
		a[x] += item.second;
	}
	
	for(int i = 1; i <= alls.size(); i++) 
		s[i] = s[i-1] + a[i];
		
	for(auto item : query) {
		l = find(item.first);
		r = find(item.second);
		
		cout << s[r] - s[l - 1] << endl;
	}  
	
	return 0;
}
