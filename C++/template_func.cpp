/*************************************************************************
	> File Name: template_func.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 15时58分00秒
 ************************************************************************/

#include <iostream>
using namespace std;

#define SWAP(t, a, b) { \
    t temp = a;      \
    a = b;          \
    b = temp;       \
}

void my_swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void my_swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void my_swap(string &s1, string &s2) {
    string temp = s1;
    s1 = s2;
    s2 = temp;
}

//泛型编程,函数模板
template <typename T>
void my_swap1(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

class Test {
    public:
        Test(const Test &t) {
            
        }
        Test() {
            
        }
};

template <typename T>
void my_sort(T *a, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {
            if (a[i] > a[j]) {
                my_swap1(a[i], a[j]);
            }
        }
    }
}

template <typename T>
void print(T *a, int len) {
    for (int i = 0; i < len; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

template <typename T1, typename T2, typename T3>
T1 add(T2 a, T3 b) {
    return static_cast<T1>(a + b);
}

int main() {
    string s1 = "hai", s2 = "zei";
    int a = 10, b = 20;
    double c = 3.1, d = 4.5;
    SWAP(int, a, b);
    SWAP(double, c, d);
    SWAP(string, s1, s2);
    my_swap(a, b);
    my_swap(c, d);
    my_swap(s1, s2);
    my_swap1(a, b);
    my_swap1(c, d);
    my_swap1(s1, s2);
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;
    cout << s1 << " " << s2 << endl;
    Test t1, t2;
    my_swap1(t1, t2);

    int x[5] = {3, 2, 1, 4, 6};
    double y[5] = {3.1, 4.2, 1.7, 4.3, 0.2};
    string s[5] = {"c", "java", "c++", "c#", "python"};
    print(x, 5);
    my_sort(x, 5);
    print(x, 5);
    cout << endl;
    print(y, 5);
    my_sort(y, 5);
    print(y, 5);
    cout << endl;
    print(s, 5);
    my_sort(s, 5);
    print(s, 5);

    int r1 = add<int>(0.5, 0.3);
    int r2 = add<int, float>(0.5, 0.6);
    int r3 = add<int, float, float>(0.5, 0.5);
    cout << r1 << endl << r2 << endl << r3 << endl;
    return 0;
}
