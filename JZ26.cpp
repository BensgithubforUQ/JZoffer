#include "Solution3.h"


bool Solution3::recursion(TreeNode* root1, TreeNode* root2) {
	if (root2 == nullptr) return true; //root遍历完了，到了叶子结点
	if (root1 == nullptr) return false;//root2没有遍历完，但是root1遍历完了
	if (root1->val != root2->val) return false; //值不相等
	return recursion(root1->left, root2->left) && recursion(root1->right, root2->right); //如果值相等，且没到叶结点，则继续查左右节点。
}

bool Solution3::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {//JZ26 树的子结构
	/*输入两棵二叉树A，B，判断B是不是A的子结构。（我们约定空树不是任意一个树的子结构）
		假如给定A为{ 8,8,7,9,2,#,#,#,#,4,7 }，B为{ 8,9,2 }，2个树的结构如下，可以看出B是A的子结构*/
	//if (pRoot2 == NULL) return false;
	bool result = false;
	if (pRoot1 != nullptr && pRoot2 != nullptr) {
		if (pRoot1->val == pRoot2->val) {
			result = recursion(pRoot1, pRoot2); //如果找到了结点值和root2根节点值一致的结点，就可以尝试进行匹配
		}
		if (!result) result =  HasSubtree(pRoot1->left,pRoot2); //如果没有，就继续找左节点
		if (!result) result =  HasSubtree(pRoot1->right, pRoot2);//如果左节点没有，就继续从右结点找
	}
	return result;
}