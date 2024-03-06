#include <bits/stdc++.h>
using namespace std;

#define DefaultSize 10

typedef int ElementType;

typedef struct Vector {
    ElementType *arr; // 实际存放的指针
    int size; // 当前元素个数
    int cap; // 容量

    int (*Size)(Vector v);
    void (*push_back)(Vector *v, ElementType e);
    ElementType (*pop_back)(Vector *v);
    ElementType (*erase)(Vector *v, int index);
    void (*insert)(Vector *v, int index, ElementType e);
    void (*print_self)(Vector v);
} Vector;

/**
 * size();
 * push_back(item);
 * pop_back();
 * erase(index);
 * insert(index, item);
*/

int Size(Vector v);
void push_back(Vector *v, ElementType e);
ElementType pop_back(Vector *v);
ElementType erase(Vector *v, int index);
void insert(Vector *v, int index, ElementType e);
void print_self(Vector v);

void initialize_vector(Vector *v) {
    v->size = 0;
    v->arr = (ElementType*)malloc(sizeof(ElementType) * DefaultSize);  // 申请了10个元素空间
    v->cap = DefaultSize;

    v->Size = Size;
    v->push_back = push_back;
    v->pop_back = pop_back;
    v->erase = erase;
    v->insert = insert;
    v->print_self = print_self;
}

int main() {
    Vector v;
    initialize_vector(&v);
    v.print_self(v);

    cout << "在push12个元素之后" << endl;
    for (int i = 0; i < 12; i++)
        v.push_back(&v, rand()%100);
    v.print_self(v);

    cout << "在pop6个元素之后" << endl;
    for (int i = 0; i < 6; i++)
        v.pop_back(&v);
    v.print_self(v);

    return 0;
}

int Size(Vector v) {
    return v.size;
}

bool is_full(Vector *v) {
    return v->size == v->cap;
}

void push_back(Vector *v, ElementType e) {
    // 1. 是否已经满了，如果满了就重新分配并复制原有的
    if (is_full(v)) {
        // 1.1 重新分配空间
        int new_cap = v->cap * 2;
        ElementType *new_arr = (ElementType*)malloc(sizeof(ElementType) * new_cap);
        // 1.2 复制原有的元素
        memcpy(new_arr, v->arr, v->cap);
        v->arr = new_arr;
        v->cap = new_cap;
    }

    v->arr[v->size++] = e;
}

void print_self(Vector v) {
    printf("当前的向量Size: %d, Cap: %d\n", v.size, v.cap);
    cout << "------------" << "当前的元素是" << "------------\n";
    for (int i = 0; i < v.Size(v); i++) {
        cout << v.arr[i] << ' ';
    }
    cout << endl;
}

ElementType pop_back(Vector *v) {
    if (v->size == 0) {
        return 0;
    }

    return v->arr[--v->size];
}

// TODO: 实现插入删除
ElementType erase(Vector *v, int index) {
    return 0;
}

void insert(Vector *v, int index, ElementType e) {

}