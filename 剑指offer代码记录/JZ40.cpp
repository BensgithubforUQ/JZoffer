#include "Solution.h"

class compare { //仿函数来一个
public:
	bool operator()(int a,int b) const {
		return a > b;
	}
};

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {// 最小的K个数
	//给定一个长度为 n 的可能有重复值的数组，找出其中不去重的最小的 k 个数。
	//	例如数组元素是4, 5, 1, 6, 2, 7, 3, 8这8个数字，则最小的4个数字是1, 2, 3, 4(任意顺序皆可)。
	/*输入：
		[4, 5, 1, 6, 2, 7, 3, 8], 4
	返回值：
		[1, 2, 3, 4]
	说明：
		返回最小的4个数即可，返回[1, 3, 2, 4]也可以*/
	multiset<int,compare> s;
	vector<int> res;
	int min = 0;
	for (vector<int>::iterator i = input.begin(); i != input.end(); i++) {
		if (i - input.begin() < 4) {
			s.insert(*i);
			continue;
		}
		if ((*s.begin()) > *i) {
			s.erase(s.begin());
			s.insert(*i);
		}
	}
	for (multiset<int, compare>::iterator i = s.begin(); i != s.end(); i++) {
		res.push_back(*i);
	}
	return res;
}