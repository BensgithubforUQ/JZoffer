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

//jz14 - jz24
class Solution2 {
public:
    int cutRope_supplementary(int n);//用于辅助，当n>3的情况。
    int cutRope(int n);//JZ14 剪绳子 贪心流（扩展思路）

    int cutRope_DP(int n);//dynamic programming 动态规划思路

    int  NumberOf1(int n);//JZ15 二进制中1的个数
    int  NumberOf1_DP(long long int n, long long int* PowerOfTwo);//JZ15 二进制中1的个数


};