/*************************************************************************
	> File Name: complex.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 16时19分17秒
 ************************************************************************/

#include <iostream>
using namespace std;

class Complex {
    private:
        double real;
        double imag;
    public:
        Complex(double r = 0, double i = 0) { 
            real = r;
            imag = i;
        }
        double getR() {
            return this->real;
        }
        double getI() {
            return this->imag;
        }
        //friend Complex add(Complex &c1, Complex &c2);
        //Complex add(Complex &c1, Complex &c2);
        //friend Complex operator+(Complex &c1, Complex &c2);
        Complex operator+(Complex &c2);
        Complex operator-(Complex &c2);
        Complex operator*(Complex &c2);
        Complex operator/(Complex &c2);
        bool operator==(Complex &c2);
        bool operator!=(Complex &c2);
        Complex& operator=(const Complex &c2);
};

//Complex add(Complex &c1, Complex &c2) {
//Complex Complex::add(Complex &c1, Complex &c2) {
//Complex operator+(Complex &c1, Complex &c2) {
Complex Complex::operator+(Complex &c2) {
    Complex ret;
    //ret.real = c1.real + c2.real;
    //ret.imag = c1.imag + c2.imag;
    ret.real = this->real + c2.real;
    ret.imag = this->imag + c2.imag;
    return ret;
}

Complex Complex::operator-(Complex &c2) {
    Complex ret;
    ret.real = this->real - c2.real;
    ret.imag = this->imag - c2.imag;
    return ret;
}

Complex Complex::operator*(Complex &c2) {
    Complex ret;
    ret.real = this->real * c2.real - this->imag * c2.imag;
    ret.imag = this->real * c2.imag + this->imag * c2.real;
    return ret;
}

Complex Complex::operator/(Complex &c2) {
    Complex ret;
    ret.real = (this->real * c2.real + this->imag * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    ret.imag = (this->imag * c2.real - this->real * c2.imag) / (c2.real * c2.real + c2.imag * c2.imag);
    return ret;
}

bool Complex::operator==(Complex &c2) {
    if (this->real == c2.real && this->imag == c2.imag) {
        return true;
    } else {
        return false;
    }
}

bool Complex::operator!=(Complex &c2) {
    if (!this->operator==(c2)) {
        return true;
    } else {
        return false;
    }
}

Complex& Complex::operator=(const Complex &c2) {
    if (this != &c2) { //不允许自赋值
        this->real = c2.real;
        this->imag = c2.imag;
    }
    return *this;
}

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(2.0, 3.0);
    //Complex c3 = add(c1, c2);
    Complex c3, c4, c5, c6;
    //c3 = c3.add(c1, c2);
    //c3 = c1 + c2;
    //c3 = operator+(c1, c2);
    c3 = c1.operator+(c2);
    cout << c3.getR() << " + " << c3.getI() << "i" << endl;
    c4 = c1.operator-(c2);
    cout << c4.getR() << " + " << c4.getI() << "i" << endl;
    c5 = c1.operator*(c2);
    cout << c5.getR() << " + " << c5.getI() << "i" << endl;
    c6 = c1.operator/(c2);
    cout << c6.getR() << " + " << c6.getI() << "i" << endl;
    cout << c1.operator==(c2) << endl;
    cout << c1.operator!=(c2) << endl;
    (c4 = c3) = c2;
    cout << c2.getR() << " + " << c2.getI() << "i" << endl;
    return 0;
}
