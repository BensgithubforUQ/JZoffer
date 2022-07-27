//背包容量问题
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


//购物车问题，m个物品，n元钱，一堆主件，一堆必须买了主件才能买的附件，每个商品都有重要性和价格，重要性*价格 = 满意度，求能得到的最大满意度
void shoppingCart() {
    int n, m;
    cin >> n >> m; //n是价格，m是可以购买的物品的数量
    n /= 10;
    vector< vector<int>> prices(61, vector<int>(3, 0)); //可能存在的主件和两个附件的价格
    vector< vector<int>> satisfaction(61, vector<int>(3, 0)); //满意度
    for (int i = 1; i <= m; i++) {
        int v, p, q;
        // 表示该物品的价格（ v<10000 ）， p 表示该物品的重要度（ 1 ~ 5 ）， q 表示该物品是主件还是附件。
        //如果 q=0 ，表示该物品为主件，如果 q>0 ，表示该物品为附件， q 是所属主件的编号
        cin >> v >> p >> q;
        v /= 10;
        p *= v; //直接转化为满意度
        if (q == 0) {
            prices[i][0] = v;
            satisfaction[i][0] = p;
        }
        else {
            if (prices[q][1] == 0) {//目前附件第一个位置是空出来的
                prices[q][1] = v;
                satisfaction[q][1] = p;
            }
            else {
                prices[q][2] = v; //题目设定只有最多一到俩附件
                satisfaction[q][2] = p;
            }
        }
    }

    //输入部分完毕，开始处理数据
    vector< vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int p1 = prices[i][0], s1 = satisfaction[i][0];
            int p2 = prices[i][1], s2 = satisfaction[i][1];
            int p3 = prices[i][2], s3 = satisfaction[i][2];

            dp[i][j] = (j >= p1) ? max(dp[i - 1][j - p1] + s1, dp[i - 1][j]) : dp[i - 1][j];
            //如果当前还剩的钱，可以买得起这个物品。那就看不买这个物品的时候相同价钱的满意度
            //和买这件物品的时候的满意度，哪个更大，选更大的。
            //如果买不起这个，那就取不买这个东西的值
            dp[i][j] = (j >= (p1 + p2)) ? max(dp[i - 1][j - p1 - p2] + s1 + s2, dp[i][j]) : dp[i][j];
            dp[i][j] = (j >= (p1 + p3)) ? max(dp[i - 1][j - p1 - p3] + s1 + s3, dp[i][j]) : dp[i][j];
            dp[i][j] = (j >= (p1 + p2 + p3)) ? max(dp[i - 1][j - p1 - p2 - p3] + s1 + s2 + s3, dp[i][j]) : dp[i][j];

        }
    }
    cout << dp[m][n] * 10;
}

class A {
    virtual void test() = 0;
private:
    int a;
    char b;
};

class B:public A{
    virtual void test();
    virtual void test1() {};
private:
    int a;
    int b;
    char e;
};

void B::test() {

}

class  C :public B {
    void test(){};
    virtual void test1() {};
    virtual void test2() {};
private:
    int a;
    int b;
    char e;
};
int main() {
    //A a;
    B b;
    C c;
    cout <<  " " << sizeof(b)<<" "<<sizeof(c);
    return 0;
}