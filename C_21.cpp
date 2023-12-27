#include <bits/stdc++.h>

using namespace std;
const int N = 10010;
int a[N], b[N];
/*
由于等长，那么遍历数组找到中间两个数即可。
*/
int n;
void find()
{
    int cnt = 0;
    int res = 0;
    int i = 1, j = 1;
    while (i <= n && j <= n) {
        cnt ++;
        if (a[i] <= b[j])  {
            if (cnt == n) res += a[i];
            if (cnt == n + 1) res += a[i];
            i ++;
        }
        else  {
            if (cnt == n) res += b[j];
            if (cnt == n + 1) res += b[j];            
            j ++;
        }
    }
    while (i <= n) {
        cnt ++;
        if (cnt == n) res += a[i];
        if (cnt == n + 1) res += a[i];
        i ++;
    }
    while (j <= n) {
        cnt ++;
        if (cnt == n) res += b[j];
        if (cnt == n + 1) res += b[j];
        j ++;
    }
    printf("%.2f\n", res / 2.0);
}

int main()
{

    cin >> n;
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    for (int j = 1; j <= n; j ++ )
        cin >> b[j];
    find();
    return 0;
}
