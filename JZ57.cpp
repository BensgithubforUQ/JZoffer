#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {//和为S的两个数字
        //标准做法只用头指针和尾指针左右逼近，但是这个升序数组，明显可以用二分法进一步加速查询
        int size = array.size();
        vector<int> res;
        for (int i = 0; i < size; i++) {
            int l = i + 1;
            int r = size - 1;
            int mid = (r + l) / 2;
            int diff = sum - array[i];
            while (l <= r) {
                mid = (r + l) / 2;
                if (array[mid] == sum - array[i]) {
                    break;
                }
                if (array[mid] < diff) l = mid + 1;
                if (array[mid] > diff) r = mid - 1;

            }
            if (array[mid] == sum - array[i]) {
                res.push_back(array[i]);
                res.push_back(array[mid]);
                break;
            }
        }
        return res;

    }
};