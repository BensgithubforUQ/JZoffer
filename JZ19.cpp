#include "Solution2.h"

bool Solution2::match(string str, string pattern) {
    // write code here
    /*请实现一个函数用来匹配包括'.'和'*'的正则表达式。
        1.模式中的字符'.'表示任意一个字符
        2.模式中的字符'*'表示它前面的字符可以出现任意次（包含0次）。
        在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/
   //动态规划
    int n1 = str.length();
    int n2 = str.length();
    //dp[i][j]
    vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true; //都为空串的时候，初始化为true
    for (int i = 2; i <= n2; i++) {
        if (pattern[i - 1] == '*') {
            dp[0][i] = dp[0][i - 1];
        }
    }
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (pattern[j - 1] != '*' && (pattern[j - 1] == '.' || pattern[j - 1] == str[i - 1])) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (j >= 2 && pattern[j - 1] == '*'){
                if (pattern[j - 2] == '.' || pattern[j - 2] == str[i - 1]) {
                    //转移情况
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }
                else {
                    //不匹配
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }

    return dp[n1][n2];
}

bool Solution2::match_core(string str, string pattern) {
    if (str.empty() && pattern.empty()) return true; //空串情况
    if (!str.empty() && pattern.empty()) return false;//实际串不为空，但是pattern为空
    if (pattern[1] == '*') {
        if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty())) {
            //当pattern和str目前的首字母相同，或者pattern首字母.，并且str不为空，则可以继续匹配
            return match_core(str.substr(1), pattern.substr(2)) || //第一种情况，str首字母和pattern的？*匹配,并且消耗掉？*
                match_core(str.substr(1), pattern) || //第二种情况，str首字母和？*匹配，但是没有消耗？*（复数情况）
                match_core(str, pattern.substr(2));//第三种情况，str的首字母虽然和？*匹配，但是并不消耗，也许？*后面一个还与之匹配
        }
        else {
            //否则，就匹配pattern == ‘*’，但是取了0个值的情况
            //这种情况下，就相当于直接跳过pattern中0和1两个字母
            return match_core(str, pattern.substr(2));
        }   
    }
    if (str[0] == pattern[0] || (pattern[0] == '.' && !str.empty())) {
        return match_core(str.substr(1), pattern.substr(1));
    }
    return false;//不符合上述情况，则不匹配
}

bool Solution2::match1(string str, string pattern) {
    return match_core(str, pattern);
}

