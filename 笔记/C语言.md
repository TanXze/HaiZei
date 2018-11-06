## C语言

#### printf函数

头文件：stdio.h

原型：int printf(const char *format, ...);

format:格式控制字符串

...：可变参数列表

返回值：输出字符的数量

#### scanf函数

头文件：stdio.h

原型：int scanf(const char *format, ...);

format:格式控制字符串

...：可变参数列表

返回值：成功读入的参数个数

> 请使用printf函数，求解一个数字n的十进制表示的数字位数

```c
#include <stdio.h>

int main() {
    int a;
    char str[100];
    FILE *fout = fopen("/dev/null", "w");
    scanf("%d",&a);
    printf(" has %d dights\n", printf("%d", a));   //printf
    printf("%d\n", sprintf(str, "%d", a));    //sprintf
    for (int i = 1, j = 0; i <= 20; i++) {
        j += sprintf(str + j, "%d", i);
    }
    printf("str = %s\n", str);
    printf("%d\n", fprintf(fout, "%d", a));   //fprintf
    return 0;
}
```

> 请写一个程序，读入一个行字符串（可能包含空格），输出这个字符串中字符的数量

```c
#include <stdio.h>

int main() {
    int n;
    char str[100];
    scanf("%[^\n]", str);
    n = printf("%s", str);
    printf(" has %d digits\n", n);
    return 0;
}
```

#### 基本运算符

|     运算符     |          说明          |
| :------------: | :--------------------: |
|       =        |       赋值运算符       |
| +、-、×、/、() |      基本四则运算      |
|       %        |       求余运算符       |
|  &、\|、^、~   |         位运算         |
|     <<、>>     | 左移（乘）、右移（除） |

#### pow函数（指数函数）

头文件：math.h

原型：double pow(double a, double b);

a：底数

b：指数

返回值：返回结果

例：pow(2, 3) = 8

#### sqrt函数（开平方函数）

头文件：math.h

原型：double sqrt(double x);

x：被开方数

返回值：返回结果

例：sqrt(16) = 4

> sqrt的两种实现

```c
#include <stdio.h>
#include <math.h>
#include <time.h>

#define TEST_TIME(func) ({ \
    int begin = clock(); \
    double ret = func; \
    int end = clock(); \
    printf("%lfms\n", (end - begin) * 1.0 / CLOCKS_PER_SEC * 1000); \
    ret; \
})

double _sqrt1(double x) {
    double head = -100, tail = 100, mid;
    #define EPS 1e-7
    while (tail - head > EPS) {
        mid = (head + tail) / 2.0;
        if (mid * mid < x) head = mid;
        else tail = mid;
    }
    #undef EPS
    return head;
}

double f1(double x, double n) {
    return x * x - n;
}

double f1_prime(double x) {
    return 2 * x;
}

double newton(double x0, double n, double (*f)(double, double), double (*f_prime)(double)) {
    double x = x0;
    int cnt = 0;
    #define EPS 1e-7
    x -= f(x, n) / f_prime(x);
    x -= f(x, n) / f_prime(x);
    x -= f(x, n) / f_prime(x);
    x -= f(x, n) / f_prime(x);
    cnt += 1;
    #undef EPS
    printf("newton run %d times\n", cnt);
    return x;
}

int main() {
    double x;
    while (scanf("%lf", &x) != EOF) {
        printf("%lf\n", TEST_TIME(_sqrt1(x)));
        printf("%lf\n", TEST_TIME(newton(1.0, x, f1, f1_prime)));
        printf("%lf\n", TEST_TIME(newton(2.0, x, f1, f1_prime)));
        printf("%lf\n", TEST_TIME(newton(5.0, x, f1, f1_prime)));
    }
    return 0;
}
```



#### ceil函数（上取整函数）

头文件：math.h

原型：double ceil(double x);

x：某个实数

返回值：返回结果

例：ceil(4.1) = 5

#### floor函数（下取整函数）

头文件：math.h

原型：double floor(double x);

x：某个实数

返回值：返回结果

例：floor(4.9) = 4

#### abs函数（整数绝对值函数）

头文件：stdlib.h

原型：int abs(int x);

x：某个整数

返回值：返回|x|的结果

例：abs(-4) = 4

#### fabs函数（实数绝对值函数）

头文件：math.h

原型：double fabs(double x);

x：某个实数

返回值：返回|x|的结果

例：fabs(-4.5) = 4.5

#### log函数（以e为底对数函数）

