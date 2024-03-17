#include <stdio.h>
#include <string.h>
int main() {
    /**
     * 字符串本质：就是字符数组 & 结尾一个\0
    */
    char message[] = {'a', 'b', 'c', '\0'};  // abc
    printf("%s\n", message);

    char name[] = {'h', 'o', 'n', 'g', 'y', 'a', 'n', 'g', '\0'}; // hongyang
    printf("name: %s\n", name);

    // C语言提供一个方便的写法，让我们能直接写出字符串 + 忽略\0:  双引号就好了
    char temp[] = "123";  // => {'1', '2', '3', '\0'};
    puts(temp);


    // 1. 字符串读取
    char m[1024];
    scanf("%s", m);

    // 2. 字符串修改==>数组修改
    // 3. 字符串函数
    // 3.1 字符串长度
    printf("the length of m: %lu\n", strlen(m));
    // 3.2 字符串比较，两个字符串是否相等
    char n[] = "GGBOND";
    strcmp(m, n);  // 返回0代表相等，否则不等

    // 4. 指针
    char* ptr = "KKKKKK\n"; // 字符串指针
    printf("%s", ptr);
    return 0;
}