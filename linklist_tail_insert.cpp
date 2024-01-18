#include <bits/stdc++.h>
using namespace std;

// 链表数据结构定义
typedef struct LinkList {
    int val;
    struct LinkList* next;
} LinkList;

// 链表遍历
void PrintLinkList(LinkList* L) {
    LinkList* p = L->next;
    while(p) {
        printf("%d ", p->val);
        p=p->next;
    }
}

int main() {
    int arr[4] = {1, 2, 3, 4}; //待插入序列
    
    // 初始化头结点单链表
    LinkList* L = new LinkList; 
    L->next = NULL;
    
    // 需要一个尾部指针跟踪
    LinkList* r = L;
    
    // 头插法实现，根据“头插法参考图”，我们可以写出以下代码
    for (int i = 0; i < 4; i++) {
        // 20,21,22这三步相当于申请了个新结点，并填充数据
        LinkList* s = new LinkList;
        s->val = arr[i];
        s->next = NULL;
        
        // 这两步完成了新结点的尾插
        r->next = s;
        r = s;
    }
    
    PrintLinkList(L);
}