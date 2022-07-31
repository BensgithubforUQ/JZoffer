#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//这道题比较难想，但是实际上很简单，求每个滑动窗口中的最大值，用deque来暂时保存当前窗口中的最大值和次大值们
//把包含在 当前最大值被滑动出滑动窗口之前，判断该值是否比后来值更大，如果是，那就要判断后来值是否比两者中间的值更大
//如果是就pop掉没用的中间值，因为这些值不会是滑动窗口的最大值。
//如果后来值比当前最大值更大，则会连当前最大值也一起pop掉。
//deque中存的是最大值和次大值们的下标，这样就能根据当前后来值的下标判断deque头部的最大值是否被滑出滑动窗口，如果是，就pop掉。
vector<int> maxInWindows(const vector<int>& nums, int size) {
    vector<int> res;
    if (nums.empty() || size < 1 || nums.size() < size) return res;
    int n = nums.size();
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && nums[dq.back()] < nums[i])
            //当队列不为空，并且，队列末尾存储的位置在nums中的值小于nums[i]的时候
            dq.pop_back();//这种时候，意味着，这些值都是无用的，因为在往后滑动的过程中，这些都不会是最大值
        dq.push_back(i);
        if (dq.front() + size <= i)
            dq.pop_front(); //当队列头部的下标已经被滑过去了，pop
        if (i + 1 >= size) //形成了size大小的滑动窗口之后
            res.push_back(nums[dq.front()]); //开始向res里面push
    }
    return res;
}

//int main() {
//    return 0;
//}