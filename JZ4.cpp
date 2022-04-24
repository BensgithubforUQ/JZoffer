#include "Solution.h"

bool Solution::Find(int target, vector<vector<int> > array) {//JZ4 二维数组中的查找
	/*在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
		每一列都按照从上到下递增的顺序排序。
		请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/
	if (!array.empty()) {
		for (auto i : array) {
			if (i[0] > target) {
				continue;
			}
			else {
				for (auto j : i) {
					if (j == target) {
						return true;
					}
				}
			}
		}
		return false;
	}
	else {
		return false;
	}
}

bool Solution::Find1(int target, vector<vector<int> > array) {//JZ4 二维数组中的查找
	/*在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
		每一列都按照从上到下递增的顺序排序。
		请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。*/
	set<int>s;
	for (auto i : array) {
		for (auto j : i) {
			s.insert(j);
		}
	}
	int intial_Size = s.size();
	s.insert(target);
	if (intial_Size != s.size()) {
		return false;
	}
	else {
		return true;
	}
}

