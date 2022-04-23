#include "Solution.h"

TreeNode* Solution::reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	//{1,2,4,7,3,5,6,8}
	//{4,7,2,1,5,3,8,6}
	// ����
	// {2��4��7}��{3��5��6��8} ���ѳ�������ǰ��������еĵ�һ��Ԫ��Ϊ�����ĸ�
	//{4��7��2}��{5��3��8��6}
	//�ٷ���
	//{4,7},
	// {4,7}
	//{5}.{6,8}
	//{5},{8,6}
	//�ٷ���
	//{8}
	//{8}
	if (pre.empty()||vin.empty()) {
		return NULL;
	}
	int size = pre.size();
	TreeNode* root = new TreeNode(pre[0]); //��ȷ�ϸ��ڵ�
	for (int i = 0; i < size; i++) {
		if (pre[0] == vin[i]) {//׼���ָ�
			//���������ǰ�����
			vector<int> leftPre(pre.begin() + 1, pre.begin() + i + 1);
			//�ұ�������ǰ�����
			vector<int> rightPre(pre.begin() + i + 1, pre.end());

			//����������������
			vector<int> leftVin(vin.begin(), vin.begin() + i);// vin.begin() + i �Ǹ��ڵ�λ��
			//�ұ��������������
			vector<int> rightVin(vin.begin() + i + 1, vin.end());

			//�����ݹ�
			root->left = reConstructBinaryTree(leftPre, leftVin);
			root->right = reConstructBinaryTree(rightPre, rightVin);
			break;
		}
	}
	return root;
}
