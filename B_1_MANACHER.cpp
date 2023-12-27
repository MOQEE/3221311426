#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N], ns[N];
int r[N];
int n;
void init() {
    int m = strlen(s);
    ns[++ n] = '#';
    for (int i = 0; i < m; i ++ ) {
        ns[++ n] = s[i];
        ns[++ n] = '#';
    }
    ns[n + 1] = '\0';
}

void Manacher()
{
    init();
    int mx = 1, p = 1;
    int mxp = 1, mxr = 1;
    for (int i = 1; i <= n; i ++ ) {
        /*
        一种是mx <= i; r[i] = 1;
        一种是i对称的j,mx - i > r[j];r[i] = r[j];
        一种是mx-i <= r[j], 可以获得该点半径的下界：r[i] >= mx - i;
        */
        //mx - i 第三种的最小边界，一二为r[p * 2 - i];
        r[i] = min(mx - i, r[p * 2 - i]);
        //第三种的扩展边界。
        while (i - r[i] >= 1 && i + r[i] <= n && ns[i - r[i]] == ns[i + r[i]]) ++ r[i];
        if (i + r[i] > mx) {
            mx = i + r[i];
            p = i;
        }
        if (r[i] > mxr) {
            mxr = r[i];
            mxp = i;
        }
    }
    for (int i = mxp - r[mxp] + 1; i <= mxp + r[mxp] - 1; i ++ )
        if (ns[i] != '#') 
            cout << ns[i];
}

int main()
{
    scanf("%s", s);

    Manacher();
    return 0;
}
