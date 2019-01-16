/*************************************************************************
	> File Name: inherittest3.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月10日 星期四 20时49分02秒
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
    private:
        string name;
        int age;
    public:
        void print() { 
            cout << name << "  " << age << endl;
        }
};
class B : public A {};
class C : public A {};
class D : public B, public C {}; //多继承

class People {
    private:
        string name;
        int age;
    public:
        People(string s1, int v1) : name(s1), age(v1) { 
            
        } 
        void print() { 
            cout << name << " " << age << endl;
        }
};

class Teacher : virtual public People {
    public:
        Teacher(string s1, int v1) : People(s1, v1) { 
            
        }
};

class Student : virtual public People {
    public: 
        Student(string s1, int v1) : People(s1, v1) {
            
        }
};

class Doctor : public Teacher, public Student {
    public:
        Doctor(string s1, int v1) : Teacher(s1 + "1", v1 + 1), Student(s1, v1), People(s1, v1) { 
            
        }
};

int main() {
    D d;
    B *pb = &d;
    C *pc = &d;
    void *pbb = pb;
    void *pcc = pc;
    if (pbb == pcc) {
        cout << "Point the same address!" << endl;
    } else {
        cout << "No!" << endl;
    }
    cout << pb << "  " << pbb << endl;
    cout << pc << "  " << pcc << endl;
    cout << &d << endl; //先继承B,与B的地址相同
    d.B::print();
    d.C::print();

    Doctor dd("qwe", 28);
    dd.Teacher()::print();
    dd.Student()::print();
    return 0;
}
