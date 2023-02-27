// 朴素并查集
// 用于判断两个数是否在同一个集合中、快速合并集合
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
// 存储每个点的祖宗节点 
int p[N];

// 返回每个点的祖宗节点 
int find(int x) {
	if(p[x] != x) // 不是祖宗节点
		p[x] = find(p[x]);
		
	return p[x];
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		p[i] = i;
		
	while(m--) {
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if(op[0] == 'M')
			p[find(a)] = find(b);
		else {
			if(find(a) == find(b))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		
	}
	
	return 0;
} 

/*
	一共有 n 个数，编号是 1 ～ n 最开始每个数各自在一个集合中。
	现在要进行 m 操作，操作共有两种：
	M a b，将编号为 a 和 b的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
	Q a b，询问编号为 a  和 b bb 的两个数是否在同一个集合中；
	
	输入格式
	第一行输入整数 n 和 m 。
	接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。
	
	输出格式
	对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。
	每个结果占一行。
*/

