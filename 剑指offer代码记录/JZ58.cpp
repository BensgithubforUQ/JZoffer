#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //˵ʵ��û�㶮ΪʲôҪ��ת��ת��ֱ��ȡ�Ӵ���ֵ�����𡣡�������
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