#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct Vector {
    ElementType *value; // 真正存放数据的指针
    int current_size; // 当前元素个数
    int capacity; // 最大容量
} Vector;

#define DEFAULT_SIZE 10

void initVector(Vector *vector) {
    vector->current_size = 0;
    vector->capacity = DEFAULT_SIZE;
    vector->value = (ElementType*)malloc(sizeof(ElementType) * DEFAULT_SIZE);
}

// 1. 求得当前Vector长度
int size(Vector vector) {
    return vector.current_size;
}

// 2. 获取当前Vector的最大容量
int capacity(Vector vector) {
    return vector.capacity;
}

// 3. 获取当前下标对应元素
ElementType get_index(Vector vector, int index) {
    if (index >= size(vector)) {
        printf("The index is out of range\n");
        return 0;
    }
    
    return vector.value[index];
}

// 4. 判断当前Vector是否是空
int empty(Vector vector) {
    return vector.current_size == 0;
}

// 5. 判断当前Vector是否是满
int full(Vector vector) {
    return vector.current_size == vector.capacity;
}

// 6. 向当前Vector的末尾append一个元素
void push_back(Vector *vector, ElementType e) {
    if (full(*vector)) {
        // 1.1 重新分配空间
        int new_cap = vector->capacity * 2;
        ElementType *new_value = (ElementType*)malloc(sizeof(ElementType) * new_cap);
        // 1.2 复制原有的元素
        memcpy(new_value, vector->value, vector->capacity);
        vector->value = new_value;
        vector->capacity = new_cap;
    }
    
    vector->value[vector->current_size++] = e;
}

// 7. 从当前Vector的末尾弹出一个元素
ElementType pop_back(Vector *vector) {
    if (empty(*vector)) {
        printf("The vector is empty\n");
        return 0;
    }

    return vector->value[--vector->current_size];
}

// 8. 打印当前Vector的信息
void print_vector(Vector vector) {
    printf("--------------------------Print Vector Start--------------------------\n");
    printf("Current size: %d, current capacity: %d\n", vector.current_size, vector.capacity);
    printf("The elements: [");
    for (int i = 0; i < size(vector); i++) {
        printf("%d%s", get_index(vector, i), i == size(vector) - 1 ? "" : ", ");
    }
    printf("]\n");
    printf("--------------------------Print Vector End--------------------------\n");
}

// 9. 在某个下标上插入一个元素
void insert(Vector *vector, int index, ElementType e) {
    if (full(*vector)) {
        // 1.1 重新分配空间
        int new_cap = vector->capacity * 2;
        ElementType *new_value = (ElementType*)malloc(sizeof(ElementType) * new_cap);
        // 1.2 复制原有的元素
        memcpy(new_value, vector->value, vector->capacity);
        vector->value = new_value;
        vector->capacity = new_cap;
    }

    if (index > vector->current_size || index < 0) {
        // index不合法
        printf("The index is invalid\n");
        return ;
    }

    // 下标[index, current_size) 都需要逐步后移
    for (int i = vector->current_size - 1; i >= index ; i--) {
        vector->value[i+1] = vector->value[i];
    }

    vector->value[index] = e;
    vector->current_size ++;
}

// 10. 删除某个下标元素
ElementType delete(Vector *vector, int index) {
    if (index > vector->current_size || index < 0) {
        // index不合法
        printf("The index is invalid\n");
        return ;
    }

    // 下标[index+1, current_size) 都需要往前移动
    for (int i = index + 1; i < vector->current_size; i++) {
        vector->value[i-1] = vector->value[i];
    }

    vector->current_size --;
}

typedef struct hero_id_allocator {
    int value[1024];   // 记录id是否被使用数组
    int current_used;  // 有多少id被分配出去
} hero_id_allocator;

hero_id_allocator allocator; // 全局变量

void init_allocator() {
    allocator.current_used = 0;
    for (int i = 0; i < 1024; i++) {
        allocator.value[i] = 0;
    }
}

int allocate_one_hero_id() {
    for (int i = 0; i <= 1024; i++) {
        if (allocator.value[i] == 0) {
            allocator.value[i] = 1;
            return i;
        }
    }
    
    printf("has no enough hero id!\n");
    return -1;
}

void free_one_hero_id(int id) {
    allocator.value[id] == 0;
}

typedef enum color {
    red,
    blue,
    purple,
    pink
} color;

typedef struct hero {
    int id; // 英雄的ID
    char name[30]; // 英雄名字
    int hp; // 英雄当前血量
    int attack; // 攻击力
    int v; // 移动速度
    int sp; // 蓝量值
    color c; // 色系
    int gender; // 性别，0代表女性，1代表男性，其他？
    char skill_description[1024]; // 大技能描述
    int status; // 0代表活着，1就是死亡
    
    Vector friends; // 朋友ID列表
    
    int resurrection_num; // 复活次数
    int sex_reassignment; // 是否变性过
} hero;

void initHero(hero *h, char* name, int hp, int attack, int v, int sp, color c, int gender, char *desc, Vector friends) {
    h->id = allocate_one_hero_id();
    strcpy(h->name, name);
    h->hp = hp;
    h->attack = attack;
    h->v = v;
    h->sp = sp;
    h->c = c;
    h->gender = gender;
    strcpy(h->skill_description, desc);
    h->status = 0;
    h->friends = friends;
    h->sex_reassignment = 0;
    h->resurrection_num = 0;
}


int main() {

}