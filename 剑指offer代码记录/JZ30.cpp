#include "Solution3.h"
//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص� min ������
//�������ʱ��֤ pop��top �� min ��������ʱ��ջ��һ����Ԫ�ء�
//
//��ջ�����ķ����У�
//push(value) :��valueѹ��ջ��
//pop() : ����ջ��Ԫ��
//top() : ��ȡջ��Ԫ��
//min() : ��ȡջ����СԪ��
//ջ���Ƚ��������
//stack<int> s1;
//stack <int> s2;
//˫ջ��
//s2����;�ǣ���¼��Сֵ����Ϊջ����ɾ�������������Сֵ��pop�Ĺ������ǻ�仯�ģ�����Ҫ��¼ÿջ��-ջ����ͬ�׶ε���Сֵ��
//���push�˸����ֵ��ջ���Ǿ��ظ�push��ǰ��С��ֵ��s2������ǰ��С��ֵ������s2��top��
void Solution3::push(int value) {//JZ30 ����min������ջ
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