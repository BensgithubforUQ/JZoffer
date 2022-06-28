#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) { //等长法
        if (pHead1 == nullptr || pHead2 == nullptr) return NULL;
        ListNode* head1 = new ListNode(0);
        ListNode* head2 = new ListNode(0);
        head1 = pHead1;
        head2 = pHead2;
        while (head1 != head2) {
            //其实就是 M + N 
            //         N + M
            head1 = head1->next;
            head2 = head2->next;
            if (head1 != head2) {
                if (head1 == nullptr) head1 = pHead2;
                if (head2 == nullptr) head2 = pHead1;
            }
        }
        return head1;
    }
};