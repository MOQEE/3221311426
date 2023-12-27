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
const int N = 2010;
int n, m;
int dist[N];
int back_dist[N];
struct pp
{
    int a, b, c;
} g[N];
void Bellman_Fold(int s)
{
    dist[s] = 0;
    for (int i = 0; i < n; i++)
    {
        // 这里跟新需要用到之前的dist数组，因为每个点都是同时去跟新的
        // 如果没有可能会用这步跟新的点去跟新其它点。
        memcpy(back_dist, dist, sizeof dist);
        for (int j = 1; j <= m; j++)
        {
            int a = g[j].a, b = g[j].b, c = g[j].c;
            dist[b] = min(dist[b], back_dist[a] + c);
        }
    }
}
void solve()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[i] = {a, b, c};
    }
    int s;
    cin >> s;
    Bellman_Fold(s);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] >= inf / 2)
        {
            cout << "INF" << endl;
        }
        else
            cout << dist[i] << endl;
    }
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
