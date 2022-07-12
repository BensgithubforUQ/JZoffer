#include <iostream>
#include <vector>
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


    //��������ϲ����ܣ���Ϸ��η����������n������������кϲ�
    ListNode* mergeSort(vector<ListNode*>& lists, int begin_id, int end_id) {//�ݹ�Ĺ鲢�������壬��������
        if (begin_id == end_id) return lists[begin_id];

        int mid_id = (end_id - begin_id) / 2 + begin_id;
        ListNode* temp1 = mergeSort(lists, begin_id, mid_id);
        ListNode* temp2 = mergeSort(lists, mid_id + 1, end_id);
        ListNode* res = Merge(temp1, temp2); //�õ������ϲ���merge
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {//���������������������ݹ���ж�ĳЩ�������
        ///ListNode * head = new ListNode(INT_MIN);
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 0) return NULL;
        return mergeSort(lists, 0, lists.size() - 1);
    }

};