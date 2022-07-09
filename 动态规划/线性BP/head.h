#pragma once
#include<iostream>
#include<vector>
//#include<bits/stdc++.h> //万能头
using namespace std;

void fib(); //斐波拉契数列

int dp_jumpFloor(int n); //青蛙跳台阶
void jumpFloor(); 

void jumpFloorExtra(); //进阶版跳台阶，但是更简单？

void jumpFloorCost(); //带键值的跳台阶

void binarySearchTreeCount();// 有n个结点的二叉搜索树有多少种形态

void maxSubArray(); //连续子数组最大和,非动态规划算法，但是思路差不多，算是双指针？
void maxSubArray_dp(); //连续子数组最大和，动态规划算法。

void maxlength_subArrayPostive_multi();//变种，这道题求连续乘积为整数的最长子串

void circleArrayMaxSum();//变种，环形连续数组的子数组最大和。

void matrixMaxSum();// 变种，子矩阵的最大和，和数组的类似，只不过这个是矩阵和的比较，数组是比较单个值。

void minPathMatrix();//变种，矩阵路径最小值

int calculateHP(int a,int b);//变种，龙与地下地下城的辅助函数
void minHP();//龙与地下城问题，需要多少基础血量才能确保有可能通关。
//本质是矩阵路径最小和的变种


void horseNextPos(int x, int y, vector<vector<long long>>& arr); //棋盘拱卒
long long countPath(long long left, long long up); //计算下个点有多少种路径
void soldierCrossRivier(); //主函数


//超重点知识，
void maxSubArrayAscend(); //最长上升子序列(一)
//整个数组，记录原序列对应点位之前，有多少小于本点位的数字，这是原意，但是要dp
//dp用一个双层循环，第一个循环是i = 0到n-1，第二个循环遍历0到i-1的部分
//比较arr[1]和之前的点位的值的大小，如果大于之前的点位，则取dp数组中的值 + 1,意为这个点是可以接在之前的那个点伤
//然后取max值，dp[i]一定是max+1


//然后是进阶版
void antiMissile_dp(); //这个题建议记下来。。。。有点东西的
//第一个问题是非严格上升子序列长度，第二问问的是严格上升自序列长度。
//拦截导弹问题
//这个问题分两个部分，第一个部分是，最长上升子序列，但是这个问题里面可以是相等的，不是严格的上升子序列
//第二个部分，最少有几个上升子序列、
//Dilworth定理:
//最少的下降序列个数就等于整个序列最长上升子序列的长度
//该定理断言：对于任意有限偏序集，其最大反链中元素的数目必等于最小链划分中链的数目。
//此定理的对偶形式亦真，它断言：对于任意有限偏序集，其最长链中元素的数目必等于其最小反链划分中反链的数目
//链: D 中的一个子集 C 满足 C 是全序集 及C中所有元素都可以比较大小
//
//反链 : D 中的一个子集 B 满足 B 中任意非空子集都不是全序集 即所有元素之间都不可以比较大小
//
//链覆盖 : 若干个链的并集为 D ，且两两之间交集为 ∅
//
//反链覆盖 : 若干个反链的并集为 D ，且两两之间交集为∅
//
//最长链 : 所有链中元素个数最多的(可以有多个最长链)
//
//最长反链 : 所有反链中元素个数最多的(可以有多个最长反链
//
//	偏序集高度 : 最长链的元素个数
//	偏序集宽度 : 最长反链中的元素个数
//
//	最小链覆盖（使链最少） = 最长反链长度 = 偏序集宽度
//	最小反链覆盖 = 最长链长度 = 偏序集深度


void smallBigSmall(); //最大升序子序列问题的延伸
//这个题主要就是在问，左侧最大升序，右侧最大降序
//然后求和最大，然后n - mx
//注意点就是，全是升序或者全是降序也是峰形，然后就是辅助数组的值记得取对了，这个要求比较精确。

void envelopes();//没什么好说的，正常的dp