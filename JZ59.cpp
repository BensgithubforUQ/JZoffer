#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int max_pos = 0;
    int maxInArray(const vector<int>& dq, int pos, int size) { //改良版，不需要双向队列
        //记住，本题目实际上就是需要记录当前滑动窗口最大值的位置
        //下一个滑动窗口，如果没有滑过这个位置，那么新滑到的值只需要和最大值比较
        //如果滑过了这个位置，那就需要重新更新这个最大的位置，就是遍历一下这个滑动窗口，看看哪个值最大，然后记载这个位置
        int max = 0;
        for (auto i = dq.begin() + pos + 1; i != dq.end(); i++) {
            if (size == 0) break;
            //max = (*i) > max ? (*i) : max;
            if (*i > max) {
                max = *i;
                max_pos = i - dq.begin();
            }
            size--;
        }
        return max;
    }

    vector<int> maxInWindows(const vector<int>& nums, int size) {
        if (nums.size() == 1 || size == 1) return nums;
        vector<int> res;
        res.push_back(0);
        int max;

        for (int i = 0, j = 0; j < nums.size(); j++) {
            if (j - i < size) {
                if (res[0] < nums[j]) {
                    max_pos = j;
                    max = nums[j];
                }
                res[0] = max;
            }
            else {
                max = res[i];
                i++;
                if (j - max_pos >= size) {
                    if (max <= nums[j]) {
                        max_pos = j;
                        res.push_back(nums[j]);
                    }
                    else res.push_back(maxInArray(nums, max_pos, size));
                }
                else {
                    if (max <= nums[j]) {
                        max_pos = j;
                        res.push_back(nums[j]);
                    }
                    else res.push_back(max);
                }

            }
        }
        return res;
    }
};