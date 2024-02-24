#include <bits/stdc++.h>
using namespace std;

/**
 * arr.size() 返回当前元素个数
 * arr.begin(), arr.end() 迭代器
 * arr.push_back(item); 把一个数添加到末尾
 * arr.pop_back(); 把最后一个元素弹出来
 * arr.erase(it); 删除指定位置的元素
 * vec.insert(it, n, item); // 在迭代器指向的位置插入n个item
 * 
 * 1. 求最值: max_element, min_element
 * 2. 从小到大排序: sort(arr.begin(), arr.end());
 * 3. 逆置: reverse(arr.begin(), arr.end());
*/
int main() {
    int n = 5;
    vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }

    auto it = arr.begin();
    cout << "The first item: " << *it << endl;
    cout << "The first item: " << arr[0] << endl;

    cout << "Length: " << arr.size() << endl;
    arr.push_back(100);
    cout << "After push one item, Length: " << arr.size() << endl;

    arr.pop_back();
    cout << "After pop one item, Length: " << arr.size() << endl;

    arr.erase(2 + arr.begin());
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    arr.insert(arr.begin() + 2, 1, 2);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    int max = *max_element(arr.begin(), arr.end());
    cout << "The max value: " << max << endl;
    int min = *min_element(arr.begin(), arr.end());
    cout << "The min value: " << min << endl;

    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rand() % 100;
    }
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    sort(arr.begin(), arr.end());
    cout << "After sort------" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    reverse(arr.begin(), arr.end());
    cout << "After reverse------" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    cout << "Sort in [1, 4)" << endl; // 73 58 49 30 7  ->  73 30 49 58 7
    sort(arr.begin() + 1, arr.end() - 1);
    cout << "After Sort------" << endl;
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    // 朴素数组演示排序
    int array[20];
    for (int i = 0; i < 20; i++)
        array[i] = rand() % 100;
    for (int i = 0; i < 20; i++)
        printf("%d%c", array[i], i == 20-1?'\n':' ');
    
    sort(array, array+20);
    puts("After sort----");
    for (int i = 0; i < 20; i++)
        printf("%d%c", array[i], i == 20-1?'\n':' ');
    return 0;
}