#include "Solution2.h"

vector<int> Solution2::printNumbers(int n) {
	/*�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��
		1. �÷���һ�������б��������ӡ
		2. n Ϊ��������0 < n <= 5*/
	//n��ʾ����λ�� n��0,5��
	int endNum = 1; //n = 0
	for (int i = 1; i <= n; i++) {
		endNum = endNum * 10; //����λ�����پ�û��Ҫ�ÿ������˰�
	}
	vector<int> numList;
	int number = 1; //��ʼ����
	while (numList.size()<endNum-1) {
		numList.push_back(number);
		++number;
	}
	return numList;

}