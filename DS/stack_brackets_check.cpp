#include <stdio.h>

#define StackMaxSize 1024

typedef struct Stack {
    int CurrentSize;  // 当前栈的元素个数，初始化为0
    int Top; // 当前栈顶指针，指向栈顶元素
    int Value[StackMaxSize]; // 栈的存储数据处
} Stack;

void InitialzeStack(Stack* stack) {
    // 初始化一个空栈
    stack->CurrentSize = 0;
    stack->Top = -1;
    for (int i = 0; i < StackMaxSize; i++) 
        stack->Value[i] = 0;
}

void Push(Stack* stack, int item) {
    // 将item元素压入栈中，如果栈满则报错，否则正常压入
    if (stack->Top == StackMaxSize) {
        printf("栈已经满了，不能再压了哦~\n");
        return;
    }
    
    stack->Top++;
    stack->Value[stack->Top] = item;
}

int Pop(Stack* stack) {
    // 弹出栈顶元素，如果栈是空的则报错，否则正常弹出
    if (stack->Top == -1) {
        printf("栈已经空了，不能再要了哦~\n");
        return 0;
    }
    
    int result = stack->Value[stack->Top];
    stack->Top--;
    return result;
}

int GetTop(Stack* stack) {
    // 读取栈顶元素，如果栈是空的则报错，否则正常读取，不弹出
    if (stack->Top == -1) {
        printf("栈是空的，没有元素啦~\n");
        return 0;
    }
    
    return stack->Value[stack->Top];
}

int IsLeft(char ch) {
    return ch == '(' || ch == '[' || ch == '{';
}

int Match(char right, char left) {
    switch (right){
        case ')':
            return left == '(';
        case ']':
            return left == '[';
        case '}':
            return left == '{';
        default:
            break;
    }
}

int CheckoutBrackets(Stack *stack, char* brackets) {
    // 括号匹配检测，如果匹配返回1，否则返回0
    for (int i = 0; brackets[i]; i++) {
        if (IsLeft(brackets[i])) {
            // 左括号，进栈
            Push(stack, brackets[i]);
        } else {
            // 右括号，出栈
            char left = Pop(stack);
            if (!Match(brackets[i], left)) {
                // 不匹配，退出程序
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    Stack s;
    InitialzeStack(&s); // 初始化
    
    char* brackets = "{}()[][][)";
    int valid = CheckoutBrackets(&s, brackets);
    if (valid)
        printf("括号匹配~\n");
    else
        printf("括号不匹配~\n");
    return 0;
}