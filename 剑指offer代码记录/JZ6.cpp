#include "Solution.h"

vector<int> Solution::printListFromTailToHead(ListNode* head) {//JZ6 ��β��ͷ��ӡ����
	vector<int> v_initial;
	while (head != NULL) {//ע������жϣ��������ж���һ����
		v_initial.push_back(head->val);
		head = head->next;
	}
	reverse(v_initial.begin(),v_initial.end()); //stl��ת
	return v_initial;
}
