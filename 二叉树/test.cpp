#include <iostream>
#include <vector>
#include <map>
using namespace std;

//�ṹ���Сʵ��
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
//��1�������������ڵĳ�Ա�����ڴ棬����̬���ݳ�Ա�����ó�Ա�����ܹ����ڴ棬���Բ�������Щ���͵ĳ�Ա��
//��2���������ڲ������Ŵ��й��캯�����������������Ʋ������ȵ��࣬��Ϊ��Щ��������ڴ�ʱ���������޷���֤��Щ���󲻱��ƻ���
int main() {
    printf("%d\n", sizeof(A));
    printf("%d\n", sizeof(A[0]));
    printf("%d\n", sizeof(A[1]));
    printf("%d\n", sizeof(A[0].e));
    printf("%d\n", sizeof(A[0].f));

    printf("%d\n", sizeof(u));
    return 0;
}