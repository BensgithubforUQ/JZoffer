#include<iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) { //������������Ǳ�������������������λ������
        // write code here
        map<int, int> m;
        for (auto i : array) {
            auto target = m.find(i);
            if (target == m.end()) m.insert(pair<int, int>(i, 1));
            else m.erase(target);
        }
        cout << m.size() << endl;
        vector<int> res;
        auto i = m.begin();
        res.push_back(i->first);
        i++;
        res.push_back(i->first);
        return res;
    }
};