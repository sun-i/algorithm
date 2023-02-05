#include <iostream>
#include <vector>

using namespace std;

// 高精度加法
vector<int> add(vector<int> &A, vector<int> &B) {
	// 结果数组 
	vector<int> res;
	
	int t = 0; // 进位
	for(int i = 0; i < A.size() || i < B.size(); i ++) {
		// 每一位都是 A[i] + B[i] + t 
		if(i < A.size())
			t += A[i];
		if(i < B.size())
			t += B[i];
		
		res.push_back(t % 10);  // 保留个位
		
		t /= 10; // 进位 
	} 
	if(t) // 最高位有进位 
		res.push_back(1);
		
	return res; 
} 

int main() {
	string a, b;
	cin >> a >> b;  // "123456"
	
	vector<int> A, B;
	// 倒叙存储在数组中  [6, 5, 4, 3, 2, 1] 
	for(int i = a.size() - 1; i >= 0; i --)
		A.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i --)
		B.push_back(b[i] - '0');
		
	vector<int> res = add(A, B);
	
	for(int i = res.size() - 1; i >= 0; i --)
		cout << res[i];
	
	return 0;
} 
