#include <bits/stdc++.h>
using namespace std;

// 1. +=  strcat()
// 2. ==  
// 3. <
// 4. >
// 5. length(), size()


int main() {
    string message = "Shuiniuge";
    // 1. +=
    message += " Kaoyan shangan";
    cout << message << endl;

    // 2. ==
    string message_cpy = "Shuiniuge Kaoyanshangan";
    printf("%s\n", message == message_cpy ? "Equals": "Not equal");

    // 3. > <
    string message_cmp = "ahuiniuge Kaoyan shangan";
    printf("%s\n", message > message_cmp ? "Shuiniuge Kaoyan shangan  >  ahuiniuge Kaoyan shangan":
        "Shuiniuge Kaoyan shangan  <=  ahuiniuge Kaoyan shangan");

    // 3.1 转大小写
    char ch = 'a';
    ch = toupper(ch);
    cout << ch << endl;

    // 4. length
    cout << "字符串长度：" << message.size() << endl;

    // 方法方法！！！！！
    // 5. erase(index); 删除index后面的所有，包括index
    // cout << message << endl;
    // message.erase(10);
    // cout << message << endl;
    // 5.1 replace(index, len, r_str); 把index处开始的len个字符，替换成r_str字符串。
    cout << message << endl;
    message.replace(10, 1, "");
    cout << message << endl;
    // 6. insert(0, "abc"); insert(index, insert_str);
    message.insert(10, "Jiangjiege ");
    cout << message << endl;

    // 7. 查找子串 find sub string，朴素查找，KMP算法:  str.find("GGbond")
    // 返回要查找字符串的下标，找不到返回string::npos
    // Shuiniuge Jiangjiege aoyan shangan
    int index = message.find("ao");
    cout << index << endl;

    cout << "Before action: " << message << endl;
    // 需求：把该字符串中的所有a替换成j8
    while (true) {
        if ((index = message.find("a")) != string::npos) {
            cout << "Found a in index: " << index << endl;
            message.replace(index, 1, "j8");
            cout << "After replacing the string: " << message << endl;
        }else {
            break;
        }
    }

    cout << "Final string: " << message << endl;
    return 0;
}