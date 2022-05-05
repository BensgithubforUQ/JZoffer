#include "Solution3.h"
#include <algorithm>

bool Solution3::IsPopOrder(vector<int> pushV, vector<int> popV) {
	// JZ31 栈的压入、弹出序列\
	输入两个整数序列，第一个序列表示栈的压入顺序，
	//请判断第二个序列是否可能为该栈的弹出顺序。
	//	假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，
	//	但4,3,5,1,2就不可能是该压栈序列的弹出序列。

	//[1,2,3,4,5] 
	//[4,3,5,1,2] 
	stack<int> s;
	//辅助栈
	int size = pushV.size();
	int i = 0, j = 0;
	for (; j < size; j++) {//j是出栈数组
		while (i < size && (s.empty() || s.top() != popV[j])) {//当入栈数组没完并且，目前栈顶元素和出栈元素不一样的时候
			//入栈
			s.push(pushV[i]);
			++i;
			//第一波，【1,2,3,4】4和出栈数据当前元素相同，跳出
			//第二波，【1,2,3】 3和出栈数据当前元素相同，跳出
			//第三波，【1,2】+【5】，入栈完毕
		}
		if (s.top() == popV[j]) {
			//1.入栈数据清空
			//2.栈顶和出栈数组当前元素相同
			s.pop();
			//【4】，pop，j++，当前元素为3。
			//【3】，pop，j++，当前元素为5
			// 入栈已经完毕
			//【5】，pop
			//【2】 ！= 【1】 ，出现错误，当前栈顶为2，而出栈数据当前数据为【1】，是不可能的顺序，因此报错。
		}
		else {
			//当入栈数据清空，就开始检测是否与出栈一致，因为不会再有元素入栈，如果这是发生栈顶和出栈数组当前元素不一样
			//则为不可能的顺序
			return false;
		}
	}
	return true;
}