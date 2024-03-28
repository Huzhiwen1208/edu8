/**
 * 移动用户管理系统
 * 
 * 完成人组员：
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 1024        // 单用户拥有最大手机号个数

typedef struct address {
    char* province;         // 省
    char* city;             // 市
    char* county;           // 县
    char* details;          // 详细地址
} address;

typedef enum work_type {
    trip,
    ecom,
    food,
    cloth,
    labor
} work_type;

typedef struct mobile_user {
    char* username;         // 用户名
    int gender;             // 性别
    int age;                // 年龄
    unsigned long long id_card;            // 身份证号，唯一标识
    int phone_numbers[MAX_NUM];// 手机号码
    int current_phone_count; // 当前手机号个数
    work_type work;         // 工作类型
    address family_address; // 家庭住址
    
    struct mobile_user* next;
} mobile_user;

static mobile_user* head;   // 链表头

/// @brief 初始化移动用户存储链表，带头结点。 
void init_user_management();

/// @brief 获取当前用户个数
int get_user_num();

/// @brief 根据用户身份证查找，查到返回数据，否则返回NULL
mobile_user* find_user_by_id(unsigned long long id_card);

/// @brief 根据用户手机号查找，查到返回数据，否则返回NULL
mobile_user* find_user_by_phone(int phone_num);

/// @brief 根据用户名查找，如果查找到多个用户，则提示输入其他能确定唯一用户的信息。
mobile_user* find_user_by_name(char* username);

/// @brief 新增一个移动用户，如果已存在id_card，则打印错误；否则插入链表
void add_user(char* username, int gender, int age, unsigned long long id_card, 
    int *phone, int current_phone_count, work_type work, address addr);

typedef enum phone_action {
    DELETE,
    ADD
} phone_action;

/// @brief 根据用户身份证号，添加/删除一个手机号码
void modify_phones(unsigned long long id_card, int phone_num, phone_action act);

/// @brief 打印当前用户的所有手机号
void print_phones(unsigned long long id_card);

/// @brief 根据身份证号删除用户，如果与用户不存在则报错，否则删除即可。
void delete_user(unsigned long long id_card);

typedef enum sort_style {
    USERNAME,
    AGE,
    ID
} sort_style;

/// @brief 打印用户信息
void print_user(mobile_user* user);

/// @brief 查找所有数据，按要求排序：用户名、年龄、身份证号选其一。
void display_all_users(sort_style style);

/// @brief 将所有数据存储到文件中
void save_to_file(char* filename);

/// @brief 将文件中的数据读入链表，返回带头结点新链表
mobile_user* file_to_data(char* filename);

int main() {
    init_user_management();
    // 打印菜单
    printf("----------Welcome to the mobile user management system!----------\n");

    int choice;
    while (1) {
        printf("1. Add a user\n");
        printf("2. Modify phone numbers\n");
        printf("3. Print phone numbers\n");
        printf("4. Delete a user\n");
        printf("5. Display all users\n");
        printf("6. Save to file\n");
        printf("7. Read from file\n");
        printf("8. Exit\n");
        printf("Please input your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                // 添加用户，输入用户名、性别、年龄、身份证号、手机号、工作类型、家庭地址
                char username[1024];
                int gender;
                int age;
                unsigned long long id_card;
                int phone[MAX_NUM];
                int current_phone_count;
                work_type work;
                address addr;
                addr.city = (char*)malloc(1024);
                addr.county = (char*)malloc(1024);
                addr.details = (char*)malloc(1024);
                addr.province = (char*)malloc(1024);

                printf("Please input username: ");
                scanf("%s", username);
                printf("Please input gender, 0 is female, 1 is male: ");
                scanf("%d", &gender);
                printf("Please input age: ");
                scanf("%d", &age);
                printf("Please input id_card: ");
                scanf("%llu", &id_card);
                printf("Please input phone numbers count: ");
                scanf("%d", &current_phone_count);
                for (int i = 0; i < current_phone_count; i++) {
                    printf("Please input phone number %d: ", i+1);
                    scanf("%d", &phone[i]);
                }
                printf("Please input work type, 0 is trip, 1 is ecom, 2 is food, 3 is cloth, 4 is labor: ");
                scanf("%d", &work);
                printf("Please input address(province city county details): ");
                scanf("%s", addr.province);
                scanf("%s", addr.city);
                scanf("%s", addr.county);
                scanf("%s", addr.details);

                // 添加用户
                add_user(username, gender, age, id_card, phone, current_phone_count, work, addr);
                break;
            }
            case 2: {
                // 修改用户手机号，输入身份证号、手机号、操作类型
                unsigned long long id_card;
                int phone_num;
                int act;

                printf("Please input id_card: ");
                scanf("%llu", &id_card);
                printf("Please input phone number: ");
                scanf("%d", &phone_num);
                printf("Please input action, 0 is delete, 1 is add: ");
                scanf("%d", &act);

                modify_phones(id_card, phone_num, act);
                break;
            }
            case 3: {
                // 打印用户手机号，输入身份证号
                unsigned long long id_card;
                printf("Please input id_card: ");
                scanf("%llu", &id_card);

                print_phones(id_card);
                break;
            }
            case 4: {
                // 删除用户，输入身份证号
                unsigned long long id_card;
                printf("Please input id_card: ");
                scanf("%llu", &id_card);

                delete_user(id_card);
                break;
            }
            case 5: {
                // 显示所有用户，输入排序方式
                int style;
                printf("Please input sort style, 0 is username, 1 is age, 2 is id: ");
                scanf("%d", &style);

                display_all_users(style);
                break;
            }
            case 6: {
                // 保存到文件，输入文件名
                char filename[1024];
                printf("Please input filename: ");
                scanf("%s", filename);

                save_to_file(filename);
                break;
            }
            case 7: {
                // 从文件读取数据，输入文件名
                char filename[1024];
                printf("Please input filename: ");
                scanf("%s", filename);

                mobile_user* new_head = file_to_data(filename);
                head = new_head;
                break;
            }
            case 8: {
                // 退出
                return 0;
            }
            default:
                printf("Unsupported choice, please input again.\n");
        }
    }
}

void init_user_management() {
    head = (mobile_user*)malloc(sizeof(mobile_user));
    head->next = NULL;
}

mobile_user* find_user_by_id(unsigned long long id_card) {
    mobile_user* p = head->next;
    while (p) {
        if (p->id_card == id_card) {
            return p;
        }
        p = p->next;
    }

    return NULL;
}

mobile_user* find_user_by_phone(int phone_num) {
    mobile_user* p = head->next;
    while (p) {
        for (int i = 0; i < p->current_phone_count; i++)
            if (p->phone_numbers[i] == phone_num)
                return p;
        p = p->next;
    }

    return NULL;
}

void add_user(char* username, int gender, int age, unsigned long long id_card, 
    int *phone, int current_phone_count, work_type work, address addr
) {
    if (find_user_by_id(id_card)) {
        printf("The user{id=%llu} exists!\n", id_card);
        return;
    }

    printf("------------------\n");

    mobile_user* s = (mobile_user*)malloc(sizeof(mobile_user));
    s->next = NULL;
    s->username = (char*)malloc(1024);
    strcpy(s->username, username);
    s->gender = gender;
    s->age = age;
    s->id_card = id_card;
    for (int i = 0; i < current_phone_count; i++) {
        s->phone_numbers[i] = phone[i];
    }
    s->current_phone_count = current_phone_count;
    s->work = work;
    s->family_address = addr;

    // 头插入插入链表中
    s->next = head->next;
    head->next = s;

    printf("The user{id=%llu} has been added.\n", id_card);
}

void modify_phones(unsigned long long id_card, int phone_num, phone_action act) {
    mobile_user* user = find_user_by_id(id_card);
    if (user == NULL) {
        printf("The user{id=%llu} not found\n", id_card);
        return;
    }

    switch (act){
        case DELETE:
            for (int i = 0; i < user->current_phone_count; i++) {
                if (user->phone_numbers[i] == phone_num) {
                    for (int j = i+1; j < user->current_phone_count; j++) {
                        user->phone_numbers[j-1] = user->phone_numbers[j];
                    }
                    user->current_phone_count --;
                    return;
                }
            }
            break;
        case ADD:
            if (user->current_phone_count >= MAX_NUM)
                printf("The count of phone numbers is exceeded.\n");
            else
                user->phone_numbers[user->current_phone_count++] = phone_num;
            break;
        default:
            printf("Unsupported action to phone_number\n");
    }
}

void print_phones(unsigned long long id_card) {
    mobile_user* user = find_user_by_id(id_card);
    if (user == NULL) {
        printf("The user{id=%llu} not found\n", id_card);
        return;
    }

    printf("The user's {id=%llu} phone list: [", id_card);
    for (int i = 0; i < user->current_phone_count; i++) {
        printf("%d%c", user->phone_numbers[i], i == user->current_phone_count - 1 ? ']': ',');
    }
    printf("\n");
}

mobile_user* find_user_by_name(char* username) {
    mobile_user* p = head->next;
    mobile_user* result = NULL;
    while (p) {
        if (strcmp(p->username, username) == 0) {
            if (result) {
                printf("The username is not unique, please input other information: id_card to find the user.\n");
                unsigned long long id_card;
                scanf("%llu", &id_card);
                return find_user_by_id(id_card);
            }
            result = p;
        }
        p = p->next;
    }

    return result;
}

void delete_user(unsigned long long id_card) {
    mobile_user* p = head;
    while (p->next) {
        if (p->next->id_card == id_card) {
            mobile_user* q = p->next;
            p->next = q->next;
            free(q);
            printf("The user{id=%llu} has been deleted.\n", id_card);
            return;
        }
        p = p->next;
    }

    printf("The user{id=%llu} not found\n", id_card);
}

void print_user(mobile_user* user) {
    printf("User{id_card: %llu, username: %s, gender: %d(male is 1, female is 0), age: %d, work: %d, address: %s %s %s %s, phone_numbers: [",
        user->id_card, user->username, user->gender, user->age, user->work, user->family_address.province, user->family_address.city, user->family_address.county, user->family_address.details);
    for (int i = 0; i < user->current_phone_count; i++) {
        printf("%d%c", user->phone_numbers[i], i == user->current_phone_count - 1 ? ']': ',');
    }
    printf("\n");
}

void display_all_users(sort_style style) {
    if (get_user_num() == 0) {
        printf("No user found.\n\n");
        return;
    }
    mobile_user* p = head->next;
    switch (style) {
        case USERNAME: {
            // 按照用户名排序后输出，这里将链表转换为数组，然后排序
            mobile_user* users_arr[1024];
            int count = 0;
            while (p) {
                users_arr[count++] = p;
                p = p->next;
            }
            if (count > 1)
                for (int i = 0; i < count; i++) {
                    for (int j = i+1; j < count; j++) {
                        if (strcmp(users_arr[i]->username, users_arr[j]->username) > 0) {
                            mobile_user* tmp = users_arr[i];
                            users_arr[i] = users_arr[j];
                            users_arr[j] = tmp;
                        }
                    }
                }
            for (int i = 0; i < count; i++) {
                print_user(users_arr[i]);
            }
            break;
        }
        case AGE: {
            // 按照年龄排序后输出，这里将链表转换为数组，然后排序
            mobile_user* users_arr[1024];
            int count = 0;
            while (p) {
                users_arr[count++] = p;
                p = p->next;
            }
            if (count > 1)
                for (int i = 0; i < count; i++) {
                    for (int j = i+1; j < count; j++) {
                        if (users_arr[i]->age > users_arr[j]->age) {
                            mobile_user* tmp = users_arr[i];
                            users_arr[i] = users_arr[j];
                            users_arr[j] = tmp;
                        }
                    }
                }
            for (int i = 0; i < count; i++) {
                print_user(users_arr[i]);
            }
            break;
        }
        case ID: {
            // 按照身份证号排序后输出, 这里将链表转换为数组，然后排序
            mobile_user* users_arr[1024];
            int count = 0;
            while (p) {
                users_arr[count++] = p;
                p = p->next;
            }
            if (count > 1)
                for (int i = 0; i < count; i++) {
                    for (int j = i+1; j < count; j++) {
                        if (users_arr[i]->id_card > users_arr[j]->id_card) {
                            mobile_user* tmp = users_arr[i];
                            users_arr[i] = users_arr[j];
                            users_arr[j] = tmp;
                        }
                    }
                }
            for (int i = 0; i < count; i++) {
                print_user(users_arr[i]);
            }
            break;
        }
        default:
            p = head->next;
            while (p) {
                print_user(p);
                p = p->next;
            }
            break;
    }

    
}

void save_to_file(char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return;
    }

    mobile_user* user = head->next;
    while (user) {
        fprintf(fp, "User{id_card: %llu, username: %s, gender: %d(male is 1, female is 0), age: %d, work: %d, address: %s %s %s %s, phone_numbers: [",
            user->id_card, user->username, user->gender, user->age, user->work, user->family_address.province, user->family_address.city, user->family_address.county, user->family_address.details);
        for (int i = 0; i < user->current_phone_count; i++) {
            fprintf(fp, "%d%c", user->phone_numbers[i], i == user->current_phone_count - 1 ? ']': ',');
        }
        fprintf(fp, "\n");
        user = user->next;
    }

    fclose(fp);
    printf("The data has been saved to file %s\n", filename);
}

mobile_user* file_to_data(char* filename) {
    mobile_user* result;

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        return NULL;
    }

    mobile_user* p = (mobile_user*)malloc(sizeof(mobile_user));
    p->next = NULL;
    result = p;

    while (!feof(fp)) {
        mobile_user* user = (mobile_user*)malloc(sizeof(mobile_user));
        user->next = NULL;
        char ch;
        fscanf(fp, "User{id_card: %llu, username: %s, gender: %d(male is 1, female is 0), age: %d, work: %d, address: %s %s %s %s, phone_numbers: [",
            &user->id_card, user->username, &user->gender, &user->age, &user->work, user->family_address.province, user->family_address.city, user->family_address.county, user->family_address.details);
        for (int i = 0; i < user->current_phone_count; i++) {
            fscanf(fp, "%d%c", &user->phone_numbers[i], &ch);
        }
        fscanf(fp, "%c", &ch);

        p->next = user;
        p = user;
        if (feof(fp))
            break;
    }

    fclose(fp);
    printf("The data has been read from file %s\n", filename);
    return result;
}

int get_user_num() {
    int count = 0;
    mobile_user* p = head->next;
    while (p) {
        count ++;
        p = p->next;
    }

    return count;
}