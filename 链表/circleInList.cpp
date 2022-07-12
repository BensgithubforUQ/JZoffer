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

    ListNode* EntryNodeOfLoop_Hash(ListNode* pHead) { //返回链表中的环，哈希表做法
        //判断重复问题里面，哈希表一直是个简单有效的方法
        map<ListNode*, int> nodeMap;
        while (pHead != NULL && pHead->next != NULL) {
            nodeMap[pHead]++;
            if (nodeMap[pHead] == 2) {
                return pHead;
            }
            pHead = pHead->next;

        }
        return NULL;
    }

    //但是哈希表的做法需要使用stl中的map容器，浪费空间不说，map的查询也浪费时间。

    //因此也建议用快慢指针，快指针一次走两格，慢指针一次走一格
    //设非环部分长度为m，环部分长度为c，相遇部分距离环起点为n
    //相遇时，慢指针走了m+n，此时快指针走了2(m+n),换种算法，快指针走了，m + c + n追上慢指针
    //因此c = m + n;
    //因此，在相遇的时候，再派出一个慢指针，那他们将会在起点相遇

    ListNode* EntryNodeOfLoop_doublePointer(ListNode* pHead) {
        if (pHead->next == nullptr || pHead == nullptr) return NULL;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        ListNode* late = pHead;
        bool flag = false;
        while (1) {
            if (fast->next) fast = fast->next; //快指针走的比较快，因此可以只用快指针判断是否有环
            else break;
            if (fast->next) fast = fast->next;
            else break;
            slow = slow->next;
            if (flag) late = late->next;
            if (fast == slow) flag = true; //只要fast == slow 就是有环，并且可以启动二个慢指针
            if (late == slow) break; //第二个慢指针和第一个慢指针相遇的点就是起点
        }
        if (!flag) return NULL; //一些判断，不要忘记
        return late;
    }
};