#include "Solution2.h"

ListNode23* Solution2::EntryNodeOfLoop(ListNode23* pHead) { //双指针
	/*给一个长度为n链表，若其中包含环，请找出该链表的环的入口结点，否则，返回null。

		数据范围： n\le10000n≤10000，1 <= 结点值 <= 100001 <= 结点值 <= 10000
		要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)*/
	// m , n
	//fast m + x + n 
	//slow m + x  v    
    if (pHead == NULL) return NULL;
    ListNode23* fast = pHead;
    ListNode23* slow = pHead;
    int flag = false;
    while (fast != NULL && fast->next != NULL) {

        fast = fast->next;
        fast = fast->next;
        slow = slow->next;
        if (slow == fast) {
            break;
        }
    }
    if (fast == NULL || fast->next == NULL) return NULL;
    fast = pHead;
    while (slow != fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}

ListNode23* EntryNodeOfLoop_hash(ListNode23* pHead) { //hash法
    vector<ListNode23*> node_vc;
    while (pHead != NULL && pHead->next != NULL) {
        node_vc.push_back(pHead);
        pHead = pHead->next;
        for (auto n : node_vc) {
            if (pHead == n) return pHead;
        }
    }
    return NULL;
}