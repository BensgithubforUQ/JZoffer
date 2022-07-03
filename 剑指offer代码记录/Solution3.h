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
	ListNode_JZ25* Merge(ListNode_JZ25* pHead1, ListNode_JZ25* pHead2);//JZ25 �ϲ��������������
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2); //JZ26 �����ӽṹ
	bool recursion(TreeNode* root1, TreeNode* root2);//

	TreeNode* Mirror(TreeNode* pRoot);//JZ27����������
	TreeNode* mirror(TreeNode* Root);

	bool isSymmetrical(TreeNode* pRoot);//JZ28 �ԳƵĶ�����
	bool compareTree(TreeNode* root1, TreeNode* root2);

	vector<int> printMatrix(vector<vector<int> > matrix);//JZ29 ˳ʱ���ӡ����
	void readMatrix(vector<vector<int> >& matrix, vector<int>& res);

	stack<int> s1;
	stack <int> s2;
	void push(int value);//JZ30 ����min������ջ
	void pop();
	int top();
	int min();//JZ30 ����min������ջ������ջ

	bool IsPopOrder(vector<int> pushV, vector<int> popV);//JZ31 ջ��ѹ�롢�������У�����ջ

	vector<int> PrintFromTopToBottom(TreeNode* root);//JZ32 �������´�ӡ���������������Ĳ�����������С�
	bool VerifySquenceOfBST(vector<int> sequence); //JZ33 �����������ĺ����������
	bool recursioVerify(vector<int> sequence, int begin, int end);

	vector<vector<int>> FindPath(TreeNode* root, int expectNumber);//JZ34 �������к�Ϊĳһֵ��·��(��)
	void dfs(TreeNode* root, int number, vector<vector<int>>& ret, vector<int>& path);

	RandomListNode* Clone(RandomListNode* pHead); //JZ35 ��������ĸ���
};