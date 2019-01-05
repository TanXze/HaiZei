/*************************************************************************
	> File Name: new.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月01日 星期二 18时08分32秒
 ************************************************************************/

#include <iostream>
using namespace std;

namespace my_lib {
    int i = 2;
    namespace my_lib1 {
        int i = 3;
    }
}
//using namespace my_lib;
//using namespace my_lib1;
//using my_lib::i;
//using my_lib::my_lib1::i;

int main() {
    /*
    type *name = new type; //申请
    delete name; //收回
    type *name = new type(value); //单个变量初始化
    delete name;
    type *name = new type[length]; //申请一堆连续的空间
    delete[] name;
    */
    int *p = new int;
    *p = 5;
    cout << *p << endl;
    
    int *q = new int(10);
    cout << *q << endl;
    
    int *w = new int[10];
    for (int i = 0; i < 10; i++) {
        w[i] = i + 1;
    }
    for (int i = 0; i < 10; i++) {
        cout << w[i] << endl;
    }
    delete p;
    delete q;
    delete[] w;

    cout << my_lib::i << endl << my_lib::my_lib1::i << endl;
    return 0;
}
