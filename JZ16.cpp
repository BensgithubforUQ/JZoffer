#include "Solution2.h"

double Solution2::Power(double base, int exponent) {
	/*实现函数 double Power(double base, int exponent)，求base的exponent次方。

		注意：
		1.保证base和exponent不同时为0。
		2.不得使用库函数，同时不需要考虑大数问题
		3.有特殊判题，不用考虑小数点后面0的位数。*/

	// 2.2~2 = 2.2 * 2.2 
	// 2.2~-2 = (1/2.2) * （1/2.2）
	// 负数带个target
	bool flag_base_minus = false;
	bool flag_exponen_minus = false;
	if (base == 0 && exponent == 0) {
		cerr << "base == 0 && exponent == 0" << endl;
		return -1;
	}
	if (exponent == 0) return 1;
	if (exponent < 0) {
		flag_exponen_minus = true;
		base = 1 / base; //取反
		exponent = 0 - exponent; //取正
	}
	if (base < 0) {
		flag_base_minus = true;
		base = 0 - base; //取正
	}
	double res = 1.00000;
	for (int i = 0; i < exponent; i++) {
		res = res * base;
	}
	if (flag_base_minus && exponent % 2 != 0) {
		return 0 - res;
	}
	else {
		return res;
	}
}

double Solution2::Power_DP(double base, int exponent) {
	bool flag_base_minus = false;
	bool flag_exponen_minus = false;
	if (base == 0 && exponent == 0) {
		cerr << "base == 0 && exponent == 0" << endl;
		return -1;
	}
	if (exponent == 0) return 1;
	if (exponent < 0) {
		flag_exponen_minus = true;
		base = 1 / base; //取反
		exponent = 0 - exponent; //取正
	}
	if (base < 0) {
		flag_base_minus = true;
		base = 0 - base; //取正
	}
	//前面都一样
	//这里还是用到动态规划，比如5的4次方，实际上就是5的二次方乘以5的二次方，可以少算一半。
	double dp[101];
	dp[0] = 1.00000;
	dp[1] = base;
	for (int i = 2; i < exponent + 1; i++) {
		dp[i] = dp[i / 2] * dp[i - i / 2];
	}
	if (flag_base_minus && exponent % 2 != 0) {
		return 0 - dp[exponent];
	}
	else {
		return  dp[exponent];
	}
}