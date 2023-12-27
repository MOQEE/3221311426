#include <bits/stdc++.h>

using namespace std;
const int N = 10100, M = 2 * N;
/*
求AOE网中的关键路径就是求源点到汇点的最长距离的路径。
思路：
先求图的拓扑排序。
再找出源点和汇点中最长的并找出所有最长路径。
再建立AOE的最长路径图。
*/
int d[N];//记录点的入度，求拓扑排序。
int h[N], rh[N], aoeh[N], ne[M], e[M], w[M], idx;//数组模拟邻接表
int n, m;
int vis[N];

int st[N], ed[N];//事件开始和结束
struct pp {
    int a, b, c;
} AOE[N];
int mxq[N];
int rmxq[N];
int dist[N];
int cnt = 1;//保存路径数量。
queue<int> q;//每次将度数为0点入队，直到结束，求处TOPO排序
stack<int> rq;//逆TOPO序
void add(int h[], int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
    if (h[u] == -1) return ;
    int op = 0;//对于每个点的分叉数。
    for (int i = aoeh[u]; ~i; i = ne[i]) {
        int j = e[i];
        op ++;
        dfs(j);
    }
    //如果有分叉,则路径数等于加上分叉数- 1。
    if (op > 1) {
        cnt += op - 1;
    }
}

void Topo_sort()
{
    //一共1 + n个点。
    queue<int> qq;
    for (int i = 0; i <= n; i ++ ) {
        if (!d[i] && !vis[i]) {
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
            if (d[k] == 0) {
                qq.push(k);
                q.push(k);
            }
        }
    }
    //检验
    //while (q.size()) cout << q.front() << endl, q.pop();
}
void AOE_KEY_WAY() {
    //TOPO求事件开始
    int mx = 0;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        rq.push(t);
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            st[j] = max(st[j], st[t] + w[i]);
            mx = max(st[j], mx);
        }
    }
    //逆TOPO求事件结束
    memset(ed, 0x3f, sizeof ed);
    ed[n] = mx;    
    while (rq.size()) {
        int t = rq.top();
        rq.pop();
        for (int i = rh[t]; ~i; i = ne[i]) {
            int j = e[i];
            dist[j] = max(dist[j], dist[t] + w[i]);
            ed[j] = min(ed[j], mx - dist[j]);
        }        
    }
    //时间剩余为0.
    memset(d, 0, sizeof d);
    unordered_map<int, int> mp;
    for (int i = 1; i <= m; i ++ ) {
        int a = AOE[i].a, b = AOE[i].b, c = AOE[i].c;
        if (st[a] == ed[b] - c) {
            add(aoeh, a, b, c);
            d[b] ++;
            mp[a] = d[a];
            mp[b] = d[b];
        }
    }
    for (auto t : mp)
        if (t.second == 0) 
            q.push(t.first);
    while (q.size()) {
        int t = q.front();
        q.pop();
        dfs(t);//计算路径。
    }
    cout << cnt << endl;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);
    memset(aoeh, -1, sizeof aoeh);
    for (int i = 1; i <= m; i ++ ) {
        int a, b, t;
        cin >> a >> b >> t;
        //建立正图
        add(h, a, b, t);
        //建立反图
        add(rh, b, a, t);
        AOE[i] = {a, b, t};
        d[b] ++;
    }
    Topo_sort();
    AOE_KEY_WAY();
    return 0;
}
