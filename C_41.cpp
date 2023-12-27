#include <bits/stdc++.h>

using namespace std;

const int N = 10010;

/*
因为题目没要求，这里我就用暴力的做法。
开个bool数组，从一个点出发，向上走，标记路径，再从另一个点出发
第一次遇见标记点即为最近公共祖先
*/
int tr[N];
bool vis[N];
void LCA(int a, int b)
{
    while (a) {
        vis[a] = 1;
        a /= 2;
    }
    while (b) {
        if (vis[b]) {
            cout << tr[b] << endl;
            break;
        }
        b /= 2;
    }
}
int main()
{
    int n;
    cin >> n;//n个点。
    for (int i = 1; i <= n; i ++ ) 
        cin >> tr[i];
    int a, b;
    cin >> a >> b;
    LCA(a, b);
    return 0;
}
