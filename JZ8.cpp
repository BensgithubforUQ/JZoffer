#include "Solution.h"

vector<TreeLinkNode*> nodes;

void InOrder(TreeLinkNode* root) {
	if (root == NULL) return;
	InOrder(root->left);//�ҵ�����������ӽڵ�
	nodes.push_back(root);//���ӽڵ���뵽�������������
	
	InOrder(root->right);//Ȼ��ʼ���ҽ��
}

TreeLinkNode* Solution::GetNext(TreeLinkNode* pNode) {
	//�����Ŀ���
	//������������Ȳ������㣬���û�У����ҽ�㣬���û�У�ջ����ջ
	//�����һ���������û�����ң�����ջ���Ľ��

	//{8, 6, 10, 5, 7, 9, 11}����, 8 ����9
	//{5��6��7,8,9��10,11}����
	//8
	//6     10
	//5 7  9 11
	//������Ϊ8ʱ������������������ҽ�㣬Ȼ�����ҽ��֮��һ·�������ң��Ҳ��������ң������9
	//{8,6,10,5,7,9,11},6
	//����Ϊ6��ʱ������һ�������������ҽ�㣬6���ҽڵ㣬��7
	//{1,2,#,#,3,#,4},4
	//   1
	//2    #
	//# 3 # 4 ������Ϊ4��ʱ��û�����ҽ�㣬�򷵻ظ���㡣
	//{5},5 ָ��null
	TreeLinkNode* root = pNode;//��ʼ�����ڵ�
	while (root->next) {
		root = root->next;//ֻҪ�и��ڵ㣬�ͼ����Ҹ��ڵ�
	}
	//Ȼ������������
	InOrder(root);
	int n = nodes.size();//ȡ��ǰ���������С

	for (int i = 0; i < n - 1; i++) {
		TreeLinkNode* cur = nodes[i];
		if (pNode->val == cur->val) {
			
				return nodes[i + 1];//������һ�����

		}
	}
	return NULL;

}