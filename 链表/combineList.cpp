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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) { //��ת������ɵ�ˣ���������ϳ�һ��������������ͷ��㣬Ȼ�����
        ListNode* head = new ListNode(INT_MIN);
        ListNode* pre = head;
        while (pHead1 && pHead2) {
            if (pHead1->val <= pHead2->val) { //�����壬��һ��������Ųһλ
                head->next = pHead1;
                pHead1 = pHead1->next;
            }
            else if (pHead1->val > pHead2->val) {
                head->next = pHead2;
                pHead2 = pHead2->next;
            }
            head = head->next;
        }
        if (pHead1) head->next = pHead1; //����ĸ���������ˣ��ǿ϶��Ϳ���
        if (pHead2) head->next = pHead2; //û�յ��Ǹ�������ʣ�µĶ��Ǵ�ģ��Ǿ�ֱ��β��
        return pre->next; //ͷ������һ�����Ƿ���ֵ��
    }
};