#include<iostream>
#include<vector>
#include<set>
using namespace std;

//现有n种砝码，重量互不相等，分别为 m1, m2, m3…mn ；
//每种砝码对应的数量为 x1, x2, x3...xn 。现在要用这些砝码去称物体的重量(放在同一侧)，问能称出多少种不同的重量。
//注：
//称重重量包括 0

//也是背包问题，也很简单，只不过这个不是看最后最大的是多少，而是查看有多少种组合情况。
//当然，这个题可以用简化的方法去做，也放在下面，而且可以通过简化的这个深入的理解背包问题的本质。
//总之，动态规划的思想就是依靠已经记录的状态，来推算当前状态的方法。
//只不过set的方法是根据上一个状态的方法直接 + weight来推算当前状态中可能出现的情况，然后用stl去重
//而原教旨主义的背包方法，则是遍历所有可能性（sum+1)中，根据上一个状态来判断当前状态中所有可能性是否能实现。
int weightSumCondition() {
    int n;
    cin >> n;
    vector<int> w(n, 0);
    vector<int> c(n, 0);
    vector<int> all_w;
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> w[i];
    all_w.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i] * w[i];
        for (int j = 0; j < c[i]; j++) all_w.push_back(w[i]);
    }

    int size = all_w.size();
    vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));
    //背包问题，每行sum + 1个数据，记录从0到sum，是否可凑
    //每列 size个数据，这个size是总砝码数，对应的是all_w中砝码的索引。
    dp[0][0] = true; //首先，啥也不放肯定是可以达到的
    for (int i = 1; i < size + 1; i++) { //遍历砝码序列
        for (int j = 0; j < sum + 1; j++) { //遍历当前行
            if (all_w[i] > j) dp[i][j] = dp[i - 1][j]; //当当前砝码的值，大于，当前动态规划辅助数组当前sum
            else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - all_w[i]];
            //看看上一层，有没有刚好存在 j - w，或者，干脆上一层的j就存在
        }
    }
    //结束后，最后一行数据中的true就是可以组成的种类个数
    sum = 0;
    for (int i = 0; i < dp[size].size(); i++) {
        if (dp[size][i]) sum++;
    }
    //cout<<endl;
    cout << sum;
    return 0;
}

int weightSumCondition_EasyWay() { //其实和背包思路一样，只不过这个直接用set解决了问题
    int n;
    cin >> n;
    vector<int> w(n, 0);
    vector<int> c(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i] * w[i];
    }

    //处理
    set<int> s;
    s.insert(0);
    for (int i = 0; i < n; i++) { //遍历砝码
        for (int j = 0; j < c[i]; j++) { //遍历个数 这两步加起来其实就是背包方法中的遍历总砝码集合
            set<int> t(s); //这里是个小技巧，创建一个临时的set，拷贝前一个状态
            for (auto k : t) { //然后针对前一个状态中的所有情况，向s中添加新的可能性
                s.insert(k + w[i]); //因为是set，所以会自动去重。
            }
        }
    }

    cout << s.size(); //最后输出set的大小就行了
    return 0;
}