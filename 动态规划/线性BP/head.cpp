#include "head.h"

void fib() { //쳲���������
    vector<int> res;
    res.push_back(1); //1
    res.push_back(1); //2
    int n;
    cin >> n;
    if (n <= 2) cout << 1 << endl;
    else {
        for (int i = 2; i < n; i++) //>2�����
            res.push_back(res[i - 1] + res[i - 2]);
        cout << res[n - 1] << endl;
    }
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

void binarySearchTreeCount() {
    //����˵������֮ǰ�Ľ�������ó���������Ȼ��ͳ���ܺ͡�
    // j -1 + i - j = i -1.��һ���������Ϊ�и�����ڸ��ڵ㡣
    int n;
    cin >> n;
    vector<int> count;
    count.push_back(1); //0
    count.push_back(1); //1;
    count.push_back(2); // 1 2 ,2 1
    for (int i = 3; i < n + 1; i++) {
        count.push_back(0);
        for (int j = 1; j <= i; j++)
            count[i] += count[j - 1] * count[i - j];
    }
    cout << count[n] << endl;
}
