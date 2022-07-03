#include "Solution4.h"
#include <set>

void Solution4::dfs(TreeNode1* node, vector<TreeNode1* > &v) {
	if (node == nullptr) return;
	int value = node->val;
	v.push_back(node);
	dfs(node->left, v);
	dfs(node->right, v);
}

TreeNode1* Solution4::Convert(TreeNode1* pRootOfTree) {//JZ36 ������������˫������
	//���������������Ǹ��ڵ������ߣ�С���ұߡ�
    if (pRootOfTree == nullptr) return pRootOfTree;
    vector<TreeNode1* > v; //���������¼��˳�������
    dfs(pRootOfTree, v);
    int size = v.size();

    for (int i = 0; i < size; i++) { //�Ÿ���
        int min = v[i]->val;
        for (int j = i + 1; j < size; j++) {
            if (min > v[j]->val) {
                min = v[j]->val;
                TreeNode1* temp = v[i];
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