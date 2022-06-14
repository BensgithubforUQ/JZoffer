#include "Solution4.h"
//输入一个整数 n ，求 1～n 这 n 个整数的十进制表示中 1 出现的次数
//例如， 1~13 中包含 1 的数字有 1 、 10 、 11 、 12 、 13 因此共出现 6 次
//
//注意：11 这种情况算两次
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n) {
        int count = 0;
        for (int i = 1; i < n + 1; i++) {
            string str = to_string(i);
            cout << str << endl;
            int size = str.size();
            for (int j = 0; j < size; j++) {
                if (str[j] == '1') {
                    count++;
                }
            }
        }
    }
};

