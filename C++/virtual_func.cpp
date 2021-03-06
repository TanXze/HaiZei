/*************************************************************************
	> File Name: virtual_func.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月16日 星期三 14时21分34秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Shap {
    public:
        virtual double area() = 0;
        //virtual void print() = 0;
};

class Rect : public Shap {
    private:
        double h;
        double w;
    public:
        Rect(double v1, double v2) { 
            h = v1;
            w = v2;
        }
        double area() { 
            return h * w;
        }
};

class Circle : public Shap {
    private:
        double r;
    public:
        Circle(double v) { 
            r = v;
        }
        double area() { 
            return 3.14 * r * r;
        }
};

int main() {
    Rect r(3.4, 4.5);
    Circle c(0.6);
    cout << r.area() << endl << c.area() << endl;
    return 0;
}
