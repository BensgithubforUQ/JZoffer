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



 struct ListNode_JZ18 { //JZ22同样用这个链表结点
 	int val;
 	struct ListNode_JZ18*next;
    ListNode_JZ18 (int x) : val(x), next(nullptr) {}
  };
 
 struct ListNode23 { //JZ24也用同种数据结构
     int val;
     struct ListNode23* next;
     ListNode23(int x) :
         val(x), next(NULL) {
     }
 };

//jz14 - jz24
class Solution2 {
public:
    int cutRope_supplementary(int n);//用于辅助，当n>3的情况。
    int cutRope(int n);//JZ14 剪绳子 贪心流（扩展思路）

    int cutRope_DP(int n);//dynamic programming 动态规划思路

    int  NumberOf1(int n);//JZ15 二进制中1的个数
    int  NumberOf1_DP(long long int n, long long int* PowerOfTwo);//JZ15 二进制中1的个数

    double Power(double base, int exponent);//JZ16 数值的整数次方
    double Power_DP(double base, int exponent);//JZ16 数值的整数次方 快速幂，动态规划


    vector<int> printNumbers(int n);//JZ17 打印从1到最大的n位数,过于简单

    ListNode_JZ18* deleteNode(ListNode_JZ18* head, int val); //JZ18 删除链表的节点


    bool match(string str, string pattern);//JZ19 正则表达式匹配 极难 多复习
    bool match1(string str, string pattern);
    bool match_core(string str, string pattern);

    bool isNumeric(string str);//JZ20 表示数值的字符串 较难

    vector<int> reOrderArray(vector<int>& array); //JZ21 调整数组顺序使奇数位于偶数前面(一)

    ListNode_JZ18* FindKthToTail(ListNode_JZ18* pHead, int k); //JZ22 链表中倒数最后k个结点

    ListNode23* EntryNodeOfLoop(ListNode23* pHead);
    ListNode23* EntryNodeOfLoop_hash(ListNode23* pHead);

    ListNode23* ReverseList(ListNode23* pHead)//JZ24 反转链表

};