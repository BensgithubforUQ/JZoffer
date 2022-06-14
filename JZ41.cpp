#include "Solution4.h"


//如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
//如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
//我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。


//max （） min

class Solution {
public:
    vector<double>v;
    void Insert(int num) {
        if (v.empty()) {
            v.push_back(num);
        }
        else {
            int i = 0;
            for (; i < v.size(); i++) {
                if (num <= v[i]) {
                    //1,3,4,5 <-2
                    break;
                }
            }
            v.insert(v.begin() + i, num);
        }
    }

    double GetMedian() {
        int n = v.size();
        if (n % 2 == 0) {
            double n1 = v[n / 2];
            double n2 = v[n / 2 - 1];
            return (n1 + n2) / 2;
        }
        else {
            return v[n / 2];
        }
    }

};