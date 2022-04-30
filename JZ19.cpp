#include "Solution2.h"

bool Solution2::match(string str, string pattern) {
    // write code here
    /*��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
        1.ģʽ�е��ַ�'.'��ʾ����һ���ַ�
        2.ģʽ�е��ַ�'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
        �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��*/
   //��̬�滮
    int n1 = str.length();
    int n2 = str.length();
    //dp[i][j]
    vector<vector<bool> > dp(n1 + 1, vector<bool>(n2 + 1, false));
    dp[0][0] = true; //��Ϊ�մ���ʱ�򣬳�ʼ��Ϊtrue
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
                    //ת�����
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
                }
                else {
                    //��ƥ��
                    dp[i][j] = dp[i][j - 2];
                }
            }
        }
    }

    return dp[n1][n2];
}

bool Solution2::match_core(string str, string pattern) {
    if (str.empty() && pattern.empty()) return true; //�մ����
    if (!str.empty() && pattern.empty()) return false;//ʵ�ʴ���Ϊ�գ�����patternΪ��
    if (pattern[1] == '*') {
        if (pattern[0] == str[0] || (pattern[0] == '.' && !str.empty())) {
            //��pattern��strĿǰ������ĸ��ͬ������pattern����ĸ.������str��Ϊ�գ�����Լ���ƥ��
            return match_core(str.substr(1), pattern.substr(2)) || //��һ�������str����ĸ��pattern�ģ�*ƥ��,�������ĵ���*
                match_core(str.substr(1), pattern) || //�ڶ��������str����ĸ�ͣ�*ƥ�䣬����û�����ģ�*�����������
                match_core(str, pattern.substr(2));//�����������str������ĸ��Ȼ�ͣ�*ƥ�䣬���ǲ������ģ�Ҳ��*����һ������֮ƥ��
        }
        else {
            //���򣬾�ƥ��pattern == ��*��������ȡ��0��ֵ�����
            //��������£����൱��ֱ������pattern��0��1������ĸ
            return match_core(str, pattern.substr(2));
        }   
    }
    if (str[0] == pattern[0] || (pattern[0] == '.' && !str.empty())) {
        return match_core(str.substr(1), pattern.substr(1));
    }
    return false;//�����������������ƥ��
}

bool Solution2::match1(string str, string pattern) {
    return match_core(str, pattern);
}

