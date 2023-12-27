#include <bits/stdc++.h>

using namespace std;
char s[10010];
int main()
{
    gets(s);
    int n = strlen(s);
    bool ok = false;
    int cnt = 0;
    for (int i = 0; i < n; i ++ )
        if (s[i] != ' ') cnt ++;

    for (int i = 0; i < n; i ++ ) {
        if (s[i] == ' ') {
            if (ok == true && cnt) cout << " ";            
            ok = false;
        }
        else {
            cnt --;
            cout << s[i];
            ok = true;            
        }
    }
    return 0;
}
