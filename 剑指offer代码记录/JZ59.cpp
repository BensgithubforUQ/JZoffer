#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int max_pos = 0;
    int maxInArray(const vector<int>& dq, int pos, int size) { //�����棬����Ҫ˫�����
        //��ס������Ŀʵ���Ͼ�����Ҫ��¼��ǰ�����������ֵ��λ��
        //��һ���������ڣ����û�л������λ�ã���ô�»�����ֵֻ��Ҫ�����ֵ�Ƚ�
        //������������λ�ã��Ǿ���Ҫ���¸����������λ�ã����Ǳ���һ������������ڣ������ĸ�ֵ���Ȼ��������λ��
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