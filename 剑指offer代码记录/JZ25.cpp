#include "Solution3.h"

ListNode_JZ25* Solution3::Merge(ListNode_JZ25* pHead1, ListNode_JZ25* pHead2) {
	//JZ25 �ϲ��������������
	/*��������������������������ĳ���Ϊn���ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�*/
	//˫ָ�� cur1��cur2
	ListNode_JZ25* cur1 = pHead1;
	ListNode_JZ25* cur2 = pHead2;
	ListNode_JZ25* head = new ListNode_JZ25(0);
	ListNode_JZ25* cur = head;
	//�½�һ����
	while (cur1 != NULL && cur2 != NULL) {
		if (cur1->val >= cur2->val) {
			cur->next = cur2;
			cur2 = cur2->next;
			
		}
		else {
			cur->next = cur1;
			cur1 = cur1->next;
			
		}
		cur = cur->next;
	}
	if (cur1 == NULL) cur->next = cur2;
	if (cur2 == NULL) cur->next = cur1;
	return head->next;
}