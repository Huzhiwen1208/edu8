#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    map<string, int> count;
    getline(cin, str);

    string temp = "";
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            count[temp] ++;
            temp = "";
            continue;
        }

        temp += str[i];
    }

    count[temp] ++;

    for (auto it = count.begin(); it != count.end(); it++) {
        cout << it->first << ' ' << it->second << endl;
    }
}
