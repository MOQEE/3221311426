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
const int N = 2e5;
int q[N], tem[N], ans;
// 归并排序
void merge_sort(int q[], int l, int r)
{
    if (l >= r)
        return;           // 边界返回
    int mid = l + r >> 1; // 分治
    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    // 此时已经局部排序，要合并左右集合。
    while (i <= mid && j <= r)
        if (q[i] <= q[j])
            tem[k++] = q[i++];
        else
            tem[k++] = q[j++], ans += mid - i + 1;
    // 合并剩下数
    while (i <= mid)
        tem[k++] = q[i++];
    while (j <= r)
        tem[k++] = q[j++];
    // 跟新原数组，让原数组完成有序化
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tem[j];
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> q[i];
    }
    // 归并排序
    merge_sort(q, 1, n);
    for (int i = 1; i <= n; i++)
    {
        cout << q[i] << " ";
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
