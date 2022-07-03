#include "Solution2.h"

ListNode_JZ18* Solution2::deleteNode(ListNode_JZ18* head, int val) {
	//单向链表，因此需要同时取前中后三个节点才能完成寻值和删除操作
	if (head->val == val) {
		return head->next; //直接返回第二个位置
	}
	auto head0 = new ListNode_JZ18(-1); //创建一个新的头结点
	head0->next = head; //新的头结点指向输入的头结点
	auto pre = head0; //因为head要作为遍历的结点使用，pre就是head的前一个结点，在这里和新头结点内容一致。
	while (head) { //当head不为空，则不是最后一个
		if (head->val == val) { 
			//如果head的val和输入的val一样，那pre的下一个结点就改变为head的下一个结点。
			pre->next = head->next;
			//直接return根节点的next结点
			return head0->next;
		}
		else {
			//如果val不一样，那head就挪下一个，pre也挪下一个(变成head)
			pre = head;
			head = head->next;
		}
	}
	return head0->next;//最终输出head0的next结点
}