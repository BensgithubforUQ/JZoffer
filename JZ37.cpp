#include "Solution4.h"

//请实现两个函数，分别用来序列化和反序列化二叉树，不对序列化之后的字符串进行约束，
//但要求能够根据序列化之后的字符串重新构造出一棵与原二叉树相同的树。
//
//二叉树的序列化(Serialize)是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
//从而使得内存中建立起来的二叉树可以持久保存。序列化可以基于先序、中序、后序、层序的二叉树等遍历方式来进行修改，
//序列化的结果是一个字符串，序列化时通过 某种符号表示空节点（#）
//
//二叉树的反序列化(Deserialize)是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
//
//例如，可以根据层序遍历的方案序列化，如下图 :
//节点数 n \le 100n≤100，树上每个节点的值满足 0 \le val \le 1500≤val≤150

char* Solution4::Serialize(TreeNode* root) {
	int num = dfs(root);
	int size = 1; //数组长度
	int temp = 1;
	for (int i = 0; i < num-1; i++) {
		temp = temp * 2;
		size += temp;
	}
	int* array = new int[size]; //数组

}
TreeNode* Solution4::Deserialize(char* str) {

}

int dfs(TreeNode* root) { //查询一波深度
	if (root == nullptr) return 0;
	int num = 1;
	if (root->left != nullptr || root->right != nullptr) {
		int l_num = dfs(root->left);
		int r_num = dfs(root->right);
			num += (l_num > r_num) ? l_num  :r_num;
	}
	return num;
}