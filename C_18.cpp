#include <bits/stdc++.h>

using namespace std;

struct Node  {
    int val;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void add(int x) {
    Node *pre = new Node();
    pre->val = x;
    if (head == NULL) {
        head = pre;
        tail = pre;
        pre->next = tail;
    }
    else {
        tail->next = pre;
        pre->next = head;
        tail = pre;
    }
}

void Josephus() {
    Node *p = head, *lp = head;
    int cnt = 0;
    while (p != NULL) {
        cnt ++;
        if (lp == p && cnt != 1) {
            cout << p->val;
            break;
        }      
        if (cnt % 3 == 0) {
            cout << p->val << " ";
            lp->next = p->next;
            free(p);
            p = lp;
        }
        lp = p;
        p = p->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int x;
        cin >> x;
        add(x);
    }
    Josephus();
    return 0;
}
