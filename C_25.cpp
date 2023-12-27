#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
char p[N], s[N];
int ne[N];
/*
KMP即预处理最大前缀和后缀，让每次匹配失败的时候，都能调到匹配串的最大前缀相同的位置。
*/
int main()
{
    gets(s + 1), gets(p + 1);
    int n, m;
    n = strlen(p + 1);
    m = strlen(s + 1);
    int j = 0;
    for (int i = 2; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    j = 0;
    for (int i = 1; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        
        if (s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            cout << i - j + 1 << " ";
            j = ne[j];
        }
    }
    return 0;
}
