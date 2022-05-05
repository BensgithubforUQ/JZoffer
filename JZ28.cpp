#include "Solution3.h"

bool Solution3::compareTree(TreeNode* root1, TreeNode* root2) {
	if (root1 == nullptr && root2 == nullptr) return true; //�鵽Ҷ�ӽ����
	if (root1 == nullptr || root2 == nullptr || root1->val != root2->val) return false;
	//���Գ�//�������ͬ�������ҽ��
	return compareTree(root1->left, root2->right) && compareTree(root1->right, root2->left);
}

bool Solution3::isSymmetrical(TreeNode* pRoot) {
	//JZ28 �ԳƵĶ�����
	//����һ�ö��������ж����Ƿ�������ľ��񣨼����Ƿ�Գƣ�
	return compareTree(pRoot, pRoot);
}