#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize(3)
#define int long long
#define ll long long
#define llu unsigned long long
#define endl "\n"
#define inf 0x3f3f3f3f
#define x first
#define y second
#define bit(x) (1LL << x)
typedef pair<int, int> PII;
const int mod = 998244353;
const int N = 2020;
int n, m;
int g[N][N];
int vis[N][N];
pair<pair<int, int>, int> q[N];
int ans = inf;
int res = inf;
int a, b, c, d;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
void dfs(int u, int v, int dist) 
{
    if (u == c && v == d) {
        ans = min(ans, dist);
        return ;
    }
    //遍历四个方向递归搜索
    for (int i = 0; i < 4; i ++ ) {
        int x = dx[i] + u, y = dy[i] + v;
        if (x < 1 || x > n || y < 1 || y > m) continue;
        if (g[x][y] == 1) continue;
        if (!vis[x][y]) {
            vis[x][y] = 1;
            dfs(x, y, dist + 1);
            vis[x][y] = 0;
        }
    }
}
int bfs() 
{
    int hh = 0, tt = -1;
    q[++ tt] = {{a, b}, 0};
    //bfs用队列一层一层搜索，最先搜索到的就是最短路径，配合队列存储每一层。
    while (hh <= tt) {
        auto t = q[hh ++];
        for (int i = 0; i < 4; i ++ ) {
            int x = dx[i] + t.first.first, y = dy[i] + t.first.second;
            if (x < 1 || x > n || y < 1 || y > m) continue;
            if (g[x][y] == 1) continue;
            q[++ tt] = {{x, y}, t.second + 1};
            //找到就退出。
            if (x == c && y == d) {
                return t.second + 1;
            }
        }
    }
    return -1;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
            cin >> g[i][j];
    cin >> a >> b >> c >> d;
    //递归
    dfs(a, b, 0);
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;

    //宽搜
    cout << bfs() << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    while (T--)
        solve();
    return 0;
}
