#include "Solution.h"

int Solution::duplicate(vector<int>& numbers){//JZ3 数组中重复的数字
    // write code here
    set <int> s;
    int j = s.size();
    for (int i = 0; i < numbers.size(); i++) {
        s.insert(numbers[i]);
        ++j;
        if (j != s.size()) {
            return numbers[i];
        }
    }
    return -1;
}


int Solution::duplicate2(vector<int>& numbers) {
    bool flag = false;
    for (auto i : numbers) {
        if (count(numbers.begin(), numbers.end(), i) > 0) {
            flag = true;
            return i;
        }
    }
    if (!flag) {
        return -1;
    }
}
