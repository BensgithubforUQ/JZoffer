#include "Solution2.h"

ListNode_JZ18* Solution2::FindKthToTail(ListNode_JZ18* pHead, int k) {//JZ22 �����е������k�����
	/*����һ������Ϊ n �������������е�Ԫ�ص�ֵΪ ai �����ظ������е�����k���ڵ㡣
		�����������С��k���뷵��һ������Ϊ 0 ������*/

	//���͵Ŀ���ָ�룬��ָ��ȿ�ָ����k
	//��ָ���ȱ���k-1����Ȼ����ָ�뿪ʼ������������ָ�롣
	
	ListNode_JZ18* fast = pHead;
	ListNode_JZ18* slow = pHead;
	if (!pHead) return NULL;
	while (k>0) {
		//k == 1�� ��ָ�����ָ��һ��
		//k == 2,  ��ָ������һ��
		if (!fast) return NULL;
		fast = fast->next;
		--k;
	}
	while (fast) {
		slow = slow->next;
		fast = fast->next;

	}
	return slow;
}