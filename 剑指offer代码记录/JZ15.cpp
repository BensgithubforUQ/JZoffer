#include "Solution2.h"

int  Solution2::NumberOf1_DP(long long int n,long long int * PowerOfTwo) {
	//for (int i = 31; i < 0;i--) {
	//	if (PowerOfTwo[i] == n) return 1;
	//	if (n > PowerOfTwo[i]) {
	//		n = n - PowerOfTwo[i];//
	//		return NumberOf1_DP(n, PowerOfTwo) + 1;
	//	}
	//}
	return 0;
}

int  Solution2::NumberOf1(int n) {
	//����һ������ n ���������32λ�����Ʊ�ʾ��1�ĸ��������и����ò����ʾ��
	//�������Ĳ�����������Ʊ�ʾ����ԭ����ͬ
	//�������Ĳ��룬����ԭ�������λ�������λȡ����0��1��1��0������λΪ1���䣩���1
	//��0�Ĳ����ʾ��Ψһ��
	//[+0]��=[+0]��=[+0]ԭ=00000000
	//[-0]�� = 11111111 + 1 = 00000000
	//vector<int> dp(n,0); //n��Ԫ�أ���������n��1�ĸ���
	long long int PowerOfTwo[32];
	PowerOfTwo[0] = 1;
	for (int power = 1; power < 32; power++) {
		PowerOfTwo[power] = PowerOfTwo[power - 1] * 2; //�ȵõ�2�Ĵη�����ֵ
		//cout << PowerOfTwo[power] << " ";
	}
	int count = 0;
	int flag = 1;
	if (n < 0) {
		n = 0 - n - 1;
		flag = 0;
	}
	for (int i = 31; i >= 0; i--) {
		if (n >= PowerOfTwo[i]) {
			n = n - PowerOfTwo[i];//
			++count;
		}
	}

	if (flag) return count;
	else return count = 32 - count;
}//JZ15 ��������1�ĸ���