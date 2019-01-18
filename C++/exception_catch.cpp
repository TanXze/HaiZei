/*************************************************************************
	> File Name: exception_catch.cpp
	> Author: Tanxiaoze
	> Mail: 2406577693@qq.com
	> Created Time: 2019年01月18日 星期五 14时41分50秒
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    //严格匹配
    try {
        throw 1;
    } catch (char c) {
        cout << "catch(char c)" << c << endl;
    } catch (short s) {
        cout << "catch(short s)" << s << endl;
    } catch (double d) {
        cout << "catch(double d)" << d << endl;
    } catch (int i) {
        cout << "catch(int i)" << i << endl;
    } catch (...) {
        cout << "catch(...)" << endl;
    }
}
