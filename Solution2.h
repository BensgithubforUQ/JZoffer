#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;



 struct ListNode_JZ18 {
 	int val;
 	struct ListNode_JZ18*next;
    ListNode_JZ18 (int x) : val(x), next(nullptr) {}
  };
 

//jz14 - jz24
class Solution2 {
public:
    int cutRope_supplementary(int n);//���ڸ�������n>3�������
    int cutRope(int n);//JZ14 ������ ̰��������չ˼·��

    int cutRope_DP(int n);//dynamic programming ��̬�滮˼·

    int  NumberOf1(int n);//JZ15 ��������1�ĸ���
    int  NumberOf1_DP(long long int n, long long int* PowerOfTwo);//JZ15 ��������1�ĸ���

    double Power(double base, int exponent);//JZ16 ��ֵ�������η�
    double Power_DP(double base, int exponent);//JZ16 ��ֵ�������η� �����ݣ���̬�滮


    vector<int> printNumbers(int n);//JZ17 ��ӡ��1������nλ��,���ڼ�

    ListNode_JZ18* deleteNode(ListNode_JZ18* head, int val); //JZ18 ɾ������Ľڵ�


    bool match(string str, string pattern);//JZ19 ������ʽƥ��
    bool match1(string str, string pattern);
    bool match_core(string str, string pattern);

    bool isNumeric(string str);//JZ20 ��ʾ��ֵ���ַ���
};