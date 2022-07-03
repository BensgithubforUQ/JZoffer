#include "Solution3.h"

//struct RandomListNode {
//	int label;
//	struct RandomListNode* next, * random;
//	RandomListNode(int x) :
//		label(x), next(NULL), random(NULL) {
//	}
//};

RandomListNode* Solution3::Clone(RandomListNode* pHead) {//JZ35 ��������ĸ���
    if (pHead == nullptr) return NULL;
    int size = 0;
    queue<int> randomPoint;
    queue<int> randomPosition;//Ҳ�����ù�ϣ������
    vector<RandomListNode*> newList;
    while (pHead != nullptr) {
        //cout << pHead->label << endl;
        RandomListNode* temp = new RandomListNode(0); //�ڱ���㣬���
        temp->label = pHead->label;
        newList.push_back(temp);
        if (pHead->random != nullptr) {
            randomPosition.push(size);
            randomPoint.push(pHead->random->label);
        }
        pHead = pHead->next;
        ++size;
    }
    cout << size << endl;
    for (int i = 0; i < size; i++) {
        if (i == size - 1) newList[i]->next = NULL;
        newList[i]->next = newList[i + 1];
        if (i == randomPosition.front()) {
            for (int j = 0; j < size; j++) {
                if (newList[j]->label == randomPoint.front()) {
                    newList[i]->random = newList[j];
                    randomPoint.pop();
                    break;
                }
            }
            randomPosition.pop();
        }
    }
    return newList[0];
}