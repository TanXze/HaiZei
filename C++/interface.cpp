/*************************************************************************
	> File Name: interface.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 14时40分16秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Interface {
    public:
        virtual bool open() = 0;
        virtual void close() = 0;
        virtual bool send(char *buf, int len) = 0;
        virtual int receive(char *buf, int len) = 0;
};



int main() {
    return 0;
}
