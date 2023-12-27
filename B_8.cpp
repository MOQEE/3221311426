#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;

int h[N], ne[N], e[N], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
int vis[N];
int n;
bool ok;
void dfs(int u, int cnt) {
    //遍历图如果回到该点，且遍历的点的个数为n则是强连通图
    if (u == 1 && cnt == n) {
        ok = true;
        return ;
    }
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!vis[j]) {
            vis[j] = 1;
            dfs(j, cnt + 1);
            vis[j] = 0;
        }
    }
}
int main()
{
    int n, m;
    printf("输入点数和边数:\n");
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    dfs(1, 0);
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
