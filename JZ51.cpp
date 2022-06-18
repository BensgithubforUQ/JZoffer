#include <set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int n = 0;
        set<int> s_data;
        int size = 0;
        for (int i = 0; i < data.size(); i++) {
            s_data.insert(data[i]);
            size++;
            int index = 1;
            for (set<int>::iterator j = s_data.begin(); j != s_data.end(); j++, index++)
                if (data[i] == *j) break;
            if (size > index) n += size - index;

        }

        return n % 1000000007;
    }//�����ⷨ

    int recursion() {

    }
};