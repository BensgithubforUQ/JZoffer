#include "Solution2.h"

ListNode23* Solution2::ReverseList(ListNode23* pHead) {//JZ24 反转链表
	/*给定一个单链表的头结点pHead(该头节点是有值的，
		比如在下图，它的val是1)，长度为n，反转该链表后，返回新链表的表头。*/
    ListNode23* pre = nullptr;
    ListNode23* cur = pHead;
    ListNode23* nex = nullptr; // 这里可以指向nullptr，循环里面要重新指向
    //null  1  2  3  4  5  6  7  null
    //pre  cur nex
    while (cur) {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
       /* int temp = x; //是基础的反转思路
        x = y;
        y = temp;*/
    }
    return pre;
}