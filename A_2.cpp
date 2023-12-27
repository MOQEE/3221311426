#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define inf 0x3f3f3f3f
const int N = 110;
/*
HARSH_1
后两位映射。
对电话号码后两位映射对应编号客户。
6
156 JASON
245 WEIBO
389 KO
399 KKK
2354 OP
4122 LSP
*/
struct PEOPLE {
	int numble;
	bool vis;
	string name;
} LIST[N];
int n, m;

vector<string> v[N];//拉链法。
PEOPLE g[N];//线性。
PEOPLE xg[N];//平方。

unordered_map<string, int> mp;

void LALIAN() {//拉链法。
	for (int i = 1; i <= n; i ++ ) {
		int num = LIST[i].numble % 100;
		string name = LIST[i].name;
		v[num].push_back(name);
	}	
}
void PIN_FANG_SEARCH()//平方。
{	
	int m = 100;
	for (int i = 1; i <= n; i ++ ) {
		int num = LIST[i].numble % 100;
		string name = LIST[i].name;
		while (g[num].vis) {
			num += num * num;
			num %= m;
		}
		g[num].vis = 1;
		g[num].name = name;
		g[num].numble = num;
	}
}
void X_SEARCH()//线性。
{
	int m = 100;
	for (int i = 1; i <= n; i ++ ) {
		int num = LIST[i].numble % 100;
		string name = LIST[i].name;
		while (g[num].vis) {
			num ++;
			num %= m;
		} 
		g[num].vis = 1;
		g[num].name = name;
		g[num].numble = num;
	}
}
void HARSH_1()
{
	//这里用拉链法求询问。
	LALIAN();
	cout << "HARSH_1" << endl;
	printf("输入查询次数\n");
	int m;
	cin >> m;
	printf("输入电话号码和姓名\n");
	while (m -- ) {
		int num;
		string name;
		cin >> num >> name;
		num %= 100;
		bool ok = false;
		for (auto t : v[num]) {
			if (t == name) {
				ok = true;
				break;
			}
		}
		if (ok) cout << "FIND IT" << endl;
		else cout << "NO PEOPLE" << endl;
	}
}

void HARSH_2()
{
	//numble->name;
	cout << "HARSH_2" << endl;
	for (int i = 1; i <= n; i ++ ) {
		string name = LIST[i].name;
		int num = LIST[i].numble;
		mp[name] = num;
	}
	printf("输入查询次数\n");
	int m;
	cin >> m;
	//HARSH_1已经展示了解决冲突，这里直接用map.
	while (m -- ) {
		printf("请输入姓名\n");
		string name;
		cin >> name;
		if (mp.count(name)) {
			cout << "电话为：";
			cout << mp[name] << endl;
		}
		else cout << "NO FIND" << endl;
	}
}

void solve()
{
	//输入数据
	cin >> n;
	for (int i = 1; i <= n; i ++ )
		cin >> LIST[i].numble >> LIST[i].name;		
	HARSH_1();
	HARSH_2();
}

signed main()
{
	int T = 1;
	while (T--)
		solve();
	return 0;
}
