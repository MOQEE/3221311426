#include <bits/stdc++.h>

using namespace std;
char s[10010];
void BRUTE_FORCE(char *s){
    int N = strlen(s);
    int  st = 0, len = 0; 
    // 奇数长度的回文子串
    for (int i = 0; i < N; i++) {   
        //枚举每个点为中心
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < N && s[l] == s[r]){
            l --, r ++;       
        }                             
        if (r - l - 1 > len) {   
            st = l + 1;
            len = r - l - 1;
        }
    }
    //偶数回文子串
    for (int i = 0; i < N; i++) {  
        int l = i, r = i + 1;   
        while (l >=0 && r < N && s[l] == s[r]) {
            l --, r ++;
        }
        if (r - l - 1 > len) {
            st = l + 1;
            len = r - l - 1;
        }
    }
    for (int i = st; i < st + len; i ++ ) {
        cout << s[i];
    }
}

int main()
{
    cin >> s;
    int n = strlen(s);
    BRUTE_FORCE(s);
    return 0;
}
