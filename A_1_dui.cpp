#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m;
int q[N], cnt;
void down(int u)
{
    int t = u;
    // 在左右儿子中选一个最小的与当前节点进行交换。
    // 即父节点下沉down操作.
    if (u * 2 <= cnt && q[u * 2] < q[t]) t = u * 2;
    if (u * 2 + 1 <= cnt && q[u * 2 + 1] < q[t]) t = u * 2 + 1;
    if (u != t)
    {
        swap(q[u], q[t]);
        down(t);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> q[i];
    cnt = n;
    // 如果要建立一个堆，那么子树一定要先满足堆性质
    // 叶子节点一定是堆，因此从叶子节点的父节点开始进行down操作即 n / 2;
    for (int i = n / 2; i; i--)
        down(i);
    while (n--)
    {
        cout << q[1] << " "; // 输出堆顶（最小值）
        q[1] = q[cnt--];     // 删除堆顶（用最后一个数覆盖第一个数） 并且长度 减1
        down(1);             // 让覆盖好的数往下面走
    }
    cout << endl;
    return 0;
}
