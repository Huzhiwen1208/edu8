#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <map>
using namespace std;

// 类型定义列表

typedef struct hero_id_allocator {
    int value[1024];   // 记录id是否被使用数组
    int current_used;  // 有多少id被分配出去
} hero_id_allocator;

typedef enum color {
    red,
    blue,
    purple,
    pink
} color;

typedef struct hero {
    int id; // 英雄的ID
    string name; // 英雄名字
    int hp; // 英雄当前血量
    int attack; // 攻击力
    int v; // 移动速度
    int sp; // 蓝量值
    color c; // 色系
    int gender; // 性别，0代表女性，1代表男性，其他？
    string skill_description; // 大技能描述
    int status; // 0代表活着，1就是死亡
    
    vector<int> friends; // 朋友ID列表
    
    int resurrection_num; // 复活次数
    int sex_reassignment; // 是否变性过
} hero;


// 全局变量声明列表

static hero_id_allocator id_allocator;
static map<int, hero> HeroManager;

static string skills[] = {"Unparalleled: This skill originated from the wilderness. It will decrease hp: 25; decrease attack: 24; increase sp: 34;"
                ,"Wilderness: This skill is impressive and rare. It will decrease hp: 33; increase hp: 50;"
                ,"GrapplingHook: The skill is a hook that can grapple or latch onto an enemy hero. It will decrease hp: 5; decrease attack: 30;"};

// 工具方法声明列表

void init_allocator();
int allocate_one_hero_id();
void free_one_hero_id(int id);

// 交互方法声明列表
// TODO: 完成所有方法的实现，参考英雄管理系统的需求文档 https://m13n4gzucg.feishu.cn/docx/LBEpdGBbGoXWgkxKjrfcdSwfnce
void initHero(hero *h, char* name, int hp, int attack, int v, int sp, color c, int gender, char *desc, vector<int>& friends);
void make_friend(hero* a, hero* b);
void delete_friend(hero* a, hero* b);
void attack_hero(hero* a, hero* b);

void create_new_hero();
void show_all_hero_name();
void show_alive_hero_name();
void show_dead_hero_name();
void show_hero_skill_description();
void show_hero_friends();
void show_hero_resurrection_num();
void show_hero_sex();
void show_hero_color();
void show_hero_status();
void show_hero_all_properties();
void pay_resurrection();
void exit_system();


int main() {
    int prompt;
    do {
        cout << "-----------------------英雄管理系统-----------------------\n";
        cout << "0. 创建新英雄\n";
        cout << "1. 查看所有英雄的名称\n";
        cout << "2. 查看生存英雄的名称\n";
        cout << "3. 查看死亡英雄的名称\n";
        cout << "4. 查看英雄的技能描述\n";
        cout << "5. 查看英雄的朋友列表\n";
        cout << "6. 查看英雄的复活次数\n";
        cout << "7. 查看英雄的性别\n";
        cout << "8. 查看英雄的色系\n";
        cout << "9. 查看英雄的状态\n";
        cout << "10. 查看英雄的所有属性\n";
        cout << "11. 建立朋友关系\n";
        cout << "12. 解除朋友关系\n";
        cout << "13. 充钱复活英雄\n";
        cout << "14. 英雄发动攻击\n";
        cout << "15. 退出系统\n";
        cout << "请输入操作编号: ";
        cin >> prompt;
        switch (prompt) {
            case 0: {
                // 创建新英雄
                break;
            }
            case 1: {
                // 查看所有英雄的名称
                break;
            }
            case 2: {
                // 查看生存英雄的名称
                break;
            }
            case 3: {
                // 查看死亡英雄的名称
                break;
            }
            case 4: {
                // 查看英雄的技能描述
                break;
            }
            case 5: {
                // 查看英雄的朋友列表
                break;
            }
            case 6: {
                // 查看英雄的复活次数
                break;
            }
            case 7: {
                // 查看英雄的性别
                break;
            }
            case 8: {
                // 查看英雄的色系
                break;
            }
            case 9: {
                // 查看英雄的状态
                break;
            }
            case 10: {
                // 查看英雄的所有属性
                break;
            }
            case 11: {
                // 建立朋友关系
                break;
            }
            case 12: {
                // 解除朋友关系
                break;
            }
            case 13: {
                // 充钱复活英雄
                break;
            }
            case 14: {
                // 英雄发动攻击
                break;
            }
            case 15: {
                cout << "正在退出系统，请稍后......\n";
                sleep(1000);
                return 0;
            }
            default: {
                cout << "输入错误，请重新输入\n";
                break;
            }
        }
    } while (prompt != 15);
}

// 工具方法实现列表
void init_allocator() {
    id_allocator.current_used = 0;
    for (int i = 0; i < 1024; i++) {
        id_allocator.value[i] = 0;
    }
}

int allocate_one_hero_id() {
    for (int i = 0; i <= 1024; i++) {
        if (id_allocator.value[i] == 0) {
            id_allocator.value[i] = 1;
            return i;
        }
    }
    
    printf("has no enough hero id!\n");
    return -1;
}

void free_one_hero_id(int id) {
    id_allocator.value[id] == 0;
}

// 交互方法实现列表

void initHero(hero *h, string name, int hp, int attack, int v, int sp, color c, int gender, string desc, vector<int>& friends) {
    h->id = allocate_one_hero_id();
    h->name = name;
    h->hp = hp;
    h->attack = attack;
    h->v = v;
    h->sp = sp;
    h->c = c;
    h->gender = gender;
    h->skill_description = desc;
    h->status = 0;
    h->friends = friends;
    h->sex_reassignment = 0;
    h->resurrection_num = 0;
}

void create_new_hero() {
    hero h;
    cout << "请输入英雄的名字: ";
    cin >> h.name;
    cout << "请输入英雄的血量: ";
    cin >> h.hp;
    cout << "请输入英雄的攻击力: ";
    cin >> h.attack;
    cout << "请输入英雄的移动速度: ";
    cin >> h.v;
    cout << "请输入英雄的蓝量值: ";
    cin >> h.sp;
    cout << "请输入英雄的色系(0: red, 1: blue, 2: purple, 3: pink): ";
    int c;
    cin >> c;
    h.c = (color)c;
    cout << "请输入英雄的性别(0: 女性, 1: 男性): ";
    cin >> h.gender;
    cout << "请输入英雄的技能描述: ";
    cin >> h.skill_description;
    vector<int> friends;
    h.friends = friends;

    h.id = allocate_one_hero_id();
    HeroManager[h.id] = h;
}

void show_all_hero_name() {
    for (auto it = HeroManager.begin(); it != HeroManager.end(); it++) {
        cout << it->second.name << " ";
    }
    cout << endl;
}