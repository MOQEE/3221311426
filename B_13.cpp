#include <bits/stdc++.h>

using namespace std;
typedef pair<int , int> PII;
const int N = 1e5, M = 2e5;
int h[N], ne[M], e[M], w[M], idx;
int dist[N];
int vis[N];
int cont[N];
int n, m;    
int st, ed;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
/*
用spfa对每个点进行松弛操作，如果一个点被松弛了大于等于点数次说明有环。
*/
void spfa(int u)
{
    memset(dist, -1, sizeof dist);
    dist[u] = 0;
    vis[u] = 1;
    queue<PII> q;
    q.push({0, u});
    int cnt = 0;
    int res = 1;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        int d = t.first;
        int v = t.second;
        vis[v] = 0;
        for (int i = h[v]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                cont[j] ++;
                //点数小于边数，对这个直接判断边数.
                if (cont[j] > n) {
                    cout << -1 << endl;
                    return ;
                }
                //已在队列里
                if (!vis[j]) {
                    vis[j] = 1;
                    q.push({dist[j], j});                    
                    res ++;
                }
            }
        }
    }
    if (dist[ed] == -1) cout << "-1" << endl;
    else cout << dist[ed] << endl; 
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cin >> st >> ed;
    spfa(st);
    return 0;
}
/*
测试样例
4
1 2 2
2 4 4
1 3 6
3 4 5
1 4
*/
