#include "Solution4.h"
#include <set>

void dfs(TreeNode* node, vector<TreeNode* > &v) {
	if (node == nullptr) return;
	int value = node->val;
	v.push_back(node);
	dfs(node->left, v);
	dfs(node->right, v);
}

TreeNode* Solution4::Convert(TreeNode* pRootOfTree) {//JZ36 ������������˫������
	//���������������Ǹ��ڵ������ߣ�С���ұߡ�
    if (pRootOfTree == nullptr) return pRootOfTree;
    vector<TreeNode* > v; //���������¼��˳�������
    dfs(pRootOfTree, v);
    int size = v.size();

    for (int i = 0; i < size; i++) { //�Ÿ���
        int min = v[i]->val;
        for (int j = i + 1; j < size; j++) {
            if (min > v[j]->val) {
                min = v[j]->val;
                TreeNode* temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    for (int i = 0; i < size - 1; i++) { //��������������
        v[i]->right = v[i + 1];
        v[i + 1]->left = v[i];
    }
    return v[0];
}

//�����������������������������Ȼ���Ҹ��ڵ���ұߣ�����������