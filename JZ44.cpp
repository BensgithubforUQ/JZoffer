#include "Solution4.h"
//数字以 0123456789101112131415...的格式作为一个字符序列，
//在这个序列中第 2 位（从下标 0 开始计算）是 2 ，第 10 位是 1 ，第 13 位是 1 ，以此类题，请你输出第 n 位对应的数字。
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int findNthDigit(int n) {
        // write code here
        // 0 - 9 = 10 * 1 10 
        // 10 - 99 = 90 * 2 180 
        // 100 - 999 = 900 * 3 2700
        // ****        9000 * 4 36000
        // write code here
        long int num = 10;
        long int size = 1;
        long int th = 1;
        long int temp = 0;
        for (; num <= n; num += size * (th * 9)) {
            temp = num;
            size++;
            th = th * 10;
        }
        cout << "temp ：" << temp << endl;
        cout << "num ：" << num << endl;
        cout << "size ：" << size << endl;
        cout << "th ：" << th << endl;
        cout << "/" << (n - temp) / size << endl;
        cout << "%" << (n - temp) % size << endl;
        long int res = 0;
        if (n > 10) res = 1;
        for (int i = 0; i < size - 1; i++) {
            res = res * 10;
        }
        res += (n - temp) / size;
        string str = to_string(res);
        cout << str << endl;
        res = (int)(str[(n - temp) % size] - 48);
        return res;
    }
};