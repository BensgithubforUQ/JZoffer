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