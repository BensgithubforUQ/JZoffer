#include "Solution.h"

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	//{1,2,4,7,3,5,6,8}
	//{4,7,2,1,5,3,8,6}
	// 分裂
	// {2，4，7}，{3，5，6，8} 分裂成子树的前序遍历序列的第一个元素为子树的根
	//{4，7，2}，{5，3，8，6}
	//再分裂
	//{4,7},
	// {4,7}
	//{5}.{6,8}
	//{5},{8,6}
	//再分裂
	//{8}
	//{8}
	if (pre.empty()||vin.empty()) {
		return NULL;
	}
	int size = pre.size();
	TreeNode* root = new TreeNode(pre[0]); //先确认根节点
	for (int i = 0; i < size; i++) {
		if (pre[0] == vin[i]) {//准备分割
			//左边子树，前序遍历
			vector<int> leftPre(pre.begin() + 1, pre.begin() + i + 1);
			//右边子树，前序遍历
			vector<int> rightPre(pre.begin() + i + 1, pre.end());

			//左边子树，中序遍历
			vector<int> leftVin(vin.begin(), vin.begin() + i);// vin.begin() + i 是根节点位置
			//右边子树，中序遍历
			vector<int> rightVin(vin.begin() + i + 1, vin.end());

			//函数递归
			root->left = reConstructBinaryTree(leftPre, leftVin);
			root->right = reConstructBinaryTree(rightPre, rightVin);
			break;
		}
	}
	return root;
}
