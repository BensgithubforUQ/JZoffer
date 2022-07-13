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
    ListNode* oddEvenList(ListNode* head) {//�������е�����λ�ڵ��ż��λ�ڵ�ֱ���ȡ������Ȼ�����кϲ���һ��������
        // write code here
        if (head == nullptr) return head;
        ListNode* pre1 = new ListNode(0);
        ListNode* pre2 = new ListNode(0);
        int num = 1;
        pre1->next = head;
        ListNode* newHead1 = pre1;
        ListNode* newHead2 = pre2;
        while (head) {
            if (num % 2) {//����
                newHead1 = head;
                head = head->next; //Ų
            }
            else {
                newHead2->next = head;
                newHead2 = newHead2->next;
                newHead1->next = head->next;
                head = head->next;
                newHead2->next = nullptr; //�ⲽҪע�⣬Ų����֮��Ͳ��ܺ�ԭ�����й�ϵ�ˣ�ֱ���жϡ�
            }
            num++;
        }
        newHead1->next = pre2->next;
        return pre1->next;
    }

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) { //��������ϳ�һ��������������ͷ��㣬Ȼ�����
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

    ListNode* sortInList(ListNode* head) {//���������򣬲��ö�����ڴ�ռ�
        // write code here
        //���η����ռ�Ӧ�ã���һ�������ϳ�һ�ѽ�㣬�ù鲢����ĺϲ��㷨������
        if (head == NULL || head->next == NULL) return head; //Ƭ��Ϊ0����1��ʱ���ֱ�ӷ��أ���ʼ�ϲ�
        ListNode* fast = head->next->next;
        ListNode* mid = head->next;
        ListNode* slow = head; //��������ָ���ҵ��鲢������ε�ʱ����Ҫ���е�

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            mid = mid->next;
            fast = fast->next->next;
        }

        //���е�Ͽ�
        slow->next = NULL;
        //Ȼ��͹鲢����
        return Merge(sortInList(head), sortInList(mid)); //�õݹ�ʵ�ַ��η���Ȼ�󷵻ص�����ݹ�ĺϲ���
    }
};

//int main() {
//    ListNode* pre = new ListNode(6);
//    ListNode* head = new ListNode(5);
//    pre->next = head;
//    for (int i = 0; i < 4; i++) {
//        ListNode* node = new ListNode(4 - i);
//        head->next = node;
//        head = node;
//    }
//    Solution s;
//    ListNode* res = s.sortInList(pre);
//
//
//    while (res) {
//        cout << res->val << " ";
//        res = res->next;
//    }
//    return 0;
//}