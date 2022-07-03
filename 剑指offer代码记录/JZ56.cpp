#include<iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindNumsAppearOnce(vector<int>& array) { //这个方法明显是暴力方法，但是懒得用位运算了
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