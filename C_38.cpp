#include <bits/stdc++.h>

using namespace std;

const int N = 200, M = 2 * N, INF = 0x3f3f3f3f; 

int n, m, k, x, y, z;
int d[N][N];
int p[N];
bool vis[N];
struct edge
{
    int a, b, c;
    /* data */
}g[M];
/*
KLSKA每次选最小边，如果构成回路则不加入，否则加入，
floyd就对于每两个点，遍历他们直接所有点看看能不能更新边权。
*/
bool cmp(edge a, edge b)
{
    return a.c < b.c;
}
//判断加入的边是否在同一个集合，如果咋=在同一个则有回路。
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void KRUSKAL() {
    //按边权重进行排序
    sort(g + 1, g + m + 1, cmp);
    int cnt = 0;
    int res = 0;
    for (int i = 1; i <= m; i ++ ) {
        int a = find(g[i].a);
        int b = find(g[i].b);
        if (a != b) {//不构成回路则加入，并且合并集合。
            vis[a] = 1;
            vis[b] = 1;
            p[a] = b;
            res += g[i].c;
            cnt ++;
        }
    }
    if (cnt < n - 1) {
        cout << "不存在最小生成树" << endl;
        return;        
    }
    printf("最小生成树权重: %d\n", res);
    printf("最小生成树的顶点：\n");
    for (int i = 1; i <= n; i ++ )
        if (vis[i]) cout << i << " ";
    cout << endl;
}

void floyd() {
    printf("任意两点间最短路径矩阵:\n");
    //对每两个点遍历之间的所有点跟新权重。
    for(int k = 1; k <= n; k ++)
        for(int i = 1; i <= n; i ++)
            for(int j = 1; j <= n; j ++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) 
            cout << d[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> n >> m;
    //一开始集合都只有自己
    for (int i = 1; i <= n; i ++ ) p[i] = i;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;

    for (int i = 1; i <= m; i ++ ) {
        cin >> x >> y >> z;
        g[i] = {x, y, z};
        //保存最小边。
        d[x][y] = min(d[x][y], z);
        d[y][x] = min(d[y][x], z);
    }
    floyd();
    KRUSKAL();
    return 0;
}
