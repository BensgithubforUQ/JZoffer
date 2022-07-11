#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) { //经典题目 反转链表
        if (pHead == nullptr) return pHead;
        ListNode* pre = new ListNode(0); //链表的换位操作，整个pre指向该结点
        pre->next = pHead; 
        ListNode* temp = pHead->next;//整个temp结点记录下一个结点
        pHead->next = nullptr; //把当前结点的next置空
        while (temp) { //temp记录的是当前结点的下一个结点（原表）
            //temp不为空的时候，表还没遍历完
            pHead = temp; //当前结点跳到下一个位置
            temp = pHead->next; //temp也跳
            pHead->next = pre->next; //改变next指向，指向pre记录的上个结点的位置
            pre->next = pHead; //pre记录当前结点的位置
        }//循环
        return pre->next; //最后返回pre指向的下一个结点，也就是当前结点的位置。
        //也可以直接返回pHead，是同一个值。
    }


    ListNode* reverseBetween(ListNode* head, int m, int n) { //反转链表的进阶，区域反转链表
        // write code here
        if (head == nullptr || head->next == nullptr || m == n) return head;
        ListNode* pre = new ListNode(0); //整个新的链表头，方便操作
        pre->val = 0;
        pre->next = head;

        int i = 0;
        ListNode* cur = pre;
        ListNode* nex = head;
        ListNode* start = pre;
        for (; i < m; i++) {
            if (i == m - 1) start = cur; //记录开始反转的前一个，重点
            head = nex;
            nex = head->next;
            cur = head;
        }
        for (; i < n; i++) {
            head = nex;
            nex = head->next;
            head->next = cur;
            cur = head;
        }
        start->next->next = nex;
        start->next = cur;
        return pre->next;
    }
};