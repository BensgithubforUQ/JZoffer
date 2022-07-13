#include <iostream>
using namespace std;
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
            head = nex; //��׼�ķ�ת��ʽ
            nex = head->next;
            head->next = cur;
            cur = head;
        }
        start->next->next = nex;//ԭ��������->next ��������
        start->next = cur; //ԭ�����ص�  next<- ����ǰһ�����
        //ʵ�ַ�ת��
        return pre->next;
    }


    //��ת����ģ��3�������Ѷȵķ�ת��
    ListNode* reverse(ListNode* pre, int k) { //k������ĵߵ���pre-> k->next ��� pre->�ߵ����k->next; 
        if (pre == nullptr || pre->next == nullptr || k == 1) return pre;
        ListNode* start = pre; //���
        ListNode* head = pre->next;
        ListNode* cur = head; //��ǰ
        ListNode* nex = head->next; //��һ��
        ListNode* fast = pre; //˫ָ��
        for (int i = 0; i < k; i++) {
            if (fast->next != nullptr)
                fast = fast->next;//��ָ������k�����ж��Ƿ�����k�ı���
            else
                return nullptr; //���������k�����򷵻�null�������еߵ�
        }
        while (k > 1) { //����ʼ�ߵ�
            head = nex; //headŲ����һ��
            nex = head->next; //nexŲ����һ��
            head->next = cur; //head��nextָ��ǰһ��
            cur = head; //cur��¼�µ�
            k--; //k����һ��
        }
        start->next->next = nex; //ԭ����������һ��ָ��ԭ������ε����һ��Ԫ�ص���һ��
        ListNode* temp = start->next; //ԭ�������
        start->next = cur;
        if (temp->next) return temp; //��һ������Ҫ�ģ�����Ȼ���k == size���ᵼ������ѭ������
        else return nullptr; //����ߵ���֮�󣬷����µ�pre����һ�����ǿյģ���˵���պ�������񣬷���null
        //���������һ�����ᵼ�¸պõ��������ѭ����
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if (head == nullptr || head->next == nullptr || k == 1) return head;
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* res = pre;
        while (res) {
            res = reverse(res, k);
        }
        return pre->next;
    }


    bool isPail_supplementary(ListNode* head1, ListNode* head2) { //�ж��������Ƿ�Ϊ���Ľṹ�ĸ�������
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val != head2->val) return false;
            cout << head1->val << " " << head2->val << endl;
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }

    bool isPail(ListNode* head) {//������ָ�룬�ҵ��е�
        // write code here
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* fast = head->next->next;
        ListNode* mid = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            mid = mid->next;
            slow = slow->next;
        }
        slow->next = nullptr; //�԰�ָ�����
        head = ReverseList(head); //������һ����ת
        return (isPail_supplementary(head, mid) || isPail_supplementary(head, mid->next)); //��Ϊ����������������������һ���������
    }
};