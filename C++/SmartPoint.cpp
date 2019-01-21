/*************************************************************************
	> File Name: qwe.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月21日 星期一 18时33分15秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Test {
    private:
        int i;
    public:
        Test(int v = 0) { 
            i = v;
        }
        int getI() { 
            return i;
        }
};

class SmartPoint {
    private:
        Test *mp;
    public:
        SmartPoint(Test *p = NULL) { 
            mp = p;
        }
        SmartPoint(const SmartPoint &obj) { 
            mp = obj.mp;
            const_cast<SmartPoint &>(obj).mp = NULL;
        }
        Test* operator->() { 
            return mp;
        }
        Test& operator*() { 
            return *mp;
        }
        Test& operator=(const SmartPoint &obj) { 
            if (this != &obj) { //防止自赋值
                delete mp; //收回当前对象
                mp = obj.mp; 
                const_cast<SmartPoint &>(obj).mp = NULL;
            }
            return *this;
        }
        ~SmartPoint() {
            cout << "delete" << endl;
            delete mp;
        }
};

int main() {
    for (int i = 0; i < 5; i++) {
        SmartPoint p = new Test(i);
        cout << p->getI() << endl;
    }
    SmartPoint p1(new Test(1));
    SmartPoint p2(new Test(2));
    p1 = p2;
    return 0;
}
