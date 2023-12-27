#include <bits/stdc++.h>
using namespace std;
const int N = 1100;

vector<int> ve[N];
int g[N][N];
int n, m;

void change()
{
    cin >> n >> m;
    //给定邻接矩阵
    for (int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        g[a][b] = 1;
        g[b][a] = 1;
    }
    //算出邻接表：
    printf("邻接表：\n");
    for (int i = 1; i <= n; i ++ ) 
        for (int j = 1; j <= n; j ++ )
            if (g[i][j] == 1) 
                ve[i].push_back(j);
    for (int i = 1; i <= n; i ++ ) {
        cout << i << "->";
        for (auto t : ve[i]) {
            cout << t << " ";
        }
        cout << endl;
    }
    //邻接表算出邻接矩阵：
    printf("邻接矩阵:\n");
    for (int i = 1; i <= n; i ++ )
        for (auto t : ve[i])
            g[i][t] = 1;
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    change();
    return 0;
}
/*
测试数据
5 5
1 2
1 4
2 3
2 4
4 5
*/
