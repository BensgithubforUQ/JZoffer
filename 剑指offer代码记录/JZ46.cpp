#include "Solution4.h"
//
//有一种将字母编码成数字的方式：'a'->1, 'b->2', ..., 'z->26'。
//我们把一个字符串编码成一串数字，再考虑逆向编译成字符串。
//由于没有分隔符，数字编码成字母可能有多种编译结果，例如 11 既可以看做是两个 'a' 也可以看做是一个 'k' 。
//但 10 只可能是 'j' ，因为 0 不能编译成任何结果。
//现在给一串数字，返回有多少种可能的译码结果
class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        vector<int> dp(nums.size() + 1, 1);
        if (nums == "0") return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == '0' && (nums[i - 1] != '1' && nums[i - 1] != '2')) {
                return 0;
            }
            if (nums[i] >= '0' && nums[i] <= '9') {
                dp[i + 1] = dp[i];
            }
            if ((nums[i - 1] == '1' && nums[i] > '0') || (nums[i - 1] == '2' && nums[i] < '7' && nums[i]>'0')) {
                dp[i + 1] = dp[i] + dp[i - 1];
            }
        }
        return dp[nums.size()];
    }
};