#include <bits/stdc++.h>
using namespace std;

const int N = 10010, M = 2 * N;

int h[N], e[M], ne[M], w[M], idx;
int n, ans;

void add(int a, int b, int c) 
{
    w[idx] = c, e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
/*
树的最长路径只需要从一个点出发记录能走到的最长路径和次长路径之和。
*/
int dfs(int u, int father)
{
    //向下找的最长路径, 和次长。
    int d1 = 0, d2 = 0;
    
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        //不往回走
        if (j == father) continue;
        
        int d = w[i] + dfs(j, u);
        //替换最长路径和次长路径
        if (d >= d1) d2 = d1, d1 = d;
        else if (d > d2) d2 = d;
        
    }
    ans = max(ans, d1 + d2);
    //对于每个路径的抉择，返回最长路径。
    return d1;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n;
    for (int i = 0; i < n - 1; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
    return 0;
}
