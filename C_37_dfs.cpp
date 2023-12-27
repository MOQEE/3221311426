#include <bits/stdc++.h>

using namespace std;

const int N = 10010, M = 2 * N;
int h[N], ne[M], e[M], idx;
int vis[N];
int n, m;
bool ok;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dfs(int ed, int u)
{
    if (u == ed) {
        ok = true;
        return ;
    }
    if (u == -1) u = ed;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!vis[j]) {
            vis[j] = 1;
            dfs(ed, j); 
            vis[j] = 0;           
        }
    }
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    for (int i = 1; i <= n; i ++ )  
        dfs(i, -1);
    cout << (ok ? "YES" : "NO") << endl;
    return 0;
}
