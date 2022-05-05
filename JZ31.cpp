#include "Solution3.h"
#include <algorithm>

bool Solution3::IsPopOrder(vector<int> pushV, vector<int> popV) {
	// JZ31 ջ��ѹ�롢��������\
	���������������У���һ�����б�ʾջ��ѹ��˳��
	//���жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
	//	����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
	//	��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�

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