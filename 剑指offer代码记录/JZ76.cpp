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
    void ergodic(ListNode* pHead) { //���������Ϲ�ϣ��
        if (pHead == nullptr) return;
        mp[pHead->val]++;
        ergodic(pHead->next);
    }
    ListNode* deleteDuplication(ListNode* pHead) { //�򵥵��������
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
                node->next = nullptr; //ע�⣬������ظ������֣�Ӧ��������node����һ���������Ϊ��
                //�����м䲻�������⣬��������������ظ�����û�д���
            }
            pHead = pHead->next;
        }
        return head->next->next;
    }


};