#include "Solution.h"

//������ջ��ʵ��һ�����У�ʹ��n��Ԫ������� n ���ڶ���β����������(push)��n���ڶ���ͷ��ɾ������(pop)�Ĺ��ܡ� 
//�����е�Ԫ��Ϊint���͡���֤�����Ϸ�������֤pop����ʱ����������Ԫ�ء�
//���ݷ�Χ�� n\le1000n��1000
//Ҫ�󣺴洢n��Ԫ�صĿռ临�Ӷ�Ϊ O(n)O(n) ��������ɾ����ʱ�临�Ӷȶ��� O(1)O(1)

//ջ�����ԣ��Ƚ���������е����ԣ��Ƚ����ȳ�������ջʵ�ֶ��У�
//����push��ʱ�򣬳�ʼ��stack1��Ȼ��pop��ʱ�򣬰�stack1ȫ��pop������stack3��Ȼ��pop stack3��һ������

void Solution::push(int node) { //����ջ��ʵ�ַ���
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

void Solution::push1(int node) {//����ջ�����ǵ������ٵ���ȥ
	stack1.push(node);
}

int Solution::pop1() {
	while (!stack1.empty()) {
		stack2.push(stack1.top());
		stack1.pop();
	}
	int top_of_queue = stack2.top(); //����֮ǰ����Ҫ���ص�ֵ

	//Ȼ���top pop�ˣ��ٰ�ʣ�µĻ���stack1
	stack2.pop();
	while (!stack2.empty()) {
		stack1.push(stack2.top());
		stack2.pop();
	}
	return top_of_queue;
}
	