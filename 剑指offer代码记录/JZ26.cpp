#include "Solution3.h"


bool Solution3::recursion(TreeNode* root1, TreeNode* root2) {
	if (root2 == nullptr) return true; //root�������ˣ�����Ҷ�ӽ��
	if (root1 == nullptr) return false;//root2û�б����꣬����root1��������
	if (root1->val != root2->val) return false; //ֵ�����
	return recursion(root1->left, root2->left) && recursion(root1->right, root2->right); //���ֵ��ȣ���û��Ҷ��㣬����������ҽڵ㡣
}

bool Solution3::HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {//JZ26 �����ӽṹ
	/*�������ö�����A��B���ж�B�ǲ���A���ӽṹ��������Լ��������������һ�������ӽṹ��
		�������AΪ{ 8,8,7,9,2,#,#,#,#,4,7 }��BΪ{ 8,9,2 }��2�����Ľṹ���£����Կ���B��A���ӽṹ*/
	//if (pRoot2 == NULL) return false;
	bool result = false;
	if (pRoot1 != nullptr && pRoot2 != nullptr) {
		if (pRoot1->val == pRoot2->val) {
			result = recursion(pRoot1, pRoot2); //����ҵ��˽��ֵ��root2���ڵ�ֵһ�µĽ�㣬�Ϳ��Գ��Խ���ƥ��
		}
		if (!result) result =  HasSubtree(pRoot1->left,pRoot2); //���û�У��ͼ�������ڵ�
		if (!result) result =  HasSubtree(pRoot1->right, pRoot2);//�����ڵ�û�У��ͼ������ҽ����
	}
	return result;
}