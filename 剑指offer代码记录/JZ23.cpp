#include "Solution2.h"

ListNode23* Solution2::EntryNodeOfLoop(ListNode23* pHead) { //˫ָ��
	/*��һ������Ϊn���������а����������ҳ�������Ļ�����ڽ�㣬���򣬷���null��

		���ݷ�Χ�� n\le10000n��10000��1 <= ���ֵ <= 100001 <= ���ֵ <= 10000
		Ҫ�󣺿ռ临�Ӷ� O(1)O(1)��ʱ�临�Ӷ� O(n)O(n)*/
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

ListNode23* EntryNodeOfLoop_hash(ListNode23* pHead) { //hash��
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