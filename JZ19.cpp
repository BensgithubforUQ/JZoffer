#include "Solution2.h"

bool Solution2::match(string s, string p) {
    // write code here
    /*��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
        1.ģʽ�е��ַ�'.'��ʾ����һ���ַ�
        2.ģʽ�е��ַ�'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ���
        �ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ��*/
   //��̬�滮
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;//�մ�
    for (int j = 2; j <= n; j++) {
        //�������Լ�ǰ����ַ��ظ�0��
        if (p[j - 1] == '*')//��ϣ� ����j-2����*��j-1����
            dp[0][j] = dp[0][j - 2]; //����ǰһ���ܹ�ƥ��մ��й�
    }
    for (int i = 1; i <= m; i++) {   //����strÿ������
        for (int j = 1; j <= n; j++) {  //����patternÿ������
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {  //��ǰ�ַ���Ϊ*����.ȥƥ������ַ�ֱ����ͬ
                dp[i][j] = dp[i - 1][j - 1];
            }  
            else if (p[j - 1] == '*') {//��ǰ���ַ�Ϊ*
                if (j > 1) {
                    if (dp[i][j - 2]) dp[i][j] = true; //����ǰһλΪ.����ǰһλ�������������ƥ��
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

