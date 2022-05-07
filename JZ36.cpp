#include "Solution4.h"
#include <set>

void dfs(TreeNode* node, vector<TreeNode* > &v) {
	if (node == nullptr) return;
	int value = node->val;
	v.push_back(node);
	dfs(node->left, v);
	dfs(node->right, v);
}

TreeNode* Solution4::Convert(TreeNode* pRootOfTree) {//JZ36 二叉搜索树与双向链表
	//二叉搜索树，就是根节点大于左边，小于右边。
    if (pRootOfTree == nullptr) return pRootOfTree;
    vector<TreeNode* > v; //整个数组记录下顺序就完了
    dfs(pRootOfTree, v);
    int size = v.size();

    for (int i = 0; i < size; i++) { //排个序
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
    for (int i = 0; i < size - 1; i++) { //按照序列连接下
        v[i]->right = v[i + 1];
        v[i + 1]->left = v[i];
    }
    return v[0];
}

//中序遍历，就是先找最左，找完最左然后找父节点的右边，继续找最左。