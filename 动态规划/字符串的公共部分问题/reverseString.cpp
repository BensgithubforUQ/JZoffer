#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dp_decrypt(vector<vector<int>>& dp, int num, int size, string &str) { //回文串问题，不用双指针的做法。
    if (num == dp.size()-1) return; //递归结束条件
    //根据前两层的数据来推算
    int left = num / 2;
    int right = num / 2;
    if (num % 2 == 1) {
        //奇数层
    }
    if (num % 2 == 0) {
        //偶数层
        left -= 1;
    }
    for (int i = 0; i < dp[num - 2].size(); i++) { //其实就是维护一个二维数组，数组里面存的是string的索引
        if (dp[num - 2][i] - left >= 0 && dp[num - 2][i] + right < size) {
            if (str[dp[num - 2][i] - left] == str[dp[num - 2][i] + right]) //每次读取前前层的索引，然后判断对应的位置的俩值是否一样
                dp[num].push_back(dp[num - 2][i]); //如果一样，那就存到本层里面
        }
    }
    dp_decrypt(dp, num+1, size, str); //结束之后继续往更深的地方遍历
}

//int main() {
//    string str;
//    cin >> str;
//    vector<vector<int>> dp(str.size() + 1, vector<int>(0));
//    if (str.size() == 1)  cout << 1 << endl;
//    else {
//
//        int num = 0;
//        for (auto i : str) {
//            dp[1].push_back(num);
//            if (num + 1 < str.size())
//                if (str[num] == str[num + 1])
//                    dp[2].push_back(num);
//            num++;
//        }
//        dp_decrypt(dp, 3, str.size(), str);
//    }
//    for (auto i : dp) {
//        for (auto j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}