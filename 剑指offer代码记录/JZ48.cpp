#include "Solution4.h"

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int lengthOfLongestSubstring(string s) {
        // write code here
        int sub = 0;
        for (int i = 0; i < s.size(); i++) {
            set<char>alphabet;
            int temp = 0;
            for (int j = i; j < s.size(); j++) {
                int size = alphabet.size();
                alphabet.insert(s[j]);
                if (size == alphabet.size()) {
                    break;
                }
                temp++;
            }
            sub = max(temp, sub);
            cout << sub << endl;
        }
        return sub;
    }
};