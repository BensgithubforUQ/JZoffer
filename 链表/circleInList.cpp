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
    ListNode* FindKthToTail(ListNode* pHead, int k) { //����ָ���������ĺ�k�����
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

    ListNode* EntryNodeOfLoop_Hash(ListNode* pHead) { //���������еĻ�����ϣ������
        //�ж��ظ��������棬��ϣ��һֱ�Ǹ�����Ч�ķ���
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

    //���ǹ�ϣ���������Ҫʹ��stl�е�map�������˷ѿռ䲻˵��map�Ĳ�ѯҲ�˷�ʱ�䡣

    //���Ҳ�����ÿ���ָ�룬��ָ��һ����������ָ��һ����һ��
    //��ǻ����ֳ���Ϊm�������ֳ���Ϊc���������־��뻷���Ϊn
    //����ʱ����ָ������m+n����ʱ��ָ������2(m+n),�����㷨����ָ�����ˣ�m + c + n׷����ָ��
    //���c = m + n;
    //��ˣ���������ʱ�����ɳ�һ����ָ�룬�����ǽ������������

    ListNode* EntryNodeOfLoop_doublePointer(ListNode* pHead) {
        if (pHead->next == nullptr || pHead == nullptr) return NULL;
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        ListNode* late = pHead;
        bool flag = false;
        while (1) {
            if (fast->next) fast = fast->next; //��ָ���ߵıȽϿ죬��˿���ֻ�ÿ�ָ���ж��Ƿ��л�
            else break;
            if (fast->next) fast = fast->next;
            else break;
            slow = slow->next;
            if (flag) late = late->next;
            if (fast == slow) flag = true; //ֻҪfast == slow �����л������ҿ�������������ָ��
            if (late == slow) break; //�ڶ�����ָ��͵�һ����ָ�������ĵ�������
        }
        if (!flag) return NULL; //һЩ�жϣ���Ҫ����
        return late;
    }
};