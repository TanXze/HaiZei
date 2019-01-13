/*************************************************************************
	> File Name: array.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月13日 星期日 18时08分37秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, val;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> val;
        val = val < 0 || val > n ? 0 : val;
        arr.push_back(val);
    }
    for (int i = 0; i < n; i++) {
        while (arr[i] != 0 && arr[i] != i + 1) {
            swap(arr[i], arr[arr[i] + 1]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
