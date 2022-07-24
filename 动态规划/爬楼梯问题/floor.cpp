#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param cost int����vector
     * @return int����
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