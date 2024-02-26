#include <stdio.h>
#include <stdlib.h> // 头文件就是一堆函数

void printArray(int arr[], int n) {
    printf("打印数组-----\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    puts("");
}

int getMax(int arr[], int n) {
    int max = 0;
    // 维护一个最大值max, 遍历数组
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

/// @brief 对数组求和
/// @param arr 被求和的数组
/// @param n 数组的长度
/// @return 数组的和
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

int avgArray(int arr[], int n) {
    int sum = sumArray(arr, n);
    int avg = sum/n;
    return avg;
}

// TODO 实现该方法
float fcArray(int arr[], int n);

int main() {
    // 1. 数组的初始化
    int arr[10];  // 10个元素的数组

    for (int i = 0; i < 10; i++)
        arr[i] = rand() % 1000;

    // 2. 访问？遍历: 一遍经过
    int item = arr[4]; // 访问第五个元素,因为从0开始
    printf("数组的第五个元素：%d\n", item);

    printArray(arr, 10);

    // 3. 修改数组元素的值
    arr[4] = 888;
    printf("修改arr[4] = 888后\n");
    printArray(arr, 10);

    // 4. 对这10个数，求最大值、求和、求整数平均
    int max = getMax(arr, 10);
    printf("该数组中的最大值是：%d\n", max);

    int sum = sumArray(arr, 10);
    printf("该数组的和是: %d\n", sum);

    int avg = avgArray(arr, 10);
    printf("该数组的平均值是: %d\n", avg);

    // 5. 对数组完成求方差
    // float fc = fcArray(arr, 10);
    // printf("该数组的方差是: %.2f\n", fc);
    // 6. 对两个数组合并。
        // a: 1,2,3,4  b: 3,2,1  -> c: 1,2,3,4,3,2,1   a || b => c
        // a(4), b(3), c(7)
    int a[] = {1,2,3,4};
    int a_len = 4;

    int b[] = {3,2,1};
    int b_len = 3;

    int c[7] = {0};
    // TODO 实现数组的合并，预期是1234321
    printArray(c, 7);


    // 777. 二维数组=>矩阵
    int arr_t[10][10]; // 10x10
    for (int i = 0; i < 10; i++) // 行
        for (int j = 0; j < 10; j++) // 列
            arr_t[i][j] = 3;

    puts("打印矩阵：\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) // 列
            printf("%d ", arr_t[i][j]);
        puts("");
    }

    arr_t[1][2] = 100;
    puts("打印矩阵：\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) // 列
            printf("%d ", arr_t[i][j]);
        puts("");
    }
    return  0;
}