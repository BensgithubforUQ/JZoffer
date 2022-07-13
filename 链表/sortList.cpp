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
    ListNode* oddEvenList(ListNode* head) {//将链表中的奇数位节点和偶数位节点分别提取出来，然后排列合并成一个新链表
        // write code here
        if (head == nullptr) return head;
        ListNode* pre1 = new ListNode(0);
        ListNode* pre2 = new ListNode(0);
        int num = 1;
        pre1->next = head;
        ListNode* newHead1 = pre1;
        ListNode* newHead2 = pre2;
        while (head) {
            if (num % 2) {//奇数
                newHead1 = head;
                head = head->next; //挪
            }
            else {
                newHead2->next = head;
                newHead2 = newHead2->next;
                newHead1->next = head->next;
                head = head->next;
                newHead2->next = nullptr; //这步要注意，挪过来之后就不能和原来的有关系了，直接切断。
            }
            num++;
        }
        newHead1->next = pre2->next;
        return pre1->next;
    }

    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) { //两个链表合成一个，就是新整个头结点，然后插入
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

    ListNode* sortInList(ListNode* head) {//单链表排序，不用额外的内存空间
        // write code here
        //分治法的终极应用，把一个链表，断成一堆结点，用归并排序的合并算法来排序
        if (head == NULL || head->next == NULL) return head; //片段为0或者1的时候就直接返回，开始合并
        ListNode* fast = head->next->next;
        ListNode* mid = head->next;
        ListNode* slow = head; //三个快慢指针找到归并排序分治的时候需要的中点

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            mid = mid->next;
            fast = fast->next->next;
        }

        //从中点断开
        slow->next = NULL;
        //然后就归并排序
        return Merge(sortInList(head), sortInList(mid)); //用递归实现分治法，然后返回的链表递归的合并。
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