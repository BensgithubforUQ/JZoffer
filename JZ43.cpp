#include "Solution4.h"
//����һ������ n ���� 1��n �� n ��������ʮ���Ʊ�ʾ�� 1 ���ֵĴ���
//���磬 1~13 �а��� 1 �������� 1 �� 10 �� 11 �� 12 �� 13 ��˹����� 6 ��
//
//ע�⣺11 �������������
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int count = 0;
        for (int i = 1; i < n + 1; i++) {
            string str = to_string(i);
            cout << str << endl;
            int size = str.size();
            for (int j = 0; j < size; j++) {
                if (str[j] == '1') {
                    count++;
                }
            }
        }
    }
};

