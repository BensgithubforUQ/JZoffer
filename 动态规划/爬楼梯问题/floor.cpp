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

    int dp_jumpFloor(int n) {  //经典的线性bp
    //一只青蛙一次可以跳上1级台阶，也可以跳上2级。
    //    求该青蛙跳上一个 n 级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
    //1,2
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int res = dp_jumpFloor(n - 2) + dp_jumpFloor(n - 1);
        return res;
    }

    void jumpFloor() {
        vector<int> res;
        int n;
        cin >> n;
        res.push_back(1); //0
        res.push_back(1); //1
        res.push_back(2); //2
        for (int i = 3; i < n + 1; i++) {
            res.push_back(dp_jumpFloor(i));
        }
        cout << res[n] << endl;
    }

    void jumpFloorExtra() {
        int n;
        cin >> n;
        vector<int> res;
        res.push_back(1); //0
        res.push_back(1); //1
        res.push_back(2); //2 
        //res.push_back(4); //3  
        //0 + 1 + 2  实际上就是以前所有计算出来的结果，都可以一步到n
        //也就说前面所有的值的累加，就等于下一个值
        //但是实际上操作的时候就会发现，因为上一个值就是上一个值之前的累加
        //因此现在这个值只需要上个值之前的累加，加，上个值，也就是上一个值的两倍。。。
        //比如说 4 -> 1 + 2 + 4 + 1  = 8 就是 4 + 4
        //总之也是动态规划
        for (int i = 3; i < n + 1; i++)
            res.push_back(res[i - 1] * 2);
        cout << res[n] << endl;
    }

    void jumpFloorCost() { //跳台阶的消耗问题，相比之前的跳台阶，额外加了每个台阶的键值，整个数组记录下就完了
        int n, temp;
        vector<int> floor;
        vector<int> cost;
        cin >> n;
        while (cin >> temp)
            floor.push_back(temp);
        cost.push_back(floor[0]);
        cost.push_back(floor[1]);
        for (int i = 2; i < n; i++) {
            cost.push_back(floor[i] + min(cost[i - 2], cost[i - 1]));
        }
        cout << min(cost[n - 1], cost[n - 2]) << endl;
    }


    //最小花费爬楼梯，每个楼梯需要支付代价才能上去，计算最低代价上楼顶
    int minCostClimbingStairs(vector<int>& cost) { //跳台阶的消耗问题，相比之前的跳台阶，额外加了每个台阶的键值，整个数组记录下就完了
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