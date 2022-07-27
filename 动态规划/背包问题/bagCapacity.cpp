//������������
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


//���ﳵ���⣬m����Ʒ��nԪǮ��һ��������һ�ѱ�����������������ĸ�����ÿ����Ʒ������Ҫ�Ժͼ۸���Ҫ��*�۸� = ����ȣ����ܵõ�����������
void shoppingCart() {
    int n, m;
    cin >> n >> m; //n�Ǽ۸�m�ǿ��Թ������Ʒ������
    n /= 10;
    vector< vector<int>> prices(61, vector<int>(3, 0)); //���ܴ��ڵ����������������ļ۸�
    vector< vector<int>> satisfaction(61, vector<int>(3, 0)); //�����
    for (int i = 1; i <= m; i++) {
        int v, p, q;
        // ��ʾ����Ʒ�ļ۸� v<10000 ���� p ��ʾ����Ʒ����Ҫ�ȣ� 1 ~ 5 ���� q ��ʾ����Ʒ���������Ǹ�����
        //��� q=0 ����ʾ����ƷΪ��������� q>0 ����ʾ����ƷΪ������ q �����������ı��
        cin >> v >> p >> q;
        v /= 10;
        p *= v; //ֱ��ת��Ϊ�����
        if (q == 0) {
            prices[i][0] = v;
            satisfaction[i][0] = p;
        }
        else {
            if (prices[q][1] == 0) {//Ŀǰ������һ��λ���ǿճ�����
                prices[q][1] = v;
                satisfaction[q][1] = p;
            }
            else {
                prices[q][2] = v; //��Ŀ�趨ֻ�����һ��������
                satisfaction[q][2] = p;
            }
        }
    }

    //���벿����ϣ���ʼ��������
    vector< vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int p1 = prices[i][0], s1 = satisfaction[i][0];
            int p2 = prices[i][1], s2 = satisfaction[i][1];
            int p3 = prices[i][2], s3 = satisfaction[i][2];

            dp[i][j] = (j >= p1) ? max(dp[i - 1][j - p1] + s1, dp[i - 1][j]) : dp[i - 1][j];
            //�����ǰ��ʣ��Ǯ����������������Ʒ���ǾͿ����������Ʒ��ʱ����ͬ��Ǯ�������
            //���������Ʒ��ʱ�������ȣ��ĸ�����ѡ����ġ�
            //�������������Ǿ�ȡ�������������ֵ
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