#include "Solution2.h"

ListNode_JZ18* Solution2::deleteNode(ListNode_JZ18* head, int val) {
	//�������������Ҫͬʱȡǰ�к������ڵ�������Ѱֵ��ɾ������
	if (head->val == val) {
		return head->next; //ֱ�ӷ��صڶ���λ��
	}
	auto head0 = new ListNode_JZ18(-1); //����һ���µ�ͷ���
	head0->next = head; //�µ�ͷ���ָ�������ͷ���
	auto pre = head0; //��ΪheadҪ��Ϊ�����Ľ��ʹ�ã�pre����head��ǰһ����㣬���������ͷ�������һ�¡�
	while (head) { //��head��Ϊ�գ��������һ��
		if (head->val == val) { 
			//���head��val�������valһ������pre����һ�����͸ı�Ϊhead����һ����㡣
			pre->next = head->next;
			//ֱ��return���ڵ��next���
			return head0->next;
		}
		else {
			//���val��һ������head��Ų��һ����preҲŲ��һ��(���head)
			pre = head;
			head = head->next;
		}
	}
	return head0->next;//�������head0��next���
}