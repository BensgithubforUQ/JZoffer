#include <iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) { //反转链表，别傻了，两个链表合成一个，就是新整个头结点，然后插入
        ListNode* head = new ListNode(INT_MIN);
        ListNode* pre = head;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) { //挨个插，插一个就往后挪一位
                head->next = pHead1;
                pHead1 = pHead1->next;
            }
            else if (pHead1->val > pHead2->val) {
                head->next = pHead2;
                pHead2 = pHead2->next;
            }
            head = head->next;
        }
        if (pHead1) head->next = pHead1; //如果哪个链表插完了，那肯定就空了
        if (pHead2) head->next = pHead2; //没空的那个，后面剩下的都是大的，那就直接尾插
        return pre->next; //头结点的下一个就是返回值、
    }
};