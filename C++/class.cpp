/*************************************************************************
	> File Name: class.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2018年12月25日 星期二 20时24分57秒
 ************************************************************************/

#include <iostream>
#include <string>

/*
using std::cin;
using std::cout;
using std::endl;
using std::string;
*/
using namespace std;

namespace my_lib{
    class People {
        private:
            int age;
            string name;
            //double height;
            //double weight;
            //double salary;
            //bool sex;
        public:
        People(string s) {
            cout << "People" << endl;
            name = s;
        }
        int getAge() {
            return age;
        }
        string getName() {
            return name;
        }
    };
}

using my_lib::People;
int main() {
    People p("txz");
    People* P = new People("TXZ");
    cout << p.getName() << endl;
    cout << P->getName() << endl;
    delete P;
    return 0;
}
