#include<iostream>
#include<vector>
#include<set>
using namespace std;

//����n�����룬����������ȣ��ֱ�Ϊ m1, m2, m3��mn ��
//ÿ�������Ӧ������Ϊ x1, x2, x3...xn ������Ҫ����Щ����ȥ�����������(����ͬһ��)�����ܳƳ������ֲ�ͬ��������
//ע��
//������������ 0

//Ҳ�Ǳ������⣬Ҳ�ܼ򵥣�ֻ����������ǿ���������Ƕ��٣����ǲ鿴�ж�������������
//��Ȼ�����������ü򻯵ķ���ȥ����Ҳ�������棬���ҿ���ͨ���򻯵�����������ⱳ������ı��ʡ�
//��֮����̬�滮��˼����������Ѿ���¼��״̬�������㵱ǰ״̬�ķ�����
//ֻ����set�ķ����Ǹ�����һ��״̬�ķ���ֱ�� + weight�����㵱ǰ״̬�п��ܳ��ֵ������Ȼ����stlȥ��
//��ԭ��ּ����ı������������Ǳ������п����ԣ�sum+1)�У�������һ��״̬���жϵ�ǰ״̬�����п������Ƿ���ʵ�֡�
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
    //�������⣬ÿ��sum + 1�����ݣ���¼��0��sum���Ƿ�ɴ�
    //ÿ�� size�����ݣ����size��������������Ӧ����all_w�������������
    dp[0][0] = true; //���ȣ�ɶҲ���ſ϶��ǿ��Դﵽ��
    for (int i = 1; i < size + 1; i++) { //������������
        for (int j = 0; j < sum + 1; j++) { //������ǰ��
            if (all_w[i] > j) dp[i][j] = dp[i - 1][j]; //����ǰ�����ֵ�����ڣ���ǰ��̬�滮�������鵱ǰsum
            else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - all_w[i]];
            //������һ�㣬��û�иպô��� j - w�����ߣ��ɴ���һ���j�ʹ���
        }
    }
    //���������һ�������е�true���ǿ�����ɵ��������
    sum = 0;
    for (int i = 0; i < dp[size].size(); i++) {
        if (dp[size][i]) sum++;
    }
    //cout<<endl;
    cout << sum;
    return 0;
}

int weightSumCondition_EasyWay() { //��ʵ�ͱ���˼·һ����ֻ�������ֱ����set���������
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

    //����
    set<int> s;
    s.insert(0);
    for (int i = 0; i < n; i++) { //��������
        for (int j = 0; j < c[i]; j++) { //�������� ��������������ʵ���Ǳ��������еı��������뼯��
            set<int> t(s); //�����Ǹ�С���ɣ�����һ����ʱ��set������ǰһ��״̬
            for (auto k : t) { //Ȼ�����ǰһ��״̬�е������������s������µĿ�����
                s.insert(k + w[i]); //��Ϊ��set�����Ի��Զ�ȥ�ء�
            }
        }
    }

    cout << s.size(); //������set�Ĵ�С������
    return 0;
}