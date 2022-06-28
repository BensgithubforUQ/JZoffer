#include<iostream>
#include<vector>
using namespace std;

class Solution { //53升序序列中，判断有几个值为k的数字，有序序列查找，第一个想到二分法。
public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty()) return 0;
        size_t n = data.size();
        int count = 0;
        int l = 0, r = data.size() - 1;
        for (; l <= r;) {
            int mid = (l + r) / 2;
            if (data[mid] > k) r = mid;
            if (data[mid] < k) l = mid;
            if (data[l] < k) ++l;
            if (data[r] > k) r--;
            if (data[l] == k && data[r] == k) {
                //std::cout << l << " " << r << std::endl;
                count = r - l + 1;
                break;
            }
        }
        return count;
    }
};