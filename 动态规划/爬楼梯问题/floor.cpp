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

    int dp_jumpFloor(int n) {  //���������bp
    //һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
    //    �����������һ�� n ����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������
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
        //0 + 1 + 2  ʵ���Ͼ�����ǰ���м�������Ľ����������һ����n
        //Ҳ��˵ǰ�����е�ֵ���ۼӣ��͵�����һ��ֵ
        //����ʵ���ϲ�����ʱ��ͻᷢ�֣���Ϊ��һ��ֵ������һ��ֵ֮ǰ���ۼ�
        //����������ֵֻ��Ҫ�ϸ�ֵ֮ǰ���ۼӣ��ӣ��ϸ�ֵ��Ҳ������һ��ֵ������������
        //����˵ 4 -> 1 + 2 + 4 + 1  = 8 ���� 4 + 4
        //��֮Ҳ�Ƕ�̬�滮
        for (int i = 3; i < n + 1; i++)
            res.push_back(res[i - 1] * 2);
        cout << res[n] << endl;
    }

    void jumpFloorCost() { //��̨�׵��������⣬���֮ǰ����̨�ף��������ÿ��̨�׵ļ�ֵ�����������¼�¾�����
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


    //��С������¥�ݣ�ÿ��¥����Ҫ֧�����۲�����ȥ��������ʹ�����¥��
    int minCostClimbingStairs(vector<int>& cost) { //��̨�׵��������⣬���֮ǰ����̨�ף��������ÿ��̨�׵ļ�ֵ�����������¼�¾�����
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