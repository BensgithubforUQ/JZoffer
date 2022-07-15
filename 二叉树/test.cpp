#include <iostream>
#include <vector>
#include <map>
using namespace std;

//结构体大小实验
#pragma pack(4)
static int num = 2;
static int val = 2;
struct test1 {
    int a; //4
    char b[5]; //4 + 1+ 3
    int* c; //4
    char d;//1+3
    vector<int>e = {3};
    map<char, int>f;
}A[2];

union test2 {
    int a;
    char b;
    float c;
    double d;
}u;
//（1）由于联合体内的成员共享内存，而静态数据成员或引用成员均不能共享内存，所以不能用这些类型的成员。
//（2）联合体内不允许存放带有构造函数，析构函数，复制操作符等的类，因为这些类对象共享内存时，编译器无法保证这些对象不被破坏。
int main() {
    printf("%d\n", sizeof(A));
    printf("%d\n", sizeof(A[0]));
    printf("%d\n", sizeof(A[1]));
    printf("%d\n", sizeof(A[0].e));
    printf("%d\n", sizeof(A[0].f));

    printf("%d\n", sizeof(u));
    return 0;
}