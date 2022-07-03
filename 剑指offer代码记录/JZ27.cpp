#include "Solution3.h"
TreeNode* Solution3::mirror(TreeNode* Root) {
	if (Root == nullptr) return Root;
	else {
		TreeNode* temp = Root->left; //�򵥵Ľ����͵ݹ�
		Root->left = Root->right;
		Root->right = temp;
		mirror(Root->left);
		mirror(Root->right);
	}
	return Root;
}

TreeNode* Solution3::Mirror(TreeNode* pRoot) {
	//JZ27 �������ľ���
	/*���������Ķ�����������任ΪԴ�������ľ���
		���ݷ�Χ���������Ľڵ��� 0 \le n \le 10000��n��1000 �� ������ÿ���ڵ��ֵ 0\le val \le 10000��val��1000*/
	return mirror(pRoot); //�򵥵Ľ����͵ݹ�
}