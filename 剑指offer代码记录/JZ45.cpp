#include "Solution4.h"
//输入一个非负整数数组numbers，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
//例如输入数组[3，32，321]，则打印出这三个数字能排成的最小数字为321323。
//1.输出结果可能非常大，所以你需要返回一个字符串而不是整数
//2.拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
class cmp {
public:
    bool operator()(string a, string b) {
        return a + b < b + a;
    }
};

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        multiset<string, cmp> s_str;
        string res = "";
        for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
            s_str.insert(to_string(*i));
        }
        for (multiset<string, cmp>::iterator i = s_str.begin(); i != s_str.end(); i++) {
            res += *i;
        }
        return res;
    }

};