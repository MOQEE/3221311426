#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
char a[N];
int n;
/*
数组模拟二叉树，i/2为父节点i的父节点，i * 2 + 1右孩子, i * 2 左孩子。
*/
void find(char x)
{
    int j = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (a[i] == x) {//找到该节点。
            j = i;
            break;
        }    
    }
    // 判断是否有孩子节点。
    if (2 * j <= n || 2 * j + 1 <= n || !j) {
        printf("%c不是叶子节点\n", x);
        return ;
    }
    stack<char> q;
    while (j) {
        q.push(a[j]);
        j /= 2;
    }
    while (q.size()) {
        cout << q.top();
        q.pop();
        if (q.size()) cout << "->";
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    char c;
    cin >> c;
    find(c);
    return 0;
}
