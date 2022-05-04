#include "Solution3.h"

bool Solution3::compareTree(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr && root2 == nullptr) return true; //查到叶子结点了
	if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) return false;
	//不对称//根结点相同，查左右结点
	return compareTree(root1->left, root2->right) && compareTree(root1->right, root2->left);
}

bool Solution3::isSymmetrical(TreeNode* pRoot) {
	//JZ28 对称的二叉树
	//给定一棵二叉树，判断其是否是自身的镜像（即：是否对称）
	return compareTree(pRoot, pRoot);
}