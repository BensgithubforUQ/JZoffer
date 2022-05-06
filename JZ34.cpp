#include "Solution3.h"

vector<vector<int>> Solution3::FindPath(TreeNode* root, int expectNumber) {
	//JZ34 �������к�Ϊĳһֵ��·��(��)
	/*����һ�Ŷ������ĸ��ڵ�root��һ������expectNumber���ҳ��������н��ֵ�ĺ�ΪexpectNumber������·����
		1.����·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ�ӽ���������Ľ��
		2.Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ�
		3.·��ֻ�ܴӸ��ڵ㵽�ӽڵ㣬���ܴ��ӽڵ㵽���ڵ�
		4.�ܽڵ���ĿΪn

		�������rootΪ{ 10,5,12,4,7 }, expectNumberΪ22*/
	//   10
	// 5   12
	//4 7 
	vector<vector<int>> ret;
	vector<int> path;
	dfs(root, expectNumber,ret,path);
	return ret;
}

void Solution3::dfs(TreeNode* root, int number, vector<vector<int>>& ret, vector<int> &path) {
	// ������Ϊ��
	if (root == NULL) return;
	// ·������
	path.push_back(root->val);
	// number����
	number -= root->val;
	// ����ݹ鵱ǰ�ڵ�ΪҶ�ӽڵ��Ҹ���·����ֵ�Ѿ��ﵽ��expectNumber�������ret
	if (root->left == NULL && root->right == NULL && number == 0) {
		ret.push_back(path);
	}
	// ���������ݹ�
	dfs(root->left, number,ret,path);
	dfs(root->right, number, ret, path);
	path.pop_back();//��ִ����͵�ǰ����йص�·������֮�󣬾�pop�������ͱ�֤��path�Ļ���
}