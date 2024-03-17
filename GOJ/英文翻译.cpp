#include <bits/stdc++.h>
using namespace std;

void print_message(int type, char ch) {
    if (type == 0) {
        switch (ch) {
            case '0':
                break;
            case '1':
                printf("one ");
                break;
            case '2':
                printf("two ");
                break;
            case '3':
                printf("three ");
                break;
            case '4':
                printf("four ");
                break;
            case '5':
                printf("five ");
                break;
            case '6':
                printf("six ");
                break;
            case '7':
                printf("seven ");
                break;
            case '8':
                printf("eight ");
                break;
            case '9':
                printf("nine ");
        }
    }else if (type == 1) {
         switch (ch) {
            case '0':
                printf("ten ");
                break;
            case '1':
                printf("eleven ");
                break;
            case '2':
                printf("twelve ");
                break;
            case '3':
                printf("thirteen ");
                break;
            case '4':
                printf("forteen ");
                break;
            case '5':
                printf("fifteen ");
                break;
            case '6':
                printf("sixteen ");
                break;
            case '7':
                printf("seventeen ");
                break;
            case '8':
                printf("eighteen ");
                break;
            case '9':
                printf("ninteen ");
        }
    }else {
        switch(ch) {
            case '2':
                printf("twenty ");
                break;
            case '3':
                printf("thirty ");
                break;
            case '4':
                printf("forty ");
                break;
            case '5':
                printf("fifty ");
                break;
            case '6':
                printf("sixty ");
                break;
            case '7':
                printf("seventy ");
                break;
            case '8':
                printf("eighty ");
                break;
            case '9':
                printf("ninty ");
        }
    }
}

void translation(char* digits) {
    // 从低到高三位一组分开如1,111,111,111
    char arr[4][3];
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 3; j++)
            arr[i][j] = '0';
    int k = 0;
    for (int i = strlen(digits) - 1; i >= 0; i--) {
        arr[k/3][k%3] = digits[i];
        k++;
    }
    // 获取当前行数
    int rows = k / 3;
    for (int i = rows; i >= 0; i--) {
        // 分析数制
        char* message = (char*)malloc(sizeof(char)*30);
        switch (i) {
            case 3:
                strcpy(message, "billion ");
                break;
            case 2:
                strcpy(message, "million ");
                break;
            case 1:
                strcpy(message, "thousand ");
                break;
            case 0:
                strcpy(message, "");
                break;
        }
        // 分析当前行数字表示
        char ch = arr[i][2]; // 百位
        if (ch != '0') {
            print_message(0, ch);
            printf("hundred ");
        }
        if (arr[i][1] == '0' && arr[i][0] == '0') {
            continue;
        }
        if (ch != '0')
            printf("and ");
        ch = arr[i][1]; // 十位
        if (ch >= '2') {
            print_message(2, ch);
            print_message(0, arr[i][0]);
        } else if (ch == '0'){
            print_message(0, arr[i][0]);
        } else if (ch == '1') {
            print_message(1, arr[i][0]);
        }
        printf("%s", message);
    }
}

int main() {
    // 本题 2^31 -1 = 2147483647
	char digits[15];
    scanf("%s", digits);
    
    translation(digits);
    
 	return 0;
}