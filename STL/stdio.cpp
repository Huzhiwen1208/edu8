#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << "We got n: " << n << ", m: " << m << endl; // printf("We got n: %d, m: %d\n", n, m);

    string message;

    // 1. 读取字符串，直到碰到空格类型\n \t都会停止读取
    // cin >> message;
    // cout << message << endl;

    // 2. 读取一行，碰到\n结束
    // 吞字符
    cin.get();
    getline(cin, message);
    cout << message << endl;

    return 0;
}