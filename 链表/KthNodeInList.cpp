#include <iostream>
#include <map>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) { //快慢指针输出链表的后k个结点
        // write code here
        if (pHead == nullptr) return pHead;
        ListNode* slow = pHead;
        ListNode* fast = pHead;
        for (int i = 0; i < k; i++)
            if (fast == nullptr) return NULL;
            else fast = fast->next;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) { //上题的进阶版本
        // write code here
        if (n == 0) return head; //这个题巨阴，如果这个地方输入是个0，那意味着快慢结点一起行动，到最后就是直接返回整个数组
        //因此这里直接这样写就好
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            if (fast) fast = fast->next;
            else return NULL;
        }
        if (fast) fast = fast->next; //因为需要删掉结点，因此需要的实际上是倒数k+1而不是k，因此这里需要再走一位
        else return slow->next; //如果fast已经是空了，那意味着链表一共就k个值，返回第二个节点就行
        while (fast) { //否则开始进入双指针挪动环节，直到找到倒数第k+1个结点slow
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; //删除倒数第k个结点
        return head;
    }
};