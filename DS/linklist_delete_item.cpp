#include <bits/stdc++.h>
using namespace std;

typedef struct LinkList {
    int val;
    struct LinkList *next;
} LinkList;

// 在带头结点单链表中删除指定元素
void deleteItem(LinkList *head, int val) {
    LinkList *p = head->next;
    LinkList *pre = head;
    while (p != NULL) {
        if (p->val == val) {
            pre->next = p->next;
            delete p;
            p = pre->next;
        } else {
            pre = p;
            p = p->next;
        }
    }
}

void printList(LinkList *head) {
    LinkList *p = head->next;
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
}

LinkList *initializeLinkList() {
    LinkList *head = new LinkList;
    head->next = NULL;
    LinkList *tail = head;
    int a[] = {7, 2, 6, 12, 4, 5};
    for (int i = 0; i < 6; i++) {
        LinkList *newNode = new LinkList;
        newNode->val = a[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int main() {
    // 尾插法初始化链表为 7, 2, 6, 12, 4, 5
    LinkList *head = initializeLinkList();

    // 删除2
    deleteItem(head, 2);
    printList(head);  // 7 6 12 4 5
}