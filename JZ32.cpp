#include "Solution3.h"


vector<int> Solution3::PrintFromTopToBottom(TreeNode* root) {//�������Ĳ�����������С�
	//�����д������´�ӡ����������ÿ���ڵ㣬ͬ��ڵ�������Ҵ�ӡ����������{ 8,6,10,#,#,2,1 }��
	//	������ͼ�е�ʾ���������������δ�ӡ8, 6, 10, 2, 1(�սڵ㲻��ӡ������)�����㽫��ӡ�Ľ����ŵ�һ���������棬���ء�
	queue<TreeNode*> q;
	vector<int> res;
	if (root == nullptr) return res;
	q.push(root);
	TreeNode* currentNode;
	while (!q.empty()) {
		currentNode = q.front();
		q.pop();
		res.push_back(currentNode->val);
		//������Һ��ӽ�㶼����
		if (currentNode->left) q.push(currentNode->left); //˫�˶��У��Ƚ��ȳ������������ģ��õȵ�ǰ��ĳ����˲Ż��
		if (currentNode->right) q.push(currentNode->right); //���У����ҽ��ӵ����к��棬�����ڵ��ڳ���ʱ�򣬾ͻ����ڵ�����ҽڵ㶼�ӽ�ȥ
		//�ڽ��ų��ҽڵ��ʱ�򣬾ͻ���ҽڵ�����ҽ�㶼�ӽ�ȥ����˾��ǲ�������ˡ�
	}
	return res;
}