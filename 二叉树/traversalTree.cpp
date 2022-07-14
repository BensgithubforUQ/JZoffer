#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) : val(x),left(nullptr),right(nullptr) {}
};

vector<int> pre_order_traversal(TreeNode* root) { //所谓前序遍历，就是，先遍历左子树，然后遍历右子树，就是dfs的一种。
    vector<int> res;
    if (root != nullptr)res.push_back(root->val);
    else return res;
    vector<int> left = pre_order_traversal(root->left);
    vector<int> right = pre_order_traversal(root->right);
    res.insert(res.end(), left.begin(), left.end());
    res.insert(res.end(), right.begin(), right.end());
    return res;
}

vector<int> in_order_Traversal(TreeNode* root) {
    // write code here
}