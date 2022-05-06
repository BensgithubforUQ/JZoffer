#include "Solution3.h"

vector<vector<int>> Solution3::FindPath(TreeNode* root, int expectNumber) {
	//JZ34 二叉树中和为某一值的路径(二)
	/*输入一颗二叉树的根节点root和一个整数expectNumber，找出二叉树中结点值的和为expectNumber的所有路径。
		1.该题路径定义为从树的根结点开始往下一直到叶子结点所经过的结点
		2.叶子节点是指没有子节点的节点
		3.路径只能从父节点到子节点，不能从子节点到父节点
		4.总节点数目为n

		如二叉树root为{ 10,5,12,4,7 }, expectNumber为22*/
	//   10
	// 5   12
	//4 7 
	vector<vector<int>> ret;
	vector<int> path;
	dfs(root, expectNumber,ret,path);
	return ret;
}

void Solution3::dfs(TreeNode* root, int number, vector<vector<int>>& ret, vector<int> &path) {
	// 处理树为空
	if (root == NULL) return;
	// 路径更新
	path.push_back(root->val);
	// number更新
	number -= root->val;
	// 如果递归当前节点为叶子节点且该条路径的值已经达到了expectNumber，则更新ret
	if (root->left == NULL && root->right == NULL && number == 0) {
		ret.push_back(path);
	}
	// 左右子树递归
	dfs(root->left, number,ret,path);
	dfs(root->right, number, ret, path);
	path.pop_back();//当执行完和当前结点有关的路径处理之后，就pop，这样就保证了path的回溯
}