#include "Solution4.h"

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return int����
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