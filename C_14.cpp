#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (cin >> n) {
        int a_25 = 0, a_10 = 0, a_5 = 0, a_1 = 0;
        a_25 += n / 25;
        n %= 25;
        a_10 += n / 10;
        n %= 10;
        a_5 += n / 5;
        n %= 5;
        a_1 += n;
        printf("25分:%d个 10分:%d个 5分:%d个 1分:%d个\n", a_25, a_10, a_5, a_1);
    }
    return 0;
}
