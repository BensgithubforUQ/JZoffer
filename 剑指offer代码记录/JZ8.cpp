#include "Solution.h"

vector<TreeLinkNode*> nodes;

void InOrder(TreeLinkNode* root) {
	if (root == NULL) return;
	InOrder(root->left);//找到最左最深的子节点
	nodes.push_back(root);//把子节点加入到中序遍历数组中
	
	InOrder(root->right);//然后开始找右结点
}

TreeLinkNode* Solution::GetNext(TreeLinkNode* pNode) {
	//是树的课题
	//中序遍历，是先查最左结点，如果没有，查右结点，如果没有，栈顶出栈
	//因此下一个数，如果没有左右，就是栈顶的结点

	//{8, 6, 10, 5, 7, 9, 11}正序, 8 返回9
	//{5，6，7,8,9，10,11}中序
	//8
	//6     10
	//5 7  9 11
	//当输入为8时，根据中序遍历，找右结点，然后找右结点之后一路向左结点找，找不到再找右，因此是9
	//{8,6,10,5,7,9,11},6
	//输入为6的时候，找下一个数，则是找右结点，6有右节点，是7
	//{1,2,#,#,3,#,4},4
	//   1
	//2    #
	//# 3 # 4 当输入为4的时候，没有左右结点，则返回根结点。
	//{5},5 指向null
	TreeLinkNode* root = pNode;//初始化根节点
	while (root->next) {
		root = root->next;//只要有父节点，就继续找父节点
	}
	//然后就是中序遍历
	InOrder(root);
	int n = nodes.size();//取当前中序遍历大小

	for (int i = 0; i < n - 1; i++) {
		TreeLinkNode* cur = nodes[i];
		if (pNode->val == cur->val) {
			
				return nodes[i + 1];//返回下一个结点

		}
	}
	return NULL;

}