/*************************************************************************
	> File Name: exception_test.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 15时09分47秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Base {};

class Exception : public Base {
    private:
        int i;
        string info;
    public:
        Exception(int v1, string s1) { 
            i = v1;
            info = s1;
        }
        void what() { 
            cout << "exception id is " << i << endl;
            cout << "exception information is " << info << endl;
        }
};

void func(int i) {
    if (i < 10) {
        throw -1;
    } else if (i < 20) {
        throw -2;
    } else if (i < 30) {
        throw -3;
    }
    return ;
}

void myfunc(int i) {
    try {
        func(i);
    } catch (int i) {
        switch (i) {
            case -1: {
                //throw "Run Error";
                throw Exception(-1, "Run Error");
                break;
            }
            case -2: {
                //throw "Parameter Error";
                throw Exception(-2, "Parameter Error");
                break;
            }
            case -3: {
                //throw "Segment fault";
                throw Exception(-3, "Segment Error");
                break;
            }
        }
    }
}

int main() {
    int i;
    cin >> i;
    try {
        myfunc(i);
    } /*catch (const char *s) {
        cout << "exception information is : " << s << endl;
    }*/
    catch (Exception &e) {
        e.what();
    } catch (Base &b) {
        cout << "Base Exception" << endl;
    } catch (...) {
        cout << "Other Exception" << endl;
    }
    cout << "done" << endl;
    return 0;
}
