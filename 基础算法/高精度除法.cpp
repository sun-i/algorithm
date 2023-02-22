#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

// A / b ���� res ������ r 
vector<int> div(vector<int> &a, int b, int &r) {
	vector<int> res;
	r = 0;
	
	for(int i = a.size() - 1; i >= 0; i--) {
		r = r * 10 + a[i];
		res.push_back(r / b);
		r = r % b;
	} 
	
	// ��ʱ���λ��ǰ�棬��Ҫ��ת 
	reverse(res.begin(), res.end());
	
	// ȥ��ǰ��0 
	while(res.size() > 1 && res.back() == 0)
		res.pop_back(); 
	
	return res;
} 

int main() {
	vector<int> a;
	int b, r; // ���� 
	string s;
	cin >> s >> b;
	
	for(int i = s.size() - 1; i >= 0; i-- )
		a.push_back(s[i] - '0');
		
	vector<int> res = div(a, b, r); 
	
	for(int i = res.size() - 1; i >= 0; i-- )
		cout << res[i];
	cout << endl << r << endl;
		
	return 0;
} 
