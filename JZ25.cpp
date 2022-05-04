#include "Solution3.h"

ListNode_JZ25* Solution3::Merge(ListNode_JZ25* pHead1, ListNode_JZ25* pHead2) {
	//JZ25 合并两个排序的链表
	/*输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。*/
	//双指针 cur1，cur2
	ListNode_JZ25* cur1 = pHead1;
	ListNode_JZ25* cur2 = pHead2;
	ListNode_JZ25* head = new ListNode_JZ25(0);
	ListNode_JZ25* cur = head;
	//新建一条链
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