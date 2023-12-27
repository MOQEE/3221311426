#include <bits/stdc++.h>

using namespace std;
typedef pair<int , int> PII;
const int N = 1e5, M = 2e5;
int h[N], ne[M], e[M], w[M], idx;
int dist[N];
int vis[N];
int fa[N];
int n, m;    
int st, ed;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
/*
用spfa求最长路径，用fa数组记录每个点从拿转移过来。
*/
void spfa(int u)
{
    memset(dist, -1, sizeof dist);
    dist[u] = 0;
    vis[u] = 1;
    queue<PII> q;
    q.push({0, u});
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
                fa[j] = v;
                if (!vis[j]) {
                    vis[j] = 1;
                    q.push({dist[j], j});                    
                    res ++;
                }
            }
        }
    }
    
}

void print_way()
{
    printf("最大魔法值：%d\n路径:",dist[ed]);
    stack<int> q;
    //用栈保存路径
    while (ed) {
        q.push(ed);
        ed = fa[ed];
    }
    while (q.size()) {
        cout << q.top();
        q.pop();
        if (q.size()) cout << "->";
    }
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
    print_way();
    return 0;
}
/*
5 6
1 2 3
1 3 5
2 3 1
2 4 4 
3 4 2
3 5 6
1 5
*/
/*
4 5
1 2 10
2 3 12
3 4 7
1 3 5
2 4 6
1 4
*/
