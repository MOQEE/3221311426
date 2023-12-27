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
const int N = 50;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];
int NO = 0;
void dfs(int u)
{
    if(u == n){
        cout << (++ NO) << ": ";
        for (int i = 0; i < n; i ++ ) 
            for (int j = 0; j < n; j ++ )
                if (g[i][j] == 'Q') {
                    printf("(%d, %d) ", i, j);
                }
        cout << endl;
    }
    
    for(int i = 0; i < n; i ++)
        if (!col[i] && !dg[i + u] && !udg[n - i + u])//解决行列对角线冲突
        {
            g[u][i] = 'Q';
            col[i] = dg[i + u] = udg[n - i + u] = true;
            dfs(u + 1);
            //回溯路径
            col[i] = dg[i + u] = udg[n - i + u] = false;
            g[u][i] = '.';
        }
}
void solve()
{
    n = 8;
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j ++)
            g[i][j] = '.';
    dfs(0);
}
signed main()
{
    int T = 1;
    while (T--)
        solve();
    return 0;
}
