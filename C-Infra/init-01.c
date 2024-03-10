#include <stdio.h> // head file

int main() {

    printf("Hello, world"); // print format 格式化输出

    // 注释1
    /* 注释2 */
    /**
     * 数学中：Z R：整数、实数：5、1.6
     * 提供数据类型：int(integer)、float(浮点数)、double(更精确的浮点数)
    */

    // 样例1：计算两个整数10、11的加减乘除、取余
    int a = 10, b = 11;
    int sum = a + b;
    int sub = a - b;
    int multi = a * b;
    int div = a / b; // 除法和数学中的不一样，整数之间的除法，是整除的，去掉小数点后所有的。
    int y = b % a; // 11 / 10 = 1 ... 1，余数是1，所以y = 1.

    // 打印
    printf("sum = %d\n", sum);
    printf("sub = %d\n", sub);
    printf("multi = %d\n", multi);
    printf("div = %d\n", div);
    printf("yushu = %d\n", y);

    // 样例2：计算两个浮点数1.6、2.3的加减乘除
    float c = 1.6, d = 2.3;
    float sum2 = c + d;
    float sub2 = c - d;
    float multi2 = c * d;
    float div2 = c / d; // 小数的除法和数学中的一样，除法的结果是小数。

    // 打印
    printf("sum2 = %f\n", sum2);
    printf("sub2 = %f\n", sub2);
    printf("multi2 = %f\n", multi2);
    printf("div2 = %f\n", div2);

    // text文本字符串：字符串是由字符组成的，字符是由字节组成的。char* 是字符串的类型。
    char ch = 'A';
    printf("16 进制：%x\n", ch);

    char* message = "25 kaoyan";
    printf("message=%s\n", message);

    // %e
    double x = 1231321.234;
    printf("x = %e\n", x);

    // %u
    int val = 123;
    printf("val = %10u\n", val);
    return 0;
}