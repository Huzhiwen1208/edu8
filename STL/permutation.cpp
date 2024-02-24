#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3};

    next_permutation(arr.begin(), arr.end());
    cout << arr[0] << arr[1] << arr[2] << endl;
    next_permutation(arr.begin(), arr.end());
    cout << arr[0] << arr[1] << arr[2] << endl;
    next_permutation(arr.begin(), arr.end());
    cout << arr[0] << arr[1] << arr[2] << endl;

    return 0;
}