头文件：math.h

原型：double log(double x);

x：某个实数

返回值：返回结果

例：log(9) = 2.107225...

以2为底对数函数：log(x) / log(2)

#### log10函数（以10为底对数函数）

头文件：math.h

原型：double log10(double x);

x：某个实数

返回值：返回结果

例：log10(1000) = 3

#### acos函数

头文件：math.h

原型：double acos(double x);

x：角度的弧度值

返回值：返回arccos(x)的结果

例：acos(-1) = 3.1415926...

> 请写一个程序，输入一个数字x，输出数字x的立方根

```c
#include <stdio.h>
#include <math.h>

int main() {
    double n, m;
    scanf("%lf", &n);
    m = sqrt(n, 1.0 / 3.0);
    printf("%lf\n", m);
    return 0;
}
```

> 请写一个程序，读入一个角度值，将角度值转化为弧度值

```c
#include <stdio.h>
#include <math.h>

#define PI acos(-1)

int main() {
    double n;
    scanf("%lf", &n);
    printf("%lf\n", PI / 180.0 * x);
    return 0;
}
```

#### 关系运算符

|     运算符     |        说明        |
| :------------: | :----------------: |
|       ==       |        等于        |
|       !=       |       不等于       |
|      <、>      |     小于、大于     |
| <=(=<)、>=(=>) | 小于等于、大于等于 |
|       !        |         非         |

#### if语句

if (表达式) {

​	代码段;

} else if (表达式) {

} else {

}

！表达式：常用条件表达式、普通表达式也可以

if(x == 5)：如果x=5执行代码段

if(x = 5)：括号内返回值为5，恒成立，故只执行if，不执行else或else if

> 程序读入一个正整数n，代表学生的成绩，根据分数输出分数档位
>
> n = 0, FOOLISH
>
> 0 < n < 60, FALL
>
> 60 <= n < 75, MEDIUM
>
> 75 <= n <= 100, GOOD

```c
#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) != EOF) { 
        if (!n) {
            printf("FOOLISH\n");
        } else if (n < 60) {
            printf("FAIL\n");
        } else if (n < 75) {
            printf("MEDIUN\n");
        } else if (n <= 100) {
            printf("GOOD\n");
        }
    }
    return 0;
}
```

#### switch语句

switch (a) {

​	case 1: 代码块1;

​	case 2: 代码块2;

​	......

​	default: 代码块n;

}

case为条件入口，程序进入case所对应的代码段，依次执行后续代码，直至遇到break，或者switch结构末尾。

> 请使用switch结构完成如下任务，程序读入一个整数n：
>
> 如果n = 1 ：输出one
>
> 如果n = 2 ：输出two
>
> 如果n = 3：输出three
>
> 否则输出error

```c
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    switch (n) {
        case 1 : printf("one\n"); break;
        case 2 : printf("two\n"); break;
        case 3 : printf("three\n"); break;
        default : printf("error\n"); break;
    }
    return 0;
}
```

#### while语句

while (表达式) {

​	代码块;

}

每当表达式为真时，代码就会被执行一次。

do {

} while ( );

每当代码执行1次，就会判断一次表达式是否为真。

> 请使用while循环实现程序，输出1—100

```c
#include<stdio.h>

int main() {
    int n = 1;
    while (n <= 100) {
        printf("%d\n", n);
        ++n;
    }
    return 0;
}
```

#### for语句

for (初始化; 循环条件; 执行后操作) {

​	代码块;

}

> 请使用for循环实现程序，输出1—100

```c
#include<stdio.h>

int main() {
    for (int i = 1; i <= 100; i++) {
        printf("%d\n", i);
    }
    return 0;
}
```

#### fread函数

头文件：stdio.h

原型：size_t fread ( void *buffer, size_t size, size_t count, FILE *stream) ;

buffer：用于接收数据的内存地址

size：要读的每个数据项的字节数，单位是字节

count：要读count个数据项，每个数据项是size个字节

stream：输入流

返回值：返回真实读取的项数，若大于count则意味着产生了错误。另外，产生错误后，文件位置指示器是无法确定的。若其他stream或buffer为空指针，或在unicode模式中写入的字节数为奇数，此函数设置errno为EINVAL以及返回0. 

> fast_read.cpp

