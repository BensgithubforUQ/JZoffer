#include "head.h"

void fib() { //斐波拉契数列
    vector<int> res;
    res.push_back(1); //1
    res.push_back(1); //2
    int n;
    cin >> n;
    if (n <= 2) cout << 1 << endl;
    else {
        for (int i = 2; i < n; i++) //>2的情况
            res.push_back(res[i - 1] + res[i - 2]);
        cout << res[n - 1] << endl;
    }
}




void binarySearchTreeCount() {
    //简单来说，利用之前的结果，设置成左右树，然后统计总和。
    // j -1 + i - j = i -1.少一个结点是因为有个结点在根节点。
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


void maxSubArray_dp() { //动态规划版本，计算数组中子数组最大连续和
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

void maxSubArrayMutil() {//动态规划版本，计算数组中子数组最大连续乘积
    //这个题注意，因为有负数的存在，所以只记录最大值没有用
    //需要付出巨大的代价用双指针判断下一个负数在哪儿，还很麻烦
    //所以这里直接再放一个最小值进来。
    //最小值集会自动的维持最小值，遇到一对负数就会自动取负数，遇到单个负数就会把上一个最大值和这个负数相乘
    //最大值集合会自动维持最大做，遇到一对负数就会把第二个负数和前一个最小值相乘，遇到单个负数就会自动取负数  
    //遇到负数的情况，就整个最小值集合出来，因为负数最小值乘以负数就是整数最大值。
    int n;
    cin >> n;
    int temp;
    vector<int> arr;
    while (cin >> temp) arr.push_back(temp); //n个
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

void maxlength_subArrayPostive_multi() { //变种，这道题求连续乘积为整数的最长子串
    //这道题的坑点在于，他输入的值很多，而且乘积很大，那就不能简单的用乘法结果来判断正负。
    //而这道题里面实际上乘积大小并不重要，重要的只有正负或者0，因此在输入的时候我就把他转变成+-1和0，这样就不会超出int的比较范围了
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
            if (neg != 0) pos = neg + 1; //乘积结果为正数，如果之前不是负数，那直接++，如果之前是负数，那就负数长度++
            else pos++;
            neg = 0;
        }
        if (mx < 0) {
            if (pos != 0) neg = pos + 1;//动态规划的思想，当乘积结果为负数的时候，就把之前正数的长度++
            else neg++;
            pos = 0;
        }
        if (mx == 0) {//当出现0的时候，无论如何都无法乘积得正了，因此把pos和neg都赋0，然后mx赋值为1,
            //如果下一个值不为0，那就可以继续判断mx的正负，如果依然是0，则重复此步骤。
            zero = 1;
            pos = 0;
            neg = 0;
            mx = 1;
        }
        res = res > pos ? res : pos;
    }
    cout << res << endl;
}


void circleArrayMaxSum() { //思路还是类似，但是有更优的解法，再考虑一个最小和的值
    int n;
    cin >> n;
    int temp;
    vector<int> arr;
    while (cin >> temp) arr.push_back(temp);
    for (int i = 0; i < n - 1; i++) arr.push_back(arr[i]); //双倍的长度，除了最后一个值。
    int len = 1;
    int dp = arr[0];
    int mx = dp;
    for (int i = 1, j = 1; i < n; j++) {
        if (dp + arr[j] < arr[j]) {
            i = j; //i挪动的情况，新值大于过去值加新值，过去为负。
            dp = arr[j];
            len = 1;
        }
        else { //否则就继续遍历，然后增加子数组长度
            dp += arr[j];
            len++;
        }
        mx = max(mx, dp);
        if (len == n) { //如果子数组长度等于输入数组长度，则说明整个数组都遍历了，i右移
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
        vector<int>sum(n, 0); //行的值的累加和
        for (int j = i; j < n; j++) {
            int temp = -127;
            for (int k = 0; k < n; k++) {
                sum[k] += arr[k][j]; //累加行的值
                temp = max(temp + sum[k], sum[k]); //判断temp加下一行是否更大，如果下一行本身更大，则更新temp
                res = max(res, temp); //当前结果就是上一个最大结果和temp比较
            }
        }
    }
    cout << res << endl; //输出最大的值
}

void minPathMatrix() { //注意，这个题是要找最小值，这可比最大值难多了
    int  n, m;
    cin >> n;
    cin >> m;
    vector<vector<int>> arr(n, vector<int>(m, 0)); //初始化一波
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    //int sum = arr[0][0];
    int i = 0, j = 0;
    for (i = n - 1, j = m - 1; j > 0; j--) arr[i][j - 1] += arr[i][j]; //首先计算位移到边界后的唯一路径的值作为dp
    for (i = n - 1, j = m - 1; i > 0; i--) arr[i - 1][j] += arr[i][j];
    if (n == 1 || m == 1) { //然后判断特殊情况，当矩阵为一条线的时候，此时已经得出答案。
        cout << arr[0][0] << endl;
        return;
    }
    for (i = n - 2; i >= 0; i--) //然后开始看普遍情况
        //之前计算的是边界，现在把边界往内缩，计算新的边界的最小路径
        for (j = m - 2; j >= 0; j--)//要么和右侧相加，要么和下侧相加，利用之前得到的边界的dp和当前的arr[i][j]相加
            arr[i][j] += min(arr[i][j + 1], arr[i + 1][j]);
    //遍历完之后，最终就得到arr[0][0]的值，就是经过一路线性bp得到的值。
    cout << arr[0][0] << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}


int calculateHP(int a, int b) { //a是当前格子的可能扣的血量，或者可能回的血量
    //b是已经计算好的到达下一个点之前需要的最低血量
    if (b > a) a = b - a;  //那么很明显，如果要求的血量比当前格子的值大
    //则有两种可能，一种是当前格子扣血，那意味着在当前格子需要b-a的血量才能安全渡过后面的流程
    //第二种可能是当前格子是回血，那同样的，这意味着你只需要b-a的血量进入当前格子就能渡过后面的流程，所以是一样的
    else a = 1; //或者，要求的血量比当前格子回血的血量少，那无所谓了，只要在进入该格子之前你还活着就行，设置为1
    return a;
}

void minHP() { //后面的流程和上一个问题的最小路径和类似，只不过比较方法额外增加了一个是否能活
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

void maxSubArrayAscend() { //重点知识。
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

void antiMissile_dp() { //拦截导弹问题
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


void smallBigSmall() { //合唱团峰形排队问题，去掉几个人可以形成峰形
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //所谓的合唱团，就是要左变边的都小于，右边的都大于。
    //也就是求目标点的左侧是最大升序，右边是最大降序
    vector<int> ascend(n, 0);
    vector<int> descend(n, 0);
    ascend[0] = 1;
    descend[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i])
                temp = max(temp, ascend[j]); //temp是比较的最大值
        }
        ascend[i] = temp + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        int temp = 0;
        for (int j = n - 1; j > i; j--) {
            if (arr[j] < arr[i])
                temp = max(temp, descend[j]); //temp是比较的最大值
        }
        descend[i] = temp + 1;
    }
    int mx = 0;

    for (int i = 0; i < n; i++) {
        mx = max(mx, ascend[i] + descend[i] - 1);
    }
    //cout<<mx<<endl;
    cout << n - mx << endl;
    //for(auto i:ascend) cout<<i<<" ";
    //cout<<endl;
    //for(auto i:descend) cout<<i<<" ";
}

void envelopes() { //这个题我觉得答案错了，我考虑的这个更周到。
    //题解没有考虑长宽互换的情况，我这个考虑到了，所以答案有可能会比题解得到的答案多一点。
    int n;
    cin >> n;
    vector<pair<int, int>> enve(n, pair<int, int>(0, 0));
    for (int i = 0; i < n;
        i++) { //在这个阶段就处理下数据吧，first小，second大
        int big, small;
        cin >> big;
        cin >> small;
        if (big < small) {
            int temp = big;
            big = small;
            small = temp;
        }
        enve[i].first = small;
        enve[i].second = big;
    }
    //这波完了之后，还得进行一个排序，不然不好比较
    //先排序first，然后根据second再排，都是降序
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (enve[i].first < enve[j].first) {
                auto temp = enve[i];
                enve[i] = enve[j];
                enve[j] = temp;
            }
            if (enve[i].first == enve[j].first) {
                if (enve[i].second < enve[j].second) {
                    auto temp = enve[i];
                    enve[i] = enve[j];
                    enve[j] = temp;
                }
            }
        }
    }
    vector<int>res(n, 1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (enve[i].first < enve[j].first && enve[i].second < enve[j].second) {
                //小值小，大值也小，才算数
                res[i] = max(res[i], res[j] + 1);
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        //cout << res[i] << " ";
        mx = max(mx, res[i]);
    }
    //cout << endl;
    cout << mx;
}


string LCS(string s1, string s2) { //BM65 最长公共子序列(二)
    //给定两个字符串str1和str2，输出两个字符串的最长公共子序列。
    // 如果最长公共子序列为空，则返回"-1"。目前给出的数据，仅仅会存在一个最长的公共子序列
    // write code here
    int len1 = s1.size();
    int len2 = s2.size();
    vector<string> res(len2 + 1, ""); //用于dp记录最长子序列
    for (int i = 1; i <= len1; i++) { //遍历子串1
        string pre = "";
        for (int j = 1; j <= len2; j++) { //遍历子串2
            string temp = res[j];  //取得当前dp中记录的当前点位的最长子串
            if (s1[i - 1] == s2[j - 1]) res[j] = pre + s1[i - 1]; //如果当前值相等则当前dp后面添加该值
            else res[j] = (res[j].size() > res[j - 1].size() ? res[j] : res[j - 1]);
            ////如果不不相等，则比较当前值和前一个值哪个更大，如果相同大小，则用前面的覆盖。
            //覆盖的理由是，因为大小相同的情况，res前面的说明相同的点比当前的出现的更早，可以形成更大长的子序列
            pre = temp; //完毕后记录原本的res[j];
        }
    }
    if (res[len2] == "") return res[len2] = "-1";
    else return res[len2];
}