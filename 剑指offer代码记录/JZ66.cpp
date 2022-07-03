#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) { //就是左边迭代乘过去，右边迭代乘回来。
        vector<int> B(A.size(), 1);
        for (int i = 0; i < A.size(); i++) {
            if (i == 0) B[i] = 1;
            else B[i] = B[i - 1] * A[i - 1];
        }
        int temp = 1;
        for (int i = B.size() - 2; i >= 0; i--) {
            temp = temp * A[i + 1];
            B[i] = temp * B[i];
        }
        cout << B.size() << endl;
        return B;
    }
};
