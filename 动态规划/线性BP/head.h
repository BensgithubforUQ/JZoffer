#pragma once
#include<iostream>
#include<vector>
//#include<bits/stdc++.h> //����ͷ
using namespace std;

void fib(); //쳲���������

int dp_jumpFloor(int n); //������̨��
void jumpFloor(); 

void jumpFloorExtra(); //���װ���̨�ף����Ǹ��򵥣�

void jumpFloorCost(); //����ֵ����̨��

void binarySearchTreeCount();// ��n�����Ķ����������ж�������̬

void maxSubArray(); //��������������,�Ƕ�̬�滮�㷨������˼·��࣬����˫ָ�룿
void maxSubArray_dp(); //�������������ͣ���̬�滮�㷨��

void maxlength_subArrayPostive_multi();//���֣�������������˻�Ϊ��������Ӵ�

void circleArrayMaxSum();//���֣�����������������������͡�

void matrixMaxSum();// ���֣��Ӿ�������ͣ�����������ƣ�ֻ��������Ǿ���͵ıȽϣ������ǱȽϵ���ֵ��

void minPathMatrix();//���֣�����·����Сֵ

int calculateHP(int a,int b);//���֣�������µ��³ǵĸ�������
void minHP();//������³����⣬��Ҫ���ٻ���Ѫ������ȷ���п���ͨ�ء�
//�����Ǿ���·����С�͵ı���


void horseNextPos(int x, int y, vector<vector<long long>>& arr); //���̹���
long long countPath(long long left, long long up); //�����¸����ж�����·��
void soldierCrossRivier(); //������