// 区间合并
/* 
	题目描述
		给定n个区间[l, r]。
		合并所有有交集的区间。
		输出合并完成后的区间个数。
		例如：[1,3]和[2,6]可以合并为一个区间[1,6]。

	输入格式
		第一行包含整数n。
		接下来n行，每行包含两个整数 l 和 r。

	输出格式
		共一行，包含一个整数，表示合并区间完成后的区间个数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

typedef pair<int, int> PII;

vector<PII> segs;

void merge(vector<PII>& segs) {
	vector<PII> res;
	int st = -2e9, ed = -2e9; // 初始的左右端点 
	for(auto seg : segs) {
		if(ed < seg.first) {  // 无交集 
			if(st != -2e9)
				res.push_back({st, ed});
			st = seg.first;
			ed = seg.second; 
		}
		else
			ed = max(seg.second, ed);  // 有交集 
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
