/*
	题目描述：
		假定有一个无限长的数轴，数轴上每个坐标上的数都是0。
		现在，我们首先进行 n 次操作，每次操作将某一位置x上的数加c。
		接下来，进行 m 次询问，每个询问包含两个整数l和r，你需要求出在区间[l, r]之间的所有数的和。

	输入格式
		第一行包含两个整数n和m。
		接下来 n 行，每行包含两个整数x和c。
		再接下里 m 行，每行包含两个整数l和r。

	输出格式
		共m行，每行输出一个询问中所求的区间内数字和。
*/

#include <iostream> 
#include <vector>
#include <algorithm> 
using namespace std;

typedef pair<int, int> PII;

const int N = 1e6;

vector<int> alls;  // 存储需要离散化的数 
int a[N]; // 存储离散化后的数 
int s[N]; // 前缀和 
vector<PII>  add, query;   

// 二分求出 x 对应的离散化后的值 
int find(int x) {
	int l = 0, r = alls.size()-1;
	while(l < r) {
		int mid = (l+r) >> 1;
		if(alls[mid] >= x)
			r = mid;
		else
			l = mid + 1;
	} 
	
	return r + 1; // 映射到 1, 2, 3, ... 
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
	
	sort(alls.begin(), alls.end());  // 排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());  // 去重 

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
