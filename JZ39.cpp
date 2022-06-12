#include "Solution4.h"

int MoreThanHalfNum_Solution(vector<int> numbers) {
	/*给一个长度为 n 的数组，数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
		例如输入一个长度为9的数组[1, 2, 3, 2, 2, 2, 5, 4, 2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。

		数据范围：n \le 50000n≤50000，数组中元素的值 0 \le val \le 100000≤val≤10000
		要求：空间复杂度：O(1)O(1)，时间复杂度 O(n)O(n)*/
	int size = numbers.size();
	int half = size / 2;
	sort(numbers.begin(), numbers.end());
	return numbers[half];
	//超过一半的数，排序完了之后，中位肯定有这个数。
}