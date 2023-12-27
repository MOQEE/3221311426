#include <bits/stdc++.h>

using namespace std;
string s, op, s_sorted;
/*
字符入栈再出栈看看是否是从小到大的顺序输出
*/
bool check(string s) 
{
    stack<char> ss;
    for (int i = 0; i < s.size(); i ++ ) ss.push(s[i]);
    char op = 'a';
    while (ss.size()) {
        char p = ss.top();
        ss.pop();
        if (p >= op) op = p;
        else return false;
    }
    return true;
}

int main()
{
    
    cin >> s;
    if (check(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
