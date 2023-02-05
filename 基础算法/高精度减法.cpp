#include <iostream>
#include <vector>

using namespace std;

// �ж� A >= B
bool cmp(vector<int> &A, vector<int> &B) {
	if(A.size() != B.size()) // λ����Ĵ� 
		return A.size() > B.size();
		
	for(int i = A.size() - 1; i >= 0; i --)
		if(A[i] != B[i]) // �����λ��ʼ�Ƚ� 
			return A[i] > B[i];
			
	return true; // ÿһλ����ͬ���� A = B������ A >= B 
} 

// �߾��ȼ��� 
vector<int> sub(vector<int> &A, vector<int> &B) {
	vector<int> res;
	
	int t = 0; // ��λ 
	for(int i = 0; i < A.size(); i ++) {
		t = A[i] - t;  // ��ȥ��λ
		if(i < B.size())
			t -= B[i];
		
		// ��� A[i] > B[i]  t > 0  ֱ��ȡ t 
		// ��� A[i] < B[i]  t < 0  ��Ҫ��λ ��ȡ t + 10 
		res.push_back((t + 10) % 10);
		
		if(t < 0)
			t = 1; // ��Ҫ��ǰ��λ
		else
			t = 0; 
	}
	
	while(res.size() > 1 && res.back() == 0)
		res.pop_back();  // ȥ������� 0 
	
	return res;
}

int main() {
	string a, b;
	cin >> a >> b;  // "123456"
	
	vector<int> A, B;
	// ����洢��������  [6, 5, 4, 3, 2, 1] 
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
