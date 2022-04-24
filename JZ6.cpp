#include "Solution.h"

vector<int> Solution::printListFromTailToHead(ListNode* head) {//JZ6 从尾到头打印链表
	vector<int> v_initial;
	while (head != NULL) {//注意这个判断，并不用判断下一个。
		v_initial.push_back(head->val);
		head = head->next;
	}
	reverse(v_initial.begin(),v_initial.end()); //stl反转
	return v_initial;
}
