#include "Solution.h"

//用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 
//队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
//数据范围： n\le1000n≤1000
//要求：存储n个元素的空间复杂度为 O(n)O(n) ，插入与删除的时间复杂度都是 O(1)O(1)

//栈的特性，先进后出，队列的特性，先进，先出，两个栈实现队列，
//则在push的时候，初始化stack1，然后pop的时候，把stack1全部pop出来给stack3，然后pop stack3第一个数字

void Solution::push(int node) { //三个栈的实现方法
	stack1.push(node);
	stack<int> stack3;
	stack3.swap(stack2);
	stack3 = stack1;
	int size = stack3.size();
	for (int i = 0; i < size; i++) {
		stack2.push(stack3.top());
		stack3.pop();
	}
}

int Solution::pop() {
	int temp_pop = stack2.top();
	stack2.pop();
	stack<int> stack3;
	stack3.swap(stack1);
	stack3 = stack2;
	int size = stack3.size();
	for (int i = 0; i < size; i++) {
		stack1.push(stack3.top());
		stack3.pop();
	}
	return temp_pop;
}

void Solution::push1(int node) {//两个栈，就是倒过来再倒过去
	stack1.push(node);
}

int Solution::pop1() {
	while (!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	int top_of_queue = stack2.top(); //在那之前保存要返回的值

	//然后把top pop了，再把剩下的还给stack1
	stack2.pop();
	while (!stack2.empty()) {
		stack1.push(stack2.top());
		stack2.pop();
	}
	return top_of_queue;
}
	