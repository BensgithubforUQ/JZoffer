class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        vector<int> temp;
        int sum1 = 0;
        //因为序列至少两个数，因此枚举最多到该数字的一半向下取整
        int up = (sum - 1) / 2;
        //枚举左区间
        for (int i = 1; i <= up; i++) {
            //从左区间往后依次连续累加
            for (int j = i; ; j++) {
                sum1 += j;
                //大于目标和则跳出该左区间
                if (sum1 > sum) {
                    sum1 = 0;
                    break;
                    //等于则找到
                }
                else if (sum1 == sum) {
                    sum1 = 0;
                    temp.clear();
                    //记录线序的数字
                    for (int k = i; k <= j; k++)
                        temp.push_back(k);
                    res.push_back(temp);
                    break;
                }
            }
        }
        return res;
    }
};