#include "Solution3.h"


vector<int> Solution3::PrintFromTopToBottom(TreeNode* root) {//二叉树的层序遍历，队列。
	//不分行从上往下打印出二叉树的每个节点，同层节点从左至右打印。例如输入{ 8,6,10,#,#,2,1 }，
	//	如以下图中的示例二叉树，则依次打印8, 6, 10, 2, 1(空节点不打印，跳过)，请你将打印的结果存放到一个数组里面，返回。
	queue<TreeNode*> q;
	vector<int> res;
	if (root == nullptr) return res;
	q.push(root);
	TreeNode* currentNode;
	while (!q.empty()) {
		currentNode = q.front();
		q.pop();
		res.push_back(currentNode->val);
		//如果左右孩子结点都存在
		if (currentNode->left) q.push(currentNode->left); //双端队列，先进先出，因此这里进的，得等到前面的出完了才会出
		if (currentNode->right) q.push(currentNode->right); //队列，左右结点加到队列后面，因此左节点在出的时候，就会把左节点的左右节点都加进去
		//在接着出右节点的时候，就会把右节点的左右结点都加进去。因此就是层序遍历了。
	}
	return res;
}