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

class Solution3 {
public:
	ListNode_JZ25* Merge(ListNode_JZ25* pHead1, ListNode_JZ25* pHead2);//JZ25 合并两个排序的链表
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2); //JZ26 树的子结构
	bool recursion(TreeNode* root1, TreeNode* root2);//
};