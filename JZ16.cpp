#include "Solution2.h"

double Solution2::Power(double base, int exponent) {
	/*ʵ�ֺ��� double Power(double base, int exponent)����base��exponent�η���

		ע�⣺
		1.��֤base��exponent��ͬʱΪ0��
		2.����ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ�������
		3.���������⣬���ÿ���С�������0��λ����*/

	// 2.2~2 = 2.2 * 2.2 
	// 2.2~-2 = (1/2.2) * ��1/2.2��
	// ��������target
	bool flag_base_minus = false;
	bool flag_exponen_minus = false;
	if (base == 0 && exponent == 0) {
		cerr << "base == 0 && exponent == 0" << endl;
		return -1;
	}
	if (exponent == 0) return 1;
	if (exponent < 0) {
		flag_exponen_minus = true;
		base = 1 / base; //ȡ��
		exponent = 0 - exponent; //ȡ��
	}
	if (base < 0) {
		flag_base_minus = true;
		base = 0 - base; //ȡ��
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
		base = 1 / base; //ȡ��
		exponent = 0 - exponent; //ȡ��
	}
	if (base < 0) {
		flag_base_minus = true;
		base = 0 - base; //ȡ��
	}
	//ǰ�涼һ��
	//���ﻹ���õ���̬�滮������5��4�η���ʵ���Ͼ���5�Ķ��η�����5�Ķ��η�����������һ�롣
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