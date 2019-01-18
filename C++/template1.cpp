/*************************************************************************
	> File Name: template1.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 11时35分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

template <int N>
void func() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += i;
    }
    cout << sum << endl;
    return ;
}

template <typename T, int N>
class Test {
    private:
        T a[N];
    public:
        Test() { 
            for (int i = 0; i < N; i++) {
                a[i] = i + 1;
            }
        }
        void print() { 
            for (int i = 0; i < N; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

template <int N>
class Test<string, N> {
    private:
        string a[N];
    public:
        Test() { 
            for (int i = 0; i < N; i++) { 
                a[i] = "txz";
            }
        }
        void print() { 
            for (int i = 0; i < N; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    func<10>();
    Test<int, 10> t;
    t.print();
    Test<string, 10> t1;
    t1.print();
    return 0;
}
