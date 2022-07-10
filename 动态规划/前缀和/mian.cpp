#include <iostream>
#include <vector>
#include <map>
using namespace std;

void sumOfLR() { //前缀和，注意观察数据范围 10的九次方，直接tm用long long
    int n, q;
    cin >> n;
    cin >> q;
    vector<long> arr(n, 0);
    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp; //dp思想，如果这里不用dp，后面就要遍历+时间复杂度直接*n

    }
    vector<pair<long, long>> res(q, pair<long, long>(0, 0));
    for (int i = 0; i < q; i++) {
        cin >> res[i].first;
        cin >> res[i].second;
    }

    for (int i = 0; i < q; i++) {
        long long temp = 0;
        if (res[i].first == 1) temp = arr[res[i].second - 1]; //用减法代替连加，节省时间复杂度、
        else temp = arr[res[i].second - 1] - arr[res[i].first - 2];
        cout << temp << endl;
    }
}


void twoDSum() { //二维的前缀和，思路一样的，只不过是多计算几步罢了。
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++) {
        long long temp;
        long long sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            sum += temp;
            arr[i][j] = sum;
            if (i > 0) arr[i][j] += arr[i - 1][j];
        }
    }


    for (int i = 0; i < q; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        long long xy1, xy2, xy3, xy4;
        if (x1 > 0 && y1 > 0) xy1 = arr[x1 - 1][y1 - 1];
        else xy1 = 0;
        if (x1 == 0) xy2 = 0;
        else xy2 = arr[x1 - 1][y2];
        if (y1 == 0) xy3 = 0;
        else xy3 = arr[x2][y1 - 1];
        long long sum = arr[x2][y2] - xy2 - xy3 + xy1;
        cout << sum << endl;
    }

}
void abb() { //前缀和第三题，算是复习一下map的用法，大概就是要用一个map记录数组中还剩多少数据。
    //每次遍历到一个数据之后，就遍历map，计算剩余的字符有多少可以和当前字符组成abb的
    //然后map中该字符的数量--;
    //到最后就可以求出总的abb数量了。
    //用map大幅度降低遍历所需要的时间成本。
    int n;
    cin >> n;
    vector<char> arr(n, ' ');
    map<char, int> res;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        res[arr[i]]++;
    }
    long long num = 0;
    for (auto i : arr) {
        for (auto j : res) {
            if (i != j.first && j.second > 1)
                num += (j.second - 1) * ((j.second - 1) + 1) / 2;
        }
        res[i]--;
    }
    cout << num << endl;
    //for(auto i : res){
        //cout<<i.first<<" "<<i.second<<endl;
    //}
}


//正数数组，m次操作，三个参数irk，把i到r的部分都加上k
//数据用long long

void elementAddK() { //差分问题，前缀和dp目的就是为了减少遍历成本
    int n, m;
    cin >> n >> m;
    vector<long long> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //数组初始化完毕
    vector<long long> dp(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int l, r;
        long long k;
        cin >> l >> r >> k;
        dp[l - 1] += k;  
        dp[r] -= k; 
    }
    for (int i = 1; i < n; i++) dp[i] += dp[i - 1]; //通过差分+前缀和，就可以用累加来简化遍历加
    for (int i = 0; i < n; i++) {
        cout << arr[i] + dp[i] << " ";
    }
}


void matrixAddK() { //模板方法，前缀和+差分，二位差分，这个画个图自算下，需要把左上角点和右下角点的右下角点设置为k
    //然后画个矩形，上左两个角设置成-k。
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m, 0));
    for (int i = 0; i < q; i++) {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;
        dp[x1 - 1][y1 - 1] += k;
        if (x2 < n && y2 < m) dp[x2][y2] += k;
        if (y2 < m) dp[x1 - 1][y2] -= k;
        if (x2 < n) dp[x2][y1 - 1] -= k;
    }
    for (int i = 0; i < n; i++)
        for (int j = 1; j < m; j++)
            dp[i][j] += dp[i][j - 1];

    for (int j = 0; j < m; j++)
        for (int i = 1; i < n; i++)
            dp[i][j] += dp[i - 1][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] + dp[i][j] << " ";
        }
        cout << endl;
    }
}
