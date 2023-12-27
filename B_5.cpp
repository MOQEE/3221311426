#include <bits/stdc++.h>

using namespace std;
const int N = 2020, M = N * 2;
int n;
struct pp
{
    int l, r;
    /* data */
} tr[M];
//先序
void dfs_1(int u)
{
    if (u == -1) return ;
    cout << u << " ";
    dfs_1(tr[u].l);
    dfs_1(tr[u].r);
}
//中序
void dfs_2(int u)
{
    if (u == -1) return ;
    dfs_2(tr[u].l);
    cout << u << " ";
    dfs_2(tr[u].r);
}
//后序
void dfs_3(int u)
{
    if (u == -1) return ;
    dfs_3(tr[u].l);
    dfs_3(tr[u].r);    
    cout << u << " ";
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        tr[a] = {b, c};
    }
    dfs_1(1);
    cout << endl;
    dfs_2(1);
    cout << endl;
    dfs_3(1);
    cout << endl;
    return 0;
}
