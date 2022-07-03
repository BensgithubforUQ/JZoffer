#include "Solution2.h"

bool Solution2::match(string s, string p) {
    // write code here
    /*请实现一个函数用来匹配包括'.'和'*'的正则表达式。
        1.模式中的字符'.'表示任意一个字符
        2.模式中的字符'*'表示它前面的字符可以出现任意次（包含0次）。
        在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配*/
   //动态规划
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;//空串
    for (int j = 2; j <= n; j++) {
        //可以让自己前面个字符重复0次
        if (p[j - 1] == '*')//组合： ？（j-2），*（j-1）。
            dp[0][j] = dp[0][j - 2]; //与再前一个能够匹配空串有关
    }
    for (int i = 1; i <= m; i++) {   //遍历str每个长度
        for (int j = 1; j <= n; j++) {  //遍历pattern每个长度
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {  //当前字符不为*，用.去匹配或者字符直接相同
                dp[i][j] = dp[i - 1][j - 1];
            }  
            else if (p[j - 1] == '*') {//当前的字符为*
                if (j > 1) {
                    if (dp[i][j - 2]) dp[i][j] = true; //若是前一位为.或者前一位可以与这个数字匹配
                    else if (s[i - 1] == p[j - 2] || p[j - 2] == '.') {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
    }
    return dp[m][n];
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

