#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //说实话没搞懂为什么要反转反转，直接取子串赋值不好吗。。。。。
        for (int i = 0; i < n; i++) {
            auto temp = str.begin();
            temp = temp + i;
            str.push_back(*temp);
        }
        int size = str.size();
        str = str.substr(n, size);
        return str;
    }
};