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
	//输入一个整数 n ，输出该数32位二进制表示中1的个数。其中负数用补码表示。
	//正整数的补码是其二进制表示，与原码相同
	//求负整数的补码，将其原码除符号位外的所有位取反（0变1，1变0，符号位为1不变）后加1
	//数0的补码表示是唯一的
	//[+0]补=[+0]反=[+0]原=00000000
	//[-0]补 = 11111111 + 1 = 00000000
	//vector<int> dp(n,0); //n个元素，用来储存n中1的个数
	long long int PowerOfTwo[32];
	PowerOfTwo[0] = 1;
	for (int power = 1; power < 32; power++) {
		PowerOfTwo[power] = PowerOfTwo[power - 1] * 2; //先得到2的次方的数值
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
}//JZ15 二进制中1的个数