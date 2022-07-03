#include "Solution2.h"

int Solution2::cutRope_supplementary(int n) {
	if (n == 2) return 2;
	if (n == 3) return 3;
	if (n - 3 >= 2) {
		return 3 * cutRope_supplementary(n - 3);
	}
	else {
		return 2 * cutRope_supplementary(n - 2);
	}
}

int Solution2::cutRope(int n) {
	//JZ14 剪绳子
	/*给你一根长度为 n 的绳子，请把绳子剪成整数长的 m 段（ m 、 n 都是整数， n > 1 并且 m > 1 ， m <= n ），
		每段绳子的长度记为 k[1], ..., k[m] 。
		请问 k[1] * k[2]*...*k[m] 可能的最大乘积是多少？
		例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积是 18 。*/
	//2< <60
	// 3 2  2,4 2 4,5 6,6, 8, 7 12,8 16,9,绝对不能出现1
	if (n == 2) return 1;
	if (n == 3) return 2;
	return cutRope_supplementary(n);
}

int Solution2::cutRope_DP(int n) {
	/*动态规划算法的基本思想是：
		将待求解的问题分解成若干个相互联系的子问题，先求解子问题，然后从这些子问题的解得到原问题的解；
		对于重复出现的子问题，只在第一次遇到的时候对它进行求解，
		并把答案保存起来，让以后再次遇到时直接引用答案，不必重新求解。
		动态规划算法将问题的解决方案视为一系列决策的结果*/

	//先分解问题
	//n = 2 ，return 1;
	//n = 3, return 2;
	//n = 4, return 4;
	//n = 5,return 6; {(n = 3) * 2/ (n = 2)*3}
	//n = 6,return (n = 4) * 2
	//n = 7,return (n = 5) * 2 / (n = 4) * 3
	//n = 8,return (n = 5) * 3/ (n = 6) * 2
	//。。。
	//可知，比较
	if (n <= 3) {
		return n - 1;
	}
	vector<int> dp(n+2, 0);
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 4;
	dp[5] = 6;
	for (int i = 6; i < n + 1; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j])); //精华，所谓动态规划，就是子问题复用。
			//这里复用d[i-j](是以前循环得出的最大值)，和 本次可分的j相乘
		}
	}
	return dp[n];
}