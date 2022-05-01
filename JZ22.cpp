#include "Solution2.h"

ListNode_JZ18* Solution2::FindKthToTail(ListNode_JZ18* pHead, int k) {//JZ22 链表中倒数最后k个结点
	/*输入一个长度为 n 的链表，设链表中的元素的值为 ai ，返回该链表中倒数第k个节点。
		如果该链表长度小于k，请返回一个长度为 0 的链表。*/

	//典型的快慢指针，慢指针比快指针慢k
	//快指针先遍历k-1个，然后慢指针开始遍历，返回慢指针。
	
	ListNode_JZ18* fast = pHead;
	ListNode_JZ18* slow = pHead;
	if (!pHead) return NULL;
	while (k>0) {
		//k == 1， 快指针和慢指针一起动
		//k == 2,  快指针先走一步
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