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

struct ListNode_JZ25 {
	int val;
	struct ListNode_JZ25* next;
	ListNode_JZ25(int x) :
		val(x), next(NULL) {
	}
};

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

struct RandomListNode {
	int label;
	struct RandomListNode* next, * random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
//jz25 - jz35
class Solution3 {
public:
	ListNode_JZ25* Merge(ListNode_JZ25* pHead1, ListNode_JZ25* pHead2);//JZ25 合并两个排序的链表
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2); //JZ26 树的子结构
	bool recursion(TreeNode* root1, TreeNode* root2);//

	TreeNode* Mirror(TreeNode* pRoot);//JZ27二叉树镜像
	TreeNode* mirror(TreeNode* Root);

	bool isSymmetrical(TreeNode* pRoot);//JZ28 对称的二叉树
	bool compareTree(TreeNode* root1, TreeNode* root2);

	vector<int> printMatrix(vector<vector<int> > matrix);//JZ29 顺时针打印矩阵
	void readMatrix(vector<vector<int> >& matrix, vector<int>& res);

	stack<int> s1;
	stack <int> s2;
	void push(int value);//JZ30 包含min函数的栈
	void pop();
	int top();
	int min();//JZ30 包含min函数的栈，辅助栈

	bool IsPopOrder(vector<int> pushV, vector<int> popV);//JZ31 栈的压入、弹出序列，辅助栈

	vector<int> PrintFromTopToBottom(TreeNode* root);//JZ32 从上往下打印二叉树，二叉树的层序遍历，队列。
	bool VerifySquenceOfBST(vector<int> sequence); //JZ33 二叉搜索树的后序遍历序列
	bool recursioVerify(vector<int> sequence, int begin, int end);

	vector<vector<int>> FindPath(TreeNode* root, int expectNumber);//JZ34 二叉树中和为某一值的路径(二)
	void dfs(TreeNode* root, int number, vector<vector<int>>& ret, vector<int>& path);

	RandomListNode* Clone(RandomListNode* pHead); //JZ35 复杂链表的复制
};