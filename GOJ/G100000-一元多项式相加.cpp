#include <bits/stdc++.h>
using namespace std;
typedef struct LinkList {
    int exponent; // 指数
    int base; // 底数
    struct LinkList *next;
} LinkList;

void PrintLinkList(LinkList *l) {
    cout << "链表内容：" << endl;
    LinkList* p = l->next;
    while (p) {
        cout << p->base << ' ' << p->exponent << endl;
        p = p->next;
    }
    cout << endl;
}


LinkList* add_list(LinkList *L1, LinkList *L2) {
    LinkList* result = new LinkList;
    LinkList* r = result;
    
    LinkList *p = L1->next;
    LinkList *q = L2->next;
    
    while (p && q) {
        // PrintLinkList(result);
        // printf("p: [%d*x^%d], q: [%d*x^%d]\n", p->base, p->exponent, q->base, q->exponent);
        if (p->exponent > q->exponent) {
        	// p高
            r->next = p;
            r = p;
            
            p = p->next;
            r->next = nullptr;
        } else if (p->exponent < q->exponent) {
           	// q高
            r->next = q;
            r = q;
            
            q = q->next;
            r->next = nullptr;
        } else {
            // 同次幂
            if (p->base + q->base != 0) {
                p->base += q->base;
                
                r->next = p;
                r = p;

                p = p->next;
                r->next = nullptr;

                q = q->next;
            } else {
                p = p->next;
                q = q->next;
            }
            
        }
    }
    
    if (p) {
        r->next = p;
    }
    
    if (q) {
        r->next = q;
    }
    
    return result;
}

int main() {
	int n, m;
    cin >> n >> m;
    LinkList *FX = new LinkList;
    LinkList *r = FX;
    
    for (int i = 0; i < n; i++) {
        LinkList *s = new LinkList;
        cin >> s->exponent >> s->base;
        s->next = nullptr;
        
        // 尾插法
        r->next = s;
        r = s;
    }
    
    LinkList *GX = new LinkList;
    r = GX;
    for (int i = 0; i < m; i++) {
        LinkList *s = new LinkList;
        cin >> s->exponent >> s->base;
        s->next = nullptr;
        
        // 尾插法
        r->next = s;
        r = s;
    }

    int cnt = 0;
	LinkList *result = add_list(FX, GX);
    LinkList *p = result->next;
    while (p) {
        cnt ++;
        p = p->next;
    }
    cout << cnt << endl;
    
    p = result->next;
    while (p) {
		cout << p->exponent << ' ' << p->base << endl;
        p = p->next;
    }
    return 0;
}