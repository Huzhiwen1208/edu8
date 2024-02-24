#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> counter;

    // 1. 加入键值对
    counter[2] = 1;
    counter[4] = 2;

    // 2. 打印我们的映射列表
    for (auto it = counter.begin(); it != counter.end(); it ++) {
        cout << it->first << ':' << it->second << endl;
    }

    for (auto pair : counter) {
        cout << pair.first << ':' << pair.second << endl;
    }

    // 3. 修改某个键对应的value
    counter[4] = 6;
    for (auto it = counter.begin(); it != counter.end(); it ++) {
        cout << it->first << ':' << it->second << endl;
    }
    
    // 4. 判断某一个键是否存在，存在则返回迭代器，否则返回end迭代器
    if (counter.find(100) != counter.end()) {
        cout << "100 存在" << endl;
    }else {
        cout << "100 不存在" << endl;
    }

    // 5. size() 有多少个键值对

    // 6. 默认根据key排序
    counter[100] = 4;
    counter[39] = 2;

    cout << "Final: " << endl;
    for (auto pair : counter) {
        cout << pair.first << ':' << pair.second << endl;
    }

    // 7. 乱序的Map, 不常用，但是性能高
    unordered_map<int, int> counter01;
    counter01[100] = 4;
    counter01[39] = 2;
    counter01[2] = 1;
    counter01[4] = 2;
    counter01[55] = 2;
    counter01[23] = 2;
    counter01[12] = 2;
    counter01[32] = 2;
    counter01[11] = 2;
    counter01[411] = 2;
    cout << "Final: " << endl;
    for (auto pair : counter01) {
        cout << pair.first << ':' << pair.second << endl;
    }
    return 0;
}