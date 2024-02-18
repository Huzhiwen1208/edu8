#include <bits/stdc++.h>
using namespace std;

int main() {
    int array[10] = {7, 2, 6, 4, 5};
    // 插入12到6与4之间
    int insertIndex = 3;
    int insertValue = 12;
    // 从后向前，将插入位置之后的元素向后移动一位
    for (int i = 4; i >= insertIndex; i--) {
        array[i + 1] = array[i];
    }
    array[insertIndex] = insertValue;
    for (int i = 0; i < 6; i++) {
        cout << array[i] << " ";
    }
    return 0;
}