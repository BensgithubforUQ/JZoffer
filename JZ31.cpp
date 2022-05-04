#include "Solution3.h"
#include <algorithm>

bool Solution3::IsPopOrder(vector<int> pushV, vector<int> popV) {
	// JZ31 栈的压入、弹出序列\
	输入两个整数序列，第一个序列表示栈的压入顺序，
	//请判断第二个序列是否可能为该栈的弹出顺序。
	//	假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
	//	但4,3,5,1,2就不可能是该压栈序列的弹出序列。

	//[1,2,3,4,5] [5,4,3,2,1]
	//[4,3,5,1,2] 
	//[4,5,3,2,1] 
	//[4,3,5,1,5]
	//[4,3,5,2,1]
	//[3,4,5,2,1]
	//[5,4,3,2,1]
	//[1,2,3,4,5]
	stack<int> s;
	int size = pushV.size();
	int i = 0, j = 0;
	for (; i < size; ) {
		if (s.empty()) {
			s.push(pushV[i]);
			++i;
		}
		if (pushV[i] != popV[j]) {
			s.push(pushV[i]);
			++i;
		}
		if (pushV[i] == popV[j]) {
			s.pop();
			++j;
		}
	}
	if (j != size) return false;
	else return true;
}