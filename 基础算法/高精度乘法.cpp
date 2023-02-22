#include <iostream>
#include <vector>

using namespace std;

vector<int> mul(vector<int> &a, int b) {
	vector<int> res;
	int t = 0; // ½øÎ» 
	for(int i = 0; i < a.size(); i++) {
		t += a[i] * b;
	 	res.push_back(t % 10);
	 	t /= 10;
	}
	
	if(t)
		res.push_back(t);
		
	return res;
} 

int main() {
	vector<int> a;
	int b;
	string s;
	cin >> s >> b;
	
	for(int i = s.size() - 1; i >= 0; i-- )
		a.push_back(s[i] - '0');
		
	vector<int> res = mul(a, b);
	
	for(int i = res.size() - 1; i >= 0; i-- )
		cout << res[i];
		
	return 0;
} 
