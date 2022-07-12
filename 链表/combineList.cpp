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


    //利用这个合并功能，配合分治法，就能针对n个有序链表进行合并
    ListNode* mergeSort(vector<ListNode*>& lists, int begin_id, int end_id) {//递归的归并排序主体，用来分治
        if (begin_id == end_id) return lists[begin_id];

        int mid_id = (end_id - begin_id) / 2 + begin_id;
        ListNode* temp1 = mergeSort(lists, begin_id, mid_id);
        ListNode* temp2 = mergeSort(lists, mid_id + 1, end_id);
        ListNode* res = Merge(temp1, temp2); //用到两两合并的merge
        return res;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {//排序的主函数，用来进入递归和判断某些特殊情况
        ///ListNode * head = new ListNode(INT_MIN);
        if (lists.size() == 1) return lists[0];
        if (lists.size() == 0) return NULL;
        return mergeSort(lists, 0, lists.size() - 1);
    }

};