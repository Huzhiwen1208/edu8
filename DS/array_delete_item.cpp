#include <bits/stdc++.h>
using namespace std;

int main() {
    int array[10] = {7, 2, 6, 12, 4, 5};
    // 删除元素2
    int deleteIndex = 1;
    // 从删除位置之后的元素向前移动一位
    for (int i = deleteIndex; i < 5; i++) {
        array[i] = array[i + 1];
    }
    for (int i = 0; i < 5; i++) {
        cout << array[i] << " ";
    }
    return 0;
}