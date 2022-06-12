#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode1 {
	int val;
	struct TreeNode1* left;
	struct TreeNode1* right;
	TreeNode1(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution4 {
public:
	TreeNode1* Convert(TreeNode1* pRootOfTree);
	void dfs(TreeNode1* node, vector<TreeNode1* >& v);

	char* Serialize(TreeNode1* root);
	TreeNode1* Deserialize(char* str);
	int dfs(TreeNode1* root);
	void dfs(TreeNode1* root, string& s, int num);
	int re(TreeNode1* root, char* s, int num, int n);
	void cut(TreeNode1* root);


	vector<string> Permutation(string str);//JZ38
	void permutation(set<string>& ans, string str, int index);
};