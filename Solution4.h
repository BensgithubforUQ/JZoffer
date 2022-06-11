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

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
class Solution4 {
	TreeNode* Convert(TreeNode* pRootOfTree);

	char* Serialize(TreeNode* root);
	TreeNode* Deserialize(char* str);
};