#include "Solution3.h"

bool Solution3::VerifySquenceOfBST(vector<int> sequence) {
	/*����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����������򷵻� true, ���򷵻� false ��
		�������������������������ֶ�������ͬ��

		���ݷ�Χ�� �ڵ����� 0 \le n \le 10000��n��1000 ���ڵ��ϵ�ֵ���� 1 \le val \le 10 ^ {5}1��val��10
		5
		����֤�ڵ��ϵ�ֵ������ͬ
		Ҫ�󣺿ռ临�Ӷ� O(n)O(n) ��ʱ��ʱ�临�Ӷ� O(n ^ 2)O(n
			2
		)
		��ʾ��
		1.������������ָ���׽ڵ�����������е�ȫ���ڵ㣬����С���������е�ȫ���ڵ������
		2.��������Լ���������Ƕ���������
		3.���������ָ���� �������� - ������ - ���ڵ㡱 ��˳�����*/

	//��ν���������������Ǹ��ڵ������ڵ㣬С���ҽڵ㡣
	//��ν��������������򣩱�����������Ȼ�󣨺��򣩱�������������󷵻ظ��ڵ�
	//��ȷ�����ڵ��ֵ����ڵ�С�ڸ��ڵ㣬�ҽڵ���ڸ��ڵ㣬���Ƕ���������
	// ����
	//8��end��
	//6    10  (��֪��end-1������������㣬��6��begin - end�е�һ��>root��ֵ��ǰһ��)
	//5��begin�� 7  9 11
	//[5, 7, 6, 9, 11, 10, 8]
	return recursioVerify(sequence, 0, sequence.size() - 1);
}

bool Solution3::recursioVerify(vector<int> sequence, int begin, int end) {
	if (sequence.empty()|| end<begin) return false;
	int root = sequence[end];//ends�Ǹ����
	int index = 0;//index���ڲ����������ĸ��ڵ�
	for (; index < end; index++) {
		if (sequence[index] > root) {//�����������ڵ���ڸ��ڵ��ʱ�򣬾��ҵ��˸��ڵ����ڵ��������������Ҷ�ӽ��
			break;
		}
	}

	for (int j = index; j < end; j++) {//���������������㿪ʼ�ң��ұ��������κδ���root��ֵ���򷵻ش���
		if (sequence[j] < root) {
			return false;
		}
	}

	bool left = true;
	if (index > begin) {
		left = recursioVerify(sequence, begin, index - 1);//���������еݹ�
	}

	bool right = true;
	if (index < end - 1) {
		right = recursioVerify(sequence, index, end = index);//���������еݹ�
	}

	return left && right;//����ͬʱΪ�棬������������Ϊ��
}

//
//class Solution {
//	bool judge(vector<int>& a, int l, int r) {
//		if (l >= r) return true;
//		int i = r;
//		while (i > l && a[i - 1] > a[r]) --i;
//		for (int j = i - 1; j >= l; --j) if (a[j] > a[r]) return false;
//		return judge(a, l, i - 1) && (judge(a, i, r - 1));
//	}
//public:
//	bool VerifySquenceOfBST(vector<int> a) {
//		if (!a.size()) return false;
//		return judge(a, 0, a.size() - 1);
//	}
//};