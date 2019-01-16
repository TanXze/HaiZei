/*************************************************************************
	> File Name: duotai_example.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 09时50分24秒
 ************************************************************************/

#include <iostream>
using namespace std;

class CompanyA_Boss {
    public:
        int battle() { 
            int ret = 10;
            cout << "CompanyA_Boss :: battle = " << ret << endl;
            return ret;
        }
};

class CompanyB_Boss {
    public:
         virtual int fight() { 
            int ret = 8;
            cout << "CompanyB_Boss :: fight = " << ret << endl;
            return ret;
        }
};

class CompanyB_NewBoss : public CompanyB_Boss {
    public:
        int fight() {
            int ret = this->CompanyB_Boss::fight() * 2;
            cout << "CompanyB_NewBoss :: fight = " << ret << endl;
            return ret;
        }
};

void vs(CompanyA_Boss *c1, CompanyB_Boss *c2) {
    int a = c1->battle();
    int b = c2->fight();
    if (a > b) {
        cout << "CompanyA is winner" << endl;
    } else {
        cout << "CompanyB is winner" << endl;
    }
    return ;
}

int main() {
    CompanyA_Boss c1;
    CompanyB_Boss c2;
    vs(&c1, &c2);
    cout << "one year later.." << endl;
    CompanyB_NewBoss c3;
    vs(&c1, &c3);
    return 0;
}
