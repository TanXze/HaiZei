/*************************************************************************
	> File Name: inherit.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月08日 星期二 19时53分13秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Father {
    protected:
        int i;
    public:
        Father() { 
            i = 100;
        }
        int get() { 
            return i;
        }
        virtual void say() { 
            cout << "I'm Father." << endl;
        }
};

class Son : public Father {
    private:
        int age;
    public:
        int getAge() {
            return age;
        }
        int add(int v) { 
            age = i + v;
            return age;
        }
        void say() { 
            cout << "I'm Son." << endl;
        }
};

void how_to_say(Father *f) {
    f->say();
}

int main() {
    Father f;
    Son s;
    cout << s.getAge() << endl;
    cout << s.get() << endl;
    cout << s.add(5) << endl;
    how_to_say(&f);
    how_to_say(&s);
    return 0;
} 
