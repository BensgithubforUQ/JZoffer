#include "Solution2.h"

vector<int> Solution2::printNumbers(int n) {
	/*输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
		1. 用返回一个整数列表来代替打印
		2. n 为正整数，0 < n <= 5*/
	//n表示的是位数 n（0,5）
	int endNum = 1; //n = 0
	for (int i = 1; i <= n; i++) {
		endNum = endNum * 10; //这里位数很少就没必要用快速幂了罢
	}
	vector<int> numList;
	int number = 1; //起始数字
	while (numList.size()<endNum-1) {
		numList.push_back(number);
		++number;
	}
	return numList;

}