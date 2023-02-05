#include <iostream>
#include <vector>

using namespace std;

// 判断 A >= B
bool cmp(vector<int> &A, vector<int> &B) {
	if(A.size() != B.size()) // 位数多的大 
		return A.size() > B.size();
		
	for(int i = A.size() - 1; i >= 0; i --)
		if(A[i] != B[i]) // 从最高位开始比较 
			return A[i] > B[i];
			
	return true; // 每一位都相同，即 A = B，满足 A >= B 
} 

// 高精度减法 
vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> res;
	
	int t = 0; // 借位 
	for(int i = 0; i < A.size(); i ++) {
		t = A[i] - t;  // 减去借位
		if(i < B.size())
			t -= B[i];
		
		// 如果 A[i] > B[i]  t > 0  直接取 t 
		// 如果 A[i] < B[i]  t < 0  需要借位 则取 t + 10 
		res.push_back((t + 10) % 10);
		
		if(t < 0)
			t = 1; // 需要向前借位
		else
			t = 0; 
	}
	
	while(res.size() > 1 && res.back() == 0)
		res.pop_back();  // 去除多余的 0 
	
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
		
//	cout << cmp(A, B);
	vector<int> res; 
	if(cmp(A, B))
		res = sub(A, B);
	else {
		res = sub(B, A);
		cout << "-";
	}
		
	
	for(int i = res.size() - 1; i >= 0; i --)
		cout << res[i];
	
	return 0;
} 
