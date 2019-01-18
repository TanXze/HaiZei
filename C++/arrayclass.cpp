/*************************************************************************
	> File Name: arrayclass.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月01日 星期二 20时16分38秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
    private:
        int length;
        int *data;
    public:
        Array() {
            length = 10;
            data = new int[length];
            for (int i = 0; i < length; i++) {
                data[i] = 0;
            }
        }
        Array(int len) {
            length = len;
            data = new int[length];
            for (int i = 0; i < length; i++) {
                data[i] = 0;
            }
        }
        int getlength() {
            return length;
        }
        bool getvalue(int index, int &value) {
            bool ret = (index >= 0) && (index < getlength());
            if (ret) {
                value = data[index];
            }
            return ret;
        }
        bool change(int index, int value, int &change) {
            bool ret = (index >= 0) && (index < getlength());
            if (ret) {
                data[index] = value;
                change = data[index];
            }
            return ret;
        }
        Array& operator=(const Array &obj) { 
            if (this != &obj) {
                int *p = new int[obj.length];
                if (p) {
                    for (int i = 0; i < obj.length; i++) {
                        p[i] = obj.data[i];
                    }
                    length = obj.length;
                    delete[] data;
                    data = p;
                }
            }
            return *this;
        }
        int& operator[](int index) { 
            if ((index < length) && (index >= 0)) {
                return data[index];
            } else {
                throw "txz";
            }
        }
        ~Array() {
            delete[] data;
            cout << "delete" << endl;
        }
};

int main() {
    Array t1;
    int value, change;
    cout << "t1.length:" << t1.getlength() << endl;
    cout << "t1.getvalue:" << endl;
    for (int i = 0; i < t1.getlength(); i++) {
        t1.getvalue(i, value);
        cout << i << ":" << value << endl;
    }
    cout << "t1.change:" << endl;
    for (int i = 0; i < t1.getlength(); i++) {
        t1.change(i, i + 1, change);
        cout << i << ":" << change << endl;
    }
    Array t2(15);
    cout << "t2.getlength:" << t2.getlength() << endl;
    cout << "t2.getvalue:" << t2.getvalue(20, value) << endl;
    cout << "t2.getvalue:" << t2.getvalue(10, value) << endl;
    cout << value << endl;
    cout << "t2.change:" << t2.change(20, 5, change) << endl;
    cout << "t2.change:" << t2.change(10, 9, change) << endl;
    cout << change << endl;
    cout << "t2.getvalue:" << endl;
    for (int i = 0; i < t2.getlength(); i++) {
        t2.getvalue(i, value);
        cout << i << ":" << value << endl;
    }

    t2 = t1;
    cout << "operator=:" << endl;
    for (int i = 0; i < t2.getlength(); i++) {
        t2.getvalue(i, value);
        cout << i << ":" << value << endl;
    }

    cout << "operator[]:" << endl;
    for (int i = 0; i < t2.getlength(); i++) {
        cout << i << ":" << t2[i] << endl;
    }
    return 0;
}
