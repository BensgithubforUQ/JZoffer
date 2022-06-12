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
static int num = 0;

char* Solution4::Serialize(TreeNode1* root) {
	num = dfs(root);
	cout << num << endl;
	int size = 1; //数组长度
	int temp = 1;
	for (int i = 0; i < num - 1; i++) {
		temp = temp * 2;
		size += temp;
	}
	cout << size << "," << num << endl;
	string s;
	dfs(root, s, num);
	cout << s << endl;
	char* c = new char[size];
	s.copy(c, size, 0);
	*(c + size) = '\0';
	return c;

}
TreeNode1* Solution4::Deserialize(char* str) {
	TreeNode1* root = new TreeNode1(str[0]);
	cout << "Deserialize num: " << num << endl;
	printf("%s\n", str);
	int num1 = num;
	cout << "Deserialize " << num1 << endl;
	re(root, str, num1, 0);
	
	cut(root);
	cout << "????" << dfs(root) << endl;

	return root;
}

int Solution4::dfs(TreeNode1* root) { //查询一波深度
	if (root == nullptr) return 0;
	int num = 1;
	if (root->left != nullptr || root->right != nullptr) {
		int l_num = dfs(root->left);
		int r_num = dfs(root->right);
		num += (l_num > r_num) ? l_num : r_num;
	}
	return num;
}

void Solution4::dfs(TreeNode1* root, string& s, int num) {
	if (root == nullptr) return;
	if (root->val == 0) root->val = 0;
	if (num > 0) {
		s += to_string(root->val);
		num--;
		if (root->left == nullptr) {
			TreeNode1* l = new TreeNode1(0);
			root->left = l;
		}
		if (root->right == nullptr) {
			TreeNode1* r = new TreeNode1(0);
			root->right = r;
		}
		dfs(root->left, s, num);
		dfs(root->right, s, num);

	}
}

int Solution4::re(TreeNode1* root, char* s, int num1, int n) {
	if (num1 == 0 ) return n - 1;
	root->val = (int)s[n] - 48;
	printf("n:%d,val:%d,num:%d\n", n, root->val,num1);
	if (num1 > 0) {
		
		num1--;
		TreeNode1* left1 = new TreeNode1(0);
		root->left = left1;
		n = re(root->left, s, num1, ++n);
		TreeNode1* right1 = new TreeNode1(0);
		root->right = right1;
		n = re(root->right, s, num1, ++n);
		
	}
	printf("n:%d\n", n);
	return n;
}

void Solution4::cut(TreeNode1* root) {
	cout << "cut11111" << endl;
	if (root == nullptr) return;
	if (root->left->val == 0) {
		TreeNode1* temp = nullptr;
		root->left = temp;
	}
	else {
		cout << "left" << root->left->val << endl;
		cut(root->left);
	}
	if (root->right->val == 0) {
		TreeNode1* temp = nullptr;
		root->right = temp;
	}
	else {
		cout <<"right" << root->right->val << endl;
		cut(root->right);
	}
}


//int main() {
//	Solution4 s4;
//	int num = 1;
//	TreeNode1*	n1 = new TreeNode1(5);
//	TreeNode1* n2 = new TreeNode1(4);
//	TreeNode1* n3 = new TreeNode1(3);
//	TreeNode1* n4 = new TreeNode1(2);
//	n1->right = n2;
//	n2->right = n3;
//	n3->right = n4;
//	TreeNode1* n5 = s4.Deserialize(s4.Serialize(n1));
//	cout << "after" << endl;
//	s4.Serialize(n5);
//	return 0;
//}