#include "Solution4.h"

int MoreThanHalfNum_Solution(vector<int> numbers) {
	/*��һ������Ϊ n �����飬��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡�
		��������һ������Ϊ9������[1, 2, 3, 2, 2, 2, 5, 4, 2]����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2��

		���ݷ�Χ��n \le 50000n��50000��������Ԫ�ص�ֵ 0 \le val \le 100000��val��10000
		Ҫ�󣺿ռ临�Ӷȣ�O(1)O(1)��ʱ�临�Ӷ� O(n)O(n)*/
	int size = numbers.size();
	int half = size / 2;
	sort(numbers.begin(), numbers.end());
	return numbers[half];
	//����һ���������������֮����λ�϶����������
}