```c++
#include <iostream>
using namespace std;

char ss[1<<17], *A = ss, *B = ss;
inline char gc() {
    return A == B && (B = (A = ss) + fread(ss, 1, 1 << 17, stdin), A == B) ? -1 : *A++;
}     //将ss地址赋给A，fread函数读入2的17次方个字符，存在ss中，返回读入的字符数，与A加和赋给B（B的位置是该字符串的最后一位）；逗号表达式返回值为A==B的返回值，如果AB相等则返回1，不等则返回0，此返回值与A==B逻辑与运算；返回1则则为真，说明A、B指向同一个位置，条件表达式返回-1；返回0则为假，条件表达式返回这个字符，并将指针A指向下一个位置

template<typename T> inline void sdf(T &x) {
    char c;
    T y = 1;
    while (c = gc(), (c < 48 || c > 57) && c != -1) {    //判断是否是数字，不是数字进去
        if (c == '-') y = -1;    //判断是否是负数
    }
    x = c ^ 48;   //48是'0'
    while (c = gc(), (c <= 57 && c >= 48)) {     //判断是否是数字，数字进去
        x = (x << 1) + (x << 3) + (c ^ 48);      //x = x * 10 + c
    }
    x *= y;
}

int main() {
    int n, a;
    sdf(n);
    for (int i = 0; i < n; i++) {
        sdf(a);
    }
    return 0;
}
```

#### 变量的地址

指针变量存放地址，指针变量也是变量有地址，指针类型：解析运算符和加一减一时占用多少字节，指针变量占８个字节（地址占８个字节）。

scanf("%d", &n)   //&n：传出参数

*p <=> a

p + 1 <=> &p[1]

p -> filed <=> (*p).filed <=> a.filed

#### 函数

int is_prime(int x) {

}

int：返回值

is_prime：函数名

int x：参数声明列表

函数的定义不能嵌套在另一个函数的定义之中：可以在函数内定义局部变量，但不能在函数内定义局部函数。

> 请实现一个程序，先读入两个整数k、b，输出y = k * x + b 直线方程中x = 1到x = 100 时的y的值

```c
#include <stdio.h>

int f(int k, int b, int x) {
    return k * x + b;
}
int main() {
    int k, b, x;
    scanf("%d%d", &k, &b);
    for (int i = 1;i <= 100; i++) {
        printf("f(%d) = %d\n", i, f(k, b, x));
    }
    return 0;
}
```

K&R风格函数定义        //慎用（g++编不过）

int is_prime(x)

int x;      //声明参数类型++

{

}ls

#### 函数指针

int (*add)(int, int);  //定义函数指针变量

typedef int (*add)(int, int);   //定义函数指针类型

获取函数地址的方法：函数名　　void function(int a) 地址：function

int func(int x);         // 声明一个函数 

int (*f) (int x);       // 声明一个函数指针 

f=func;        // 将func函数的首地址赋给指针f 

或者使用下面的方法将函数地址赋给函数指针：

f = &func;

#### 递归程序

程序调用自身

递归程序的组成部分：

1. 明确递归函数的语义
2. 边界条件处理
3. 针对问题的处理过程和递归过程
4. 结果返回

> 读入n，计算n的阶乘

```c
#include <stdio.h>

int factorial(int n) {     //明确语义信息
    if (n == 1) return 1;     //边界条件
    return factorial(n - 1) * n;    //递归过程、处理过程、返回值
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d! = %d\n", n, factorial(n));
    return 0;
}
```

#### 辗转相除

证明：

gcd(a, b) <=> gcd(b, a % b)

gcd(a, b) = c

a = x * c

b = y * c

gcd(x ,y) = 1

a % b = a - k * b = (x - k * y) * c

...

```c
int gcd(int a, int b){
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}
```

#### 变参函数



> function.c

```c
#include <stdio.h>
#define P(func) { \
    printf("%s = %d\n", #func, func); \
}

int is_prime(int x);
int max_int(int n, ...);

int main() {
    for (int i = 2; i <= 100; i++) {
        if (is_prime(i)) printf("%d\n", i);
    }
    P(max_int(3, 1, 2, 3));
    P(max_int(4, 1, 2, 3, 9));
    P(max_int(5, 1, 12, 3, 9, 10));
    return 0;
}
```

> unit.c

```c
#include <stdio.h>
#include <stdarg.h>
#include <inttypes.h>

int is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int max_int(int n, ...) {
    va_list arg;
    va_start(arg, n);
    int ans = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int temp = va_arg(arg, int);
        ans = temp > ans ? temp : ans;
    }
    return ans;
}
```

> 编译

