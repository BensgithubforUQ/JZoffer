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


    //反转链表，模板3，更高难度的反转。
    ListNode* reverse(ListNode* pre, int k) { //k段链表的颠倒。pre-> k->next 变成 pre->颠倒后的k->next; 
        if (pre == nullptr || pre->next == nullptr || k == 1) return pre;
        ListNode* start = pre; //起点
        ListNode* head = pre->next;
        ListNode* cur = head; //当前
        ListNode* nex = head->next; //下一个
        ListNode* fast = pre; //双指针
        for (int i = 0; i < k; i++) {
            if (fast->next != nullptr)
                fast = fast->next;//快指针先跑k步，判断是否满足k的倍数
            else
                return nullptr; //如果不满足k个，则返回null，不进行颠倒
        }
        while (k > 1) { //否则开始颠倒
            head = nex; //head挪到下一个
            nex = head->next; //nex挪到下一个
            head->next = cur; //head的next指向前一个
            cur = head; //cur记录新的
            k--; //k降低一个
        }
        start->next->next = nex; //原来的起点的下一个指向原本链表段的最后一个元素的下一个
        ListNode* temp = start->next; //原来的起点
        start->next = cur;
        if (temp->next) return temp; //这一步很重要的，，不然如果k == size，会导致无限循环。。
        else return nullptr; //如果颠倒完之后，发现新的pre的下一个数是空的，那说明刚好完成任务，返回null
        //如果不加这一步，会导致刚好的情况无限循环、
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (head == nullptr || head->next == nullptr || k == 1) return head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        while (res) {
            res = reverse(res, k);
        }
        return pre->next;
    }
};