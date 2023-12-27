#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
int n, m;
int q[N], cnt;
// 希尔排序 ：
void shell_sort()
{
    // 对数组进行分组。每一次分的组的间隔为之前的一半。
    for (int gap = n >> 1; gap; gap >>= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int x = q[i];
            int j;
            // 对于每个组进行插入排序，从后往前找，找到第一个能插入的位置，
            for (j = i; j >= gap && q[j - gap] > x; j -= gap)
            {
                q[j] = q[j - gap];
            }
            q[j] = x;
        }
    }
    for (int i = 0; i < n; i++)
        cout << q[i] << " ";
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    shell_sort();
}
