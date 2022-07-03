#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     *
     * @param prices int����vector
     * @return int����
     */
    int maxProfit(vector<int>& prices) { //ƽƽ����ı���
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