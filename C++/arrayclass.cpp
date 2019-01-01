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
            for (int i = 0; i < length; i++) {
                data[i] = 0;
            }
        }
        Array(int len) {
            length = len;
            /*for (int i = 0; i < length; i++) {
                data[i] = 0;
            }*/
        }
        int getlength() {
            return length;
        }
        int getnumber(int index) {
            if (index < length) {
                return data[index];
            } else {
                length = index + 1;
            }
        }
        int change(int index, int value) {
            if (index < length) {
                data[index] = value;
            } else {
                length = index + 1;
            }
        }
};

int main() {
    Array t1;
    cout << t1.getlength() << endl;
    //cout << t1.getnumber(5) << endl;
    //cout << t1.change(5, 4) << endl;
    Array t2(15);
    cout << t2.getlength() << endl;
    //cout << t2.getnumber(9) << endl;
    //cout << t2.change(12, 8) << endl;
    return 0;
}
