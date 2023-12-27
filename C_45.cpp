#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = 2 * N;

int h[N], ne[M], e[M], idx;

//链式前向星，存储邻接表。
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
/*
TOPO序每次取出入度为0的点，删掉与之相邻的边，反复操作。
*/
queue<int> q;
int d[N];
int n, m;
int vis[N];
void Topo_sort()
{
    queue<int> qq;
    for (int i = 0; i <= n; i ++ ) {
        if (!d[i]) {
            q.push(i);       
            qq.push(i);    
        }
    }
    while (qq.size()) {
        int i = qq.front();
        qq.pop();          
        //删掉与之相邻的边。
        for (int j = h[i]; ~j; j = ne[j]) {
            int k = e[j];
            d[k] --;
            if (d[k] == 0) {//入度为0，则入队。
                qq.push(k);
                q.push(k);
            }
        }
    }
    while (q.size()) cout << q.front() << " ", q.pop();
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i ++ ) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b] ++;
    }
    Topo_sort();
}
