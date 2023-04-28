// 用数组模拟双链表
#include <iostream>
using namespace std;

const int N = 10010;
 
int e[N], l[N], r[N], idx;

void init() {
	// 左端点为 0, 右端点为 1
	l[0] = 0;
	r[0] = 1;
	idx = 2; 
} 

// 在下标为 k 的点的右边插入 x 
void add(int k, int x) {
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx ++;
} 

// 删除下标为 k 的结点 
void remove(int k) {
	l[r[k]] = l[k];
	r[l[k]] = r[k]; 
} 

int main() {
	int M;
	cin >> M;
	init();
	string op;
	int x, k;
	while(M--) {
		cin >> op;
		if(op == "L") {
			cin >> x;
			add(0, x);
		} 
		else if(op == "R") {
			cin >> x;
			add(l[1], x);
		}
		else if(op == "D") {
			cin >> k;
			remove(k+1);
		}
		else if(op == "IL") {
			cin >> k >> x;
			add(l[k+1], x);
		} 
		else {
			cin >> k >> x;
			add(k+1, x);
		}
	}
	
	for(int i = r[0]; i != 1; i = r[i]) 
		cout << e[i] << " ";
}


/*
	实现一个双链表，双链表初始为空，支持 5 种操作：
	在最左侧插入一个数；
	在最右侧插入一个数；
	将第 k 个插入的数删除；
	在第 k 个插入的数左侧插入一个数；
	在第 k 个插入的数右侧插入一个数
	现在要对该链表进行 M 次操作，进行完所有操作后，从左到右输出整个链表。
	注意:题目中第 k 个插入的数并不是指当前链表的第 k 个数。例如操作过程中一共插入了 n 个数，则按照插入的时间顺序，这 n 个数依次为：第 1 个插入的数，第 2 22 个插入的数，…第 n nn 个插入的数。
	
	输入格式
	第一行包含整数 M MM，表示操作次数。
	接下来 M MM 行，每行包含一个操作命令，操作命令可能为以下几种：
	L x，表示在链表的最左端插入数 x xx。
	R x，表示在链表的最右端插入数 x xx。
	D k，表示将第 k kk 个插入的数删除。
	IL k x，表示在第 k kk 个插入的数左侧插入一个数。
	IR k x，表示在第 k kk 个插入的数右侧插入一个数。
	
	输出格式
	共一行，将整个链表从左到右输出。
	
	数据范围
	1 ≤ M ≤ 100000 1≤M≤1000001≤M≤100000
	所有操作保证合法。
*/ 
