#include <iostream>

struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) { //������Ŀ ��ת����
        if (pHead == nullptr) return pHead;
        ListNode* pre = new ListNode(0); //����Ļ�λ����������preָ��ý��
        pre->next = pHead; 
        ListNode* temp = pHead->next;//����temp����¼��һ�����
        pHead->next = nullptr; //�ѵ�ǰ����next�ÿ�
        while (temp) { //temp��¼���ǵ�ǰ������һ����㣨ԭ��
            //temp��Ϊ�յ�ʱ�򣬱�û������
            pHead = temp; //��ǰ���������һ��λ��
            temp = pHead->next; //tempҲ��
            pHead->next = pre->next; //�ı�nextָ��ָ��pre��¼���ϸ�����λ��
            pre->next = pHead; //pre��¼��ǰ����λ��
        }//ѭ��
        return pre->next; //��󷵻�preָ�����һ����㣬Ҳ���ǵ�ǰ����λ�á�
        //Ҳ����ֱ�ӷ���pHead����ͬһ��ֵ��
    }


    ListNode* reverseBetween(ListNode* head, int m, int n) { //��ת����Ľ��ף�����ת����
        // write code here
        if (head == nullptr || head->next == nullptr || m == n) return head;
        ListNode* pre = new ListNode(0); //�����µ�����ͷ���������
        pre->val = 0;
        pre->next = head;

        int i = 0;
        ListNode* cur = pre;
        ListNode* nex = head;
        ListNode* start = pre;
        for (; i < m; i++) {
            if (i == m - 1) start = cur; //��¼��ʼ��ת��ǰһ�����ص�
            head = nex;
            nex = head->next;
            cur = head;
        }
        for (; i < n; i++) {
            head = nex;
            nex = head->next;
            head->next = cur;
            cur = head;
        }
        start->next->next = nex;
        start->next = cur;
        return pre->next;
    }
};