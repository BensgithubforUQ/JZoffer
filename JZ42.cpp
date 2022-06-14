#include "Solution4.h"
//输入一个长度为n的整型数组array，数组中的一个或连续多个整数组成一个子数组，子数组最小长度为1。求所有子数组的和的最大值。
//数据范围 : 1 - 2*10 5
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