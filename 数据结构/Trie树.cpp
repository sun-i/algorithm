// Trie 树
// 用于存储和查询字符串

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

// son[p][s] 用来存储 p 节点的 s 字母，cnt 用来存储以 p 节点结尾的字符串数量 
int son[N][26], cnt[N], idx;
char str[N];

void insert(char str[]) {
	int p = 0;
	for(int i = 0; str[i]; i++) {
		int u = str[i] - 'a'; 
		if(!son[p][u])
			son[p][u] = ++ idx;  // 没有子树则创建
		p = son[p][u];
	}
	
	cnt[p] ++;
} 


int query(char str[]) {
	int p = 0;
	for(int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if(!son[p][u])
			return -1;
		p = son[p][u];
	}
	
	return cnt[p];
}


int main() {
	int n;
	cin >> n;
	while(n--) {
		char op[2];
		cin >> op;
		if(op[0] == 'I') {
			cin >> str;
			insert(str);
		}
		else
		{
			cin >> str;
			cout << query(str) << endl;
		}
	} 
	
	return 0;
} 



/*
	维护一个字符串集合，支持两种操作：
	“I x”向集合中插入一个字符串x；
	“Q x”询问一个字符串在集合中出现了多少次。
	共有N个操作，输入的字符串总长度不超过 105，字符串仅包含小写英文字母。
	
	输入格式
	第一行包含整数N，表示操作数。
	接下来N行，每行包含一个操作指令，指令为”I x”或”Q x”中的一种。
	
	输出格式
	对于每个询问指令”Q x”，都要输出一个整数作为结果，表示x在集合中出现的次数。
	每个结果占一行。
*/