```
gcc -c function     //生成对象文件
gcc -c unit
gcc function.o unit.o    //链接对象文件
```

#### 数组与字符串

#### 素数筛

1. 用prime[i]来标记i是否是合数
2. 标记为1的数字为合数，否则为素数
3. 第一次知道2是素数，则将2的倍数标记为1
4. 向后找到第一个没有被标记的数字i
5. 将i的倍数全部标记为合数
6. 重复4—6，直到标记完范围内的所有数字

```c
#include <stdio.h>
#include <inttyypes.h>

#define MAX 10000

int32_t prime[MAX + 5] = {0};

int main() {
    for(int32_t i = 2; i * i <= MAX; i++){
        if(!prime[i]){
            for(int32_t j = 2 * i; j <= MAX; j += i){
                prime[j] = 1;
            }
        }
    }
    int32_t n;
    while (scanf("%d", &n) != EOF) {
        printf("%s\n", prime[n] == 0 ? "yes" : "NO");
    }
    return 0;
}
```

#### 折半查找

mid = (min + max) / 2;

终止条件：min >= max

调整：

1. 如果arr[mid] < x, min = mid + 1；
2. 如果arr[mid] > x, max = mid - 1;
3. 如果arr[mid] == x, 找到结果

> 请完成如下函数，实现在一个数组arr中查找数字x是否存在，数组长度为n，如果找到了，返回x所在数组下标，否则返回-1
>
> int binary_search(int *arr, int x, int n);

```c
int binary_search(int *arr, int x, int n) {
    int head, tail, mid;
    head = 0, tail = n - 1;
    mid = (head + tail) >> 1;
    while (head <= tail) {
        if (num[mid] == x) {
            return mid;
        } else if (num[mid] < x) {
            head = x + 1;
        } else {
            tail = x - 1;
        }
        mid = (head + tail) >> 1;
    }
    return -1;
}
```

#### 结构体

可以命名也可以不命名

结构体类型

struct person {

​	char name[20];     //20字节

​	int age;       //4字节

​	char sex;        //4字节

​	fioat height;      //4字节

};

struct person A

struct person B

#### 共用体

共用一片存储空间，占用内存大小按最大算

> 使用共用体，实现ip转整数

```c++
#include <iostream>

union IP {
    struct {
        unsigned char arr[4];
    } ip;　　　　　　　　　　//匿名结构体类型定义ip变量
    unsigned int num;
};

int main() {
    int a, b, c ,d;
    IP ip;
    while (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != EOF) {
        ip.ip.arr[0] = a;
        ip.ip.arr[1] = b;
        ip.ip.arr[2] = c;
        ip.ip.arr[3] = d;
        printf("%d\n", ip.num);
    }
    return 0;
}
```

```c++
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#pragma pack(1)　　　//宏定义存储单元，完全没有空间浪费

struct person {
    char name[20];
    int age;
    char gender;
    float height;
};

struct test {
    char a;
    short b;   //只能放在2的倍数上
    int c;     //只能放在4的倍数上
    double d;
};


struct Number {
    int type;
    union {
        int num1;
        float num2;
    } N;
};

void print(Number *n) {
    switch (n -> type) {
        case 0: printf("%d\n", n -> N.num1); break;
        case 1: printf("%f\n", n -> N.num2); break;
    }
    return ;
}

void set(Number *n, int num) {
    n -> type = 0;
    n -> N.num1 = num;
} 

void set(Number *n, float num) {
    n -> type = 1;
    n -> N.num2 = num;
}

int main() {
    srand(time(0));
    struct test a;
    printf("sizeof(person) : %ld\n", sizeof(struct person));
    printf("%p %p %p %p\n", &a.a, &a.b, &a.c, &a.d);
    #define MAX_N 20
    Number arr[MAX_N];
    for (int i = 0; i < MAX_N; i++) {
        int op = rand() % 2;
        switch (op) {
            case 0: {
                int value = rand() % 100;
                set(arr + i, value);
            } break;
            case 1: {
                float value = (1.0 * (rand() % 10000) / 10000) * 100;
                set(arr + i, value);
            } break;
        }
    }
    for (int i = 0; i < MAX_N; i++) {
        print(arr + i);
    }
    arr[0].N.num2 = 1.0;
    printf("arr[0].N.num1 = %d\n", arr[0].N.num1);
    printf("arr[0].N.num1 = %x\n", arr[0].N.num1);
    return 0;
}
```

