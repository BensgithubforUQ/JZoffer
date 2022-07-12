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

    ListNode* removeNthFromEnd(ListNode* head, int n) { //����Ľ��װ汾
        // write code here
        if (n == 0) return head; //�����������������ط������Ǹ�0������ζ�ſ������һ���ж�����������ֱ�ӷ�����������
        //�������ֱ������д�ͺ�
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            if (fast) fast = fast->next;
            else return NULL;
        }
        if (fast) fast = fast->next; //��Ϊ��Ҫɾ����㣬�����Ҫ��ʵ�����ǵ���k+1������k�����������Ҫ����һλ
        else return slow->next; //���fast�Ѿ��ǿ��ˣ�����ζ������һ����k��ֵ�����صڶ����ڵ����
        while (fast) { //����ʼ����˫ָ��Ų�����ڣ�ֱ���ҵ�������k+1�����slow
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; //ɾ��������k�����
        return head;
    }

    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        //�����������˽�㣬�Ǿͷֱ�����ָ�뿪ʼ������������
        //�������˿�ʼ������һ������
        //��Щ����ͬ�����У��ҵ���ͬ�Ľ����ǵ�һ�����
        if (pHead1 == nullptr || pHead2 == nullptr) return NULL;
        ListNode* p1 = pHead1;
        ListNode* p2 = pHead2;
        while (p1 != p2) {//�����߼�ע��˳������ط������ж��Ƿ���ȣ�����Ϊ�����һ������ȣ����жϾͻ��Թ�
            if (p1)p1 = p1->next;//��һ����������Ų
            if (p2)p2 = p2->next;
            if (p1 == p2 && p1 == nullptr) return NULL;//Ų�������һ���ˣ����ǿգ���˵����û��һ����
            if (p1 == nullptr) p1 = pHead2; //����Ų��ͷ�ˣ�������һ��
            if (p2 == nullptr) p2 = pHead1;
        }
        return p1;//���͸�����ȷ�ġ�
    }
};