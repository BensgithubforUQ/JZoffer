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

void matrixMaxSum() {
    int n;
    cin >> n;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    if (n == 1) {
        cout << arr[0][0] << endl;
        return;
    }
    int res = INT_MIN; // - 2 31 
    for (int i = 0; i < n; i++) { 
        vector<int>sum(n, 0); //�е�ֵ���ۼӺ�
        for (int j = i; j < n; j++) {
            int temp = -127;
            for (int k = 0; k < n; k++) {
                sum[k] += arr[k][j]; //�ۼ��е�ֵ
                temp = max(temp + sum[k], sum[k]); //�ж�temp����һ���Ƿ���������һ�б�����������temp
                res = max(res, temp); //��ǰ���������һ���������temp�Ƚ�
            }
        }
    }
    cout << res << endl; //�������ֵ
}

void minPathMatrix() { //ע�⣬�������Ҫ����Сֵ����ɱ����ֵ�Ѷ���
    int  n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0)); //��ʼ��һ��
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    //int sum = arr[0][0];
    int i = 0, j = 0;
    for (i = n - 1, j = m - 1; j > 0; j--) arr[i][j - 1] += arr[i][j]; //���ȼ���λ�Ƶ��߽���Ψһ·����ֵ��Ϊdp
    for (i = n - 1, j = m - 1; i > 0; i--) arr[i - 1][j] += arr[i][j];
    if (n == 1 || m == 1) { //Ȼ���ж����������������Ϊһ���ߵ�ʱ�򣬴�ʱ�Ѿ��ó��𰸡�
        cout << arr[0][0] << endl;
        return;
    }
    for (i = n - 2; i >= 0; i--) //Ȼ��ʼ���ձ����
        //֮ǰ������Ǳ߽磬���ڰѱ߽��������������µı߽����С·��
        for (j = m - 2; j >= 0; j--)//Ҫô���Ҳ���ӣ�Ҫô���²���ӣ�����֮ǰ�õ��ı߽��dp�͵�ǰ��arr[i][j]���
            arr[i][j] += min(arr[i][j + 1], arr[i + 1][j]);
    //������֮�����վ͵õ�arr[0][0]��ֵ�����Ǿ���һ·����bp�õ���ֵ��
    cout << arr[0][0] << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}


int calculateHP(int a, int b) { //a�ǵ�ǰ���ӵĿ��ܿ۵�Ѫ�������߿��ܻص�Ѫ��
    //b���Ѿ�����õĵ�����һ����֮ǰ��Ҫ�����Ѫ��
    if (b > a) a = b - a;  //��ô�����ԣ����Ҫ���Ѫ���ȵ�ǰ���ӵ�ֵ��
    //�������ֿ��ܣ�һ���ǵ�ǰ���ӿ�Ѫ������ζ���ڵ�ǰ������Ҫb-a��Ѫ�����ܰ�ȫ�ɹ����������
    //�ڶ��ֿ����ǵ�ǰ�����ǻ�Ѫ����ͬ���ģ�����ζ����ֻ��Ҫb-a��Ѫ�����뵱ǰ���Ӿ��ܶɹ���������̣�������һ����
    else a = 1; //���ߣ�Ҫ���Ѫ���ȵ�ǰ���ӻ�Ѫ��Ѫ���٣�������ν�ˣ�ֻҪ�ڽ���ø���֮ǰ�㻹���ž��У�����Ϊ1
    return a;
}

void minHP() { //��������̺���һ���������С·�������ƣ�ֻ�����ȽϷ�������������һ���Ƿ��ܻ�
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    arr[n - 1][m - 1] = calculateHP(arr[n - 1][m - 1], 1);
    for (int i = n - 1, j = m - 1; i > 0; i--) {
        arr[i - 1][j] = calculateHP(arr[i - 1][j], arr[i][j]);
    }

    for (int i = n - 1, j = m - 1; j > 0; j--) {
        arr[i][j - 1] = calculateHP(arr[i][j - 1], arr[i][j]);
    }

    if (n - 1 == 1 || m - 1 == 1) {
        cout << arr[0][0];
        return;
    }
    for (int j = m - 2; j >= 0; j--)
        for (int i = n - 2; i >= 0; i--) {
            int right, down;
            right = calculateHP(arr[i][j], arr[i][j + 1]);
            down = calculateHP(arr[i][j], arr[i + 1][j]);
            arr[i][j] = min(right, down);
        }
    cout << arr[0][0] << endl;

}


void horseNextPos(int x, int y, vector<vector<long long>>& arr) {
    if (x >= 0 && y >= 0 && x < arr.size() && y < arr[0].size())
        arr[x][y] = -1;
}

long long countPath(long long left, long long up) {
    if (left > 0 && up > 0) return left + up;
    if (left < 0 && up < 0) return -1;
    return max(up, left);
}

void soldierCrossRivier() {
    int n, m;
    int x, y;
    cin >> n >> m >> x >> y;
    n = n + 1;
    m = m + 1;
    vector<vector<long long>> arr(n, vector<long long>(m, 0));
    horseNextPos(x, y, arr);
    horseNextPos(x + 2, y + 1, arr);
    horseNextPos(x + 1, y + 2, arr);
    horseNextPos(x - 1, y + 2, arr);
    horseNextPos(x - 2, y + 1, arr);
    horseNextPos(x - 2, y - 1, arr);
    horseNextPos(x - 1, y - 2, arr);
    horseNextPos(x + 1, y - 2, arr);
    horseNextPos(x + 2, y - 1, arr);
    for (int i = 0; i < n; i++) {
        if (arr[i][0] != -1)
            arr[i][0] = 1;
        if (i > 0)
            if (arr[i - 1][0] == -1)
                arr[i][0] = -1;
    }
    for (int j = 0; j < m; j++) {
        if (arr[0][j] != -1)
            arr[0][j] = 1;
        if (j > 0)
            if (arr[0][j - 1] == -1)
                arr[0][j] = -1;
    }
    if (n == 1 || m == 1) {
        cout << arr[n - 1][m - 1];
        return;
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++) {
            if (arr[i][j] == -1) continue;
            arr[i][j] = countPath(arr[i - 1][j], arr[i][j - 1]);
        }
    cout << arr[n - 1][m - 1];

}

void maxSubArrayAscend() { //�ص�֪ʶ��
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> res(n, 1);

    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                mx = max(mx, res[j]);
            }
        }
        res[i] = mx + 1;
    }
    int mx = 1;
    for (auto i : res)
        mx = max(mx, i);
    cout << mx;
}

void antiMissile_dp() { //���ص�������
    int n;
    cin >> n;
    vector<int>arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int>res(n, 1);
    for (int i = 1; i < n; i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (arr[i] <= arr[j]) {
                res[i] = max(res[j] + 1, mx);
            }
            mx = res[i];
        }
    }
    if (n == 0) {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, res[i]);
        res[i] = 1;
    }
    //for(auto i : res) cout<<i<<" ";
    int num = 0;
    for (int i = 1; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i]) {
                temp = max(res[j], temp);
            }
        }
        res[i] += temp;
        num = max(num, res[i]);
    }

    //cout<<endl;
    cout << mx << endl;
    cout << num << endl;
}