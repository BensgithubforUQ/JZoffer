#include "Solution4.h"
//����һ������Ϊn����������array�������е�һ������������������һ�������飬��������С����Ϊ1��������������ĺ͵����ֵ��
//���ݷ�Χ : 1 - 2*10 5
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.size() == 0) return NULL;
        if (array.size() == 1) return array[0];

        int max = array[0];
        int premax = max;
        for (int i = 1; i < array.size(); i++) {
            int newmax = array[i] + premax;
            if (newmax > array[i]) { //premax > 0
                premax = newmax;
            }
            else { //premax < 0
                premax = array[i];
            }
            if (premax > max) {
                max = premax;
            }
        }
        return max;
    }
};