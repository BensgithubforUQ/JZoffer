#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int>& prices) { //平平无奇的遍历
        // write code here
        if (prices.size() < 2) return 0;
        int maxP = 0;
        int min = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (min > prices[i]) {
                min = prices[i];
            }
            int temp = prices[i] - min;
            if (temp > maxP) maxP = temp;
        }
        return maxP;
    }
};