#include <bits/stdc++.h>
using namespace std;

typedef struct LinkList {
    int val;
    struct LinkList *next;
} LinkList;

// 在链表的某个元素后插入一个元素
void insertItem(LinkList *head, int item, int val) {
    LinkList *p = head->next;
    while (p != NULL) {
        if (p->val == item) {  // 找到要插入位置的前一个元素
            LinkList *newNode = new LinkList;
            newNode->val = val;
            newNode->next = p->next;
            p->next = newNode;
            return;
        }
        p = p->next;
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
    int a[] = {7, 2, 6, 4, 5};
    for (int i = 0; i < 5; i++) {
        LinkList *newNode = new LinkList;
        newNode->val = a[i];
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
    return head;
}

int main() {
    // 尾插法初始化链表为 7, 2, 6, 4, 5
    LinkList *head = initializeLinkList();

    // 在链表的6之后插入一个元素12
    insertItem(head, 6, 12);
    printList(head);  // 7 2 6 3 4 5
}