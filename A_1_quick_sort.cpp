#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m;
int q[N], cnt;
void quickSort(int q[], int l, int r)
{
    // 如果数组中就一个数，就已经排好了，直接返回。
    if (l >= r)
        return;
    // 选取分界线。这里选数组中间那个数
    int x = q[l + r >> 1];
    int i = l - 1, j = r + 1;
    // 划分成左右两个部分
    while (i < j)
    {
        while (q[++i] < x);
        while (q[--j] > x);
        if (i < j)
        {
            swap(q[i], q[j]);
        }
    }
    // 对左部分和有部分排序
    quickSort(q, l, j),
    quickSort(q, j + 1, r);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    quickSort(q, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
}
