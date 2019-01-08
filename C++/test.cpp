/*************************************************************************
	> File Name: test.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月08日 星期二 19时26分14秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Mem {
    public:
        Mem() { 
            cout << "Mem" << endl;
        }
        ~Mem() {
            cout << "~Mem" << endl;
        }
};

class Disk {
    public:
        Disk() { 
            cout << "Disk" << endl;
        }
        ~Disk() { 
            cout << "~Disk" << endl;
        }
};

class CPU {
    public:
        CPU() { 
            cout << "CPU" << endl;
        }
        ~CPU() {
            cout << "~CPU" << endl;
        }
};

class Computer {
    private:
        Mem m;
        Disk d;
        CPU c;
    public:
        void PowerOn() { 
            cout << "Power On" << endl;
        }
        Computer() { 
            cout << "Computer" << endl;
        }
        ~Computer() { 
            cout << "~Computer" << endl;
        }
};

int main() {
    Computer c;
    return 0;
}
