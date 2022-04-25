#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <set>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode {//JZ6
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {

    }
};

struct TreeLinkNode {//JZ8
    int val;
    struct TreeLinkNode* left;
    struct TreeLinkNode* right;
    struct TreeLinkNode* next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};


// Definition for binary tree
struct TreeNode {//JZ7 �ؽ�������
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param numbers int����vector
     * @return int����
     */
    int duplicate(vector<int>& numbers);//JZ3 �������ظ�������
    int duplicate2(vector<int>& numbers);//JZ3 �������ظ�������

    bool Find(int target, vector<vector<int> > array);//JZ4 ��ά�����еĲ��ң����ַ����Ƚ��Ƽ�
    bool Find1(int target, vector<vector<int> > array);//JZ4 ��ά�����еĲ���,���ַ����Ǳ������������Ƽ� set֪ʶ��

    string replaceSpace(string s);//JZ5 �滻�ո� string֪ʶ��

    vector<int> printListFromTailToHead(ListNode* head);//JZ6 ��β��ͷ��ӡ����

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin); //JZ7 �ؽ�������

    TreeLinkNode* GetNext(TreeLinkNode* pNode);//JZ7 ����������һ�����

    void push(int node);//JZ9 ������ջʵ�ֶ���
    int pop();//JZ9 ������ջʵ�ֶ���

    void push1(int node);//JZ9 ������ջʵ�ֶ���
    int pop1();//JZ9 ������ջʵ�ֶ���

    int Fibonacci(int n);//JZ10 쳲��������� �ݹ�
    int Fibonacci1(int n);//JZ10 쳲��������� ��̬�滮

private:
    stack<int> stack1; //JZ9 ������ջʵ�ֶ���
    stack<int> stack2;// JZ9 ������ջʵ�ֶ���
};