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
	//JZ14 ������
	/*����һ������Ϊ n �����ӣ�������Ӽ����������� m �Σ� m �� n ���������� n > 1 ���� m > 1 �� m <= n ����
		ÿ�����ӵĳ��ȼ�Ϊ k[1], ..., k[m] ��
		���� k[1] * k[2]*...*k[m] ���ܵ����˻��Ƕ��٣�
		���磬�����ӵĳ����� 8 ʱ�����ǰ������ɳ��ȷֱ�Ϊ 2��3��3 �����Σ���ʱ�õ������˻��� 18 ��*/
	//2< <60
	// 3 2  2,4 2 4,5 6,6, 8, 7 12,8 16,9,���Բ��ܳ���1
	if (n == 2) return 1;
	if (n == 3) return 2;
	return cutRope_supplementary(n);
}

int Solution2::cutRope_DP(int n) {
	/*��̬�滮�㷨�Ļ���˼���ǣ�
		������������ֽ�����ɸ��໥��ϵ�������⣬����������⣬Ȼ�����Щ������Ľ�õ�ԭ����Ľ⣻
		�����ظ����ֵ������⣬ֻ�ڵ�һ��������ʱ�����������⣬
		���Ѵ𰸱������������Ժ��ٴ�����ʱֱ�����ô𰸣�����������⡣
		��̬�滮�㷨������Ľ��������Ϊһϵ�о��ߵĽ��*/

	//�ȷֽ�����
	//n = 2 ��return 1;
	//n = 3, return 2;
	//n = 4, return 4;
	//n = 5,return 6; {(n = 3) * 2/ (n = 2)*3}
	//n = 6,return (n = 4) * 2
	//n = 7,return (n = 5) * 2 / (n = 4) * 3
	//n = 8,return (n = 5) * 3/ (n = 6) * 2
	//������
	//��֪���Ƚ�
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
			dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j])); //��������ν��̬�滮�����������⸴�á�
			//���︴��d[i-j](����ǰѭ���ó������ֵ)���� ���οɷֵ�j���
		}
	}
	return dp[n];
}