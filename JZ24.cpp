#include "Solution2.h"

ListNode23* Solution2::ReverseList(ListNode23* pHead) {//JZ24 ��ת����
	/*����һ���������ͷ���pHead(��ͷ�ڵ�����ֵ�ģ�
		��������ͼ������val��1)������Ϊn����ת������󣬷���������ı�ͷ��*/
    ListNode23* pre = nullptr;
    ListNode23* cur = pHead;
    ListNode23* nex = nullptr; // �������ָ��nullptr��ѭ������Ҫ����ָ��
    //null  1  2  3  4  5  6  7  null
    //pre  cur nex
    while (cur) {
        nex = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nex;
       /* int temp = x; //�ǻ����ķ�ת˼·
        x = y;
        y = temp;*/
    }
    return pre;
}