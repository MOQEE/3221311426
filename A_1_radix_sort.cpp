#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
vector<int> q[15];
int a[N];
int n;
void radix_sort()
{
    //从低位到高位取出位数，依次插入队列。
    for (int k = 0; k <= 9; k ++ ) {
        bool ok = true;
        int p = pow(10, k);
        for (int i = 1; i <= n; i ++ ) {
            if (a[i] < a[i - 1]) ok = false;
            int j = a[i] / p % 10;
            q[j].push_back(a[i]);
        }
        if (ok) return ;
        int op = 1;
        //进行排序。
        for (int i = 0; i <= 9; i ++ ) {
            for (int j = 0; j < q[i].size(); j ++ )
                a[op ++] = q[i][j];//依次取出元素
            q[i].clear();//清空队列。
        }          
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
        cin >> a[i];    
    radix_sort();
    for (int i = 1; i <= n; i ++ ) 
        cout << a[i] << " ";
    return 0;
}
