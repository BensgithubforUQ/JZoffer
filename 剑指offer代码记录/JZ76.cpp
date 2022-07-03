#include <iostream>
#include <unordered_map>
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
    unordered_map<int, int> mp;
    void ergodic(ListNode* pHead) { //链表遍历配合哈希表
        if (pHead == nullptr) return;
        mp[pHead->val]++;
        ergodic(pHead->next);
    }
    ListNode* deleteDuplication(ListNode* pHead) { //简单的链表遍历
        ergodic(pHead);
        ListNode* node = new ListNode(0);
        ListNode* head = new ListNode(0);
        head->next = node;
        while (pHead != nullptr) {
            if (mp[pHead->val] == 1) {
                node->next = pHead;
                node = node->next;
            }
            else {
                node->next = nullptr; //注意，如果是重复的数字，应该主动把node的下一个结点设置为空
                //否则中间不会有问题，但是最后连续的重复结点会没有处理。
            }
            pHead = pHead->next;
        }
        return head->next->next;
    }


};