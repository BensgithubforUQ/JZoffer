#include "Solution4.h"
//����һ���Ǹ���������numbers������������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
//������������[3��32��321]�����ӡ���������������ųɵ���С����Ϊ321323��
//1.���������ܷǳ�����������Ҫ����һ���ַ�������������
//2.ƴ�����������ֿ��ܻ���ǰ�� 0�����������Ҫȥ��ǰ�� 0
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