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
struct TreeNode {//JZ7 重建二叉树
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param numbers int整型vector
     * @return int整型
     */
    int duplicate(vector<int>& numbers);//JZ3 数组中重复的数字
    int duplicate2(vector<int>& numbers);//JZ3 数组中重复的数字

    bool Find(int target, vector<vector<int> > array);//JZ4 二维数组中的查找，这种方法比较推荐
    bool Find1(int target, vector<vector<int> > array);//JZ4 二维数组中的查找,这种方法是暴力方法，不推荐 set知识点

    string replaceSpace(string s);//JZ5 替换空格 string知识点

    vector<int> printListFromTailToHead(ListNode* head);//JZ6 从尾到头打印链表

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin); //JZ7 重建二叉树

    TreeLinkNode* GetNext(TreeLinkNode* pNode);//JZ7 二叉树的下一个结点

    void push(int node);//JZ9 用三个栈实现队列
    int pop();//JZ9 用三个栈实现队列

    void push1(int node);//JZ9 用两个栈实现队列
    int pop1();//JZ9 用两个栈实现队列

    int Fibonacci(int n);//JZ10 斐波那契数列 递归
    int Fibonacci1(int n);//JZ10 斐波那契数列 动态规划

private:
    stack<int> stack1; //JZ9 用两个栈实现队列
    stack<int> stack2;// JZ9 用两个栈实现队列
};