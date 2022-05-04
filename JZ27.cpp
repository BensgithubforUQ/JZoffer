#include "Solution3.h"
TreeNode* Solution3::mirror(TreeNode* Root) {
	if (Root == nullptr) return Root;
	else {
		TreeNode* temp = Root->left; //简单的交换和递归
		Root->left = Root->right;
		Root->right = temp;
		mirror(Root->left);
		mirror(Root->right);
	}
	return Root;
}

TreeNode* Solution3::Mirror(TreeNode* pRoot) {
	//JZ27 二叉树的镜像
	/*操作给定的二叉树，将其变换为源二叉树的镜像。
		数据范围：二叉树的节点数 0 \le n \le 10000≤n≤1000 ， 二叉树每个节点的值 0\le val \le 10000≤val≤1000*/
	return mirror(pRoot); //简单的交换和递归
}