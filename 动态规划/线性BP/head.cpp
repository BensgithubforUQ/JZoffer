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


void maxSubArray() {
    int n;
    cin >> n;
    int temp;
    vector<int> arr;
    while (cin >> temp) arr.push_back(temp);
    int max = arr[0];
    int res = 0;
    //int l,r;
    for (int right = 0, left = 0; left < n; right++) {
        if (right == n) {
            right = ++left;
            res = arr[right];
            continue;
        }
        res += arr[right];
        if (arr[right] >= res) {
            left = right;
            res = arr[right];
        }
        if (res >= max) {
            max = res;
            //r = right;
            //l = left;
        }
    }
    cout << max << endl;
}


void maxSubArray_dp() { //��̬�滮�汾���������������������������
    int n;
    cin >> n;
    int temp;
    vector<int> arr;
    while (cin >> temp) arr.push_back(temp);
    int max = arr[0];
    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < n; i++) {
        int temp = dp[i - 1] + arr[i] > arr[i] ? dp[i - 1] + arr[i] : arr[i];
        dp.push_back(temp);
        max = max > dp[i] ? max : dp[i];
    }
    cout << max << endl;
}

void maxSubArrayMutil() {//��̬�滮�汾��������������������������˻�
    //�����ע�⣬��Ϊ�и����Ĵ��ڣ�����ֻ��¼���ֵû����
    //��Ҫ�����޴�Ĵ�����˫ָ���ж���һ���������Ķ��������鷳
    //��������ֱ���ٷ�һ����Сֵ������
    //��Сֵ�����Զ���ά����Сֵ������һ�Ը����ͻ��Զ�ȡ�������������������ͻ����һ�����ֵ������������
    //���ֵ���ϻ��Զ�ά�������������һ�Ը����ͻ�ѵڶ���������ǰһ����Сֵ��ˣ��������������ͻ��Զ�ȡ����  
    //�����������������������Сֵ���ϳ�������Ϊ������Сֵ���Ը��������������ֵ��
    int n;
    cin >> n;
    int temp;
    vector<int> arr;
    while (cin >> temp) arr.push_back(temp); //n��
    int res = arr[0];
    int max_dp = arr[0];
    int min_dp = arr[0];
    for (int i = 1; i < n; i++) {
        int max_temp = max_dp;
        int min_temp = min_dp;
        max_dp = max(max_temp * arr[i], max(arr[i], min_temp * arr[i]));
        min_dp = min(min_temp * arr[i], min(arr[i], max_temp * arr[i]));
        res = max(max_dp, res);
    }
    cout << res << endl;
}

void maxlength_subArrayPostive_multi() { //���֣�������������˻�Ϊ��������Ӵ�
    //�����Ŀӵ����ڣ��������ֵ�ܶ࣬���ҳ˻��ܴ��ǾͲ��ܼ򵥵��ó˷�������ж�������
    //�����������ʵ���ϳ˻���С������Ҫ����Ҫ��ֻ����������0������������ʱ���ҾͰ���ת���+-1��0�������Ͳ��ᳬ��int�ıȽϷ�Χ��
    int n;
    cin >> n;
    vector<int> arr;
    int temp;
    while (cin >> temp) {
        if (temp > 0) temp = 1;
        if (temp == 0) temp = 0;
        if (temp < 0) temp = -1;
        arr.push_back(temp);
    }
    int pos = 0, neg = 0, zero = 0;
    if (arr[0] > 0) pos = 1;
    if (arr[0] < 0) neg = 1;
    if (arr[0] == 0) zero = 1;
    int res = 0;
    int mx = arr[0];
    int mn = arr[0];
    for (int i = 1; i < n; i++) {
        //int max_t = max(mx*arr[i],max(arr[i],arr[i]*mn));
        //int min_t = min(mn*arr[i],min(arr[i],arr[i]*mx));
        //mx = max_t;
        //mn = min_t;
        mx *= arr[i];
        if (mx > 0) {
            if (neg != 0) pos = neg + 1; //�˻����Ϊ���������֮ǰ���Ǹ�������ֱ��++�����֮ǰ�Ǹ������Ǿ͸�������++
            else pos++;
            neg = 0;
        }
        if (mx < 0) {
            if (pos != 0) neg = pos + 1;//��̬�滮��˼�룬���˻����Ϊ������ʱ�򣬾Ͱ�֮ǰ�����ĳ���++
            else neg++;
            pos = 0;
        }
        if (mx == 0) {//������0��ʱ��������ζ��޷��˻������ˣ���˰�pos��neg����0��Ȼ��mx��ֵΪ1,
            //�����һ��ֵ��Ϊ0���ǾͿ��Լ����ж�mx�������������Ȼ��0�����ظ��˲��衣
            zero = 1;
            pos = 0;
            neg = 0;
            mx = 1;
        }
        res = res > pos ? res : pos;
    }
    cout << res << endl;
}


void circleArrayMaxSum() { //˼·�������ƣ������и��ŵĽⷨ���ٿ���һ����С�͵�ֵ
    int n;
    cin >> n;
    int temp;
    vector<int> arr;
    while (cin >> temp) arr.push_back(temp);
    for (int i = 0; i < n - 1; i++) arr.push_back(arr[i]); //˫���ĳ��ȣ��������һ��ֵ��
    int len = 1;
    int dp = arr[0];
    int mx = dp;
    for (int i = 1, j = 1; i < n; j++) {
        if (dp + arr[j] < arr[j]) {
            i = j; //iŲ�����������ֵ���ڹ�ȥֵ����ֵ����ȥΪ����
            dp = arr[j];
            len = 1;
        }
        else { //����ͼ���������Ȼ�����������鳤��
            dp += arr[j];
            len++;
        }
        mx = max(mx, dp);
        if (len == n) { //��������鳤�ȵ����������鳤�ȣ���˵���������鶼�����ˣ�i����
            i++;
            j = i;
            dp = arr[i];
            len = 1;

        }
    }
    cout << mx << endl;
}