#include "Solution3.h"
//定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的 min 函数，
//输入操作时保证 pop、top 和 min 函数操作时，栈中一定有元素。
//
//此栈包含的方法有：
//push(value) :将value压入栈中
//pop() : 弹出栈顶元素
//top() : 获取栈顶元素
//min() : 获取栈中最小元素
//栈，先进，后出。
//stack<int> s1;
//stack <int> s2;
//双栈法
//s2的用途是，记录最小值，因为栈还有删除操作，因此最小值在pop的过程中是会变化的，所以要记录每栈底-栈顶不同阶段的最小值。
//如果push了更大的值入栈，那就重复push当前最小的值进s2，而当前最小的值，就是s2的top。
void Solution3::push(int value) {//JZ30 包含min函数的栈
	s1.push(value);
	if (s2.empty() || value < s2.top()) s2.push(value);
	else s2.push(s2.top());
}
void Solution3::pop() {
	s1.pop();
	s2.pop();
}
int Solution3::top() {
	return s1.top();
}
int Solution3::min() {
	return s2.top();
}