#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param cost int整型vector
     * @return int整型
     */
    int minCostClimbingStairs(vector<int>& cost) {
        // write code here
        vector<int> dp(2);
        dp[0] = cost[0];
        dp[1] = cost[1];
        int size = cost.size();
        for (int i = 2; i < size; i++) {
            dp.push_back(cost[i]);
            dp[i] = min(dp[i - 1] + dp[i], dp[i - 2] + dp[i]);
        }
        return min(dp[size - 1], dp[size - 2]);
    }
};