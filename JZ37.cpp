#include "Solution4.h"

//��ʵ�������������ֱ��������л��ͷ����л����������������л�֮����ַ�������Լ����
//��Ҫ���ܹ��������л�֮����ַ������¹����һ����ԭ��������ͬ������
//
//�����������л�(Serialize)��ָ����һ�ö���������ĳ�ֱ�����ʽ�Ľ����ĳ�ָ�ʽ����Ϊ�ַ�����
//�Ӷ�ʹ���ڴ��н��������Ķ��������Գ־ñ��档���л����Ի����������򡢺��򡢲���Ķ������ȱ�����ʽ�������޸ģ�
//���л��Ľ����һ���ַ��������л�ʱͨ�� ĳ�ַ��ű�ʾ�սڵ㣨#��
//
//�������ķ����л�(Deserialize)��ָ������ĳ�ֱ���˳��õ������л��ַ������str���ع���������
//
//���磬���Ը��ݲ�������ķ������л�������ͼ :
//�ڵ��� n \le 100n��100������ÿ���ڵ��ֵ���� 0 \le val \le 1500��val��150

char* Solution4::Serialize(TreeNode* root) {
	int num = dfs(root);
	int size = 1; //���鳤��
	int temp = 1;
	for (int i = 0; i < num-1; i++) {
		temp = temp * 2;
		size += temp;
	}
	int* array = new int[size]; //����

}
TreeNode* Solution4::Deserialize(char* str) {

}

int dfs(TreeNode* root) { //��ѯһ�����
	if (root == nullptr) return 0;
	int num = 1;
	if (root->left != nullptr || root->right != nullptr) {
		int l_num = dfs(root->left);
		int r_num = dfs(root->right);
			num += (l_num > r_num) ? l_num  :r_num;
	}
	return num;
}