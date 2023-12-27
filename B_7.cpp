#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;

    //逆序对个数
    for (int i = 1; i <= n; i ++ ) 
        cin >> a[i];
    int cnt = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = i + 1; j <= n; j ++ ) 
            if (a[i] > a[j]) cnt ++;
    cout << cnt << endl;
    return 0;
}
