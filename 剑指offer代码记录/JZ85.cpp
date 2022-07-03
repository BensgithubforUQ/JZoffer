class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) { // 连续子数组的最大和(二)
        // write code here
        vector<int>res;
        if (array.empty()) return res;
        int size = array.size();
        if (size == 1) return array;
        int max = array[0];
        int temp = 0;
        int max_count = 0;
        int count = 0;
        int pos = 0;
        for (int i = 0, j = 0; i < size;) {
            if (j == size) {
                i++;
                j = i;
                count = 0;
                temp = 0;
                continue;
            }
            if (temp + array[j] < array[j]) { //假如左边一堆加起来 为负数 还不如右边第一个数大
                //则左边可以直接抛弃，从右边开始更大
                //就是这一步最关键，这一步是动态规划的思路。
                i = i + count;
                count = 0;
                j = i;
                temp = 0;
            }
            temp += array[j];
            j++;
            count++;
            if (temp > max || (temp == max && count > max_count)) {
                pos = i;
                max = temp;
                max_count = count;
            }


        }
        cout << pos << " " << max_count << endl;
        for (int i = pos; i < max_count + pos; i++)
            res.push_back(array[i]);
        return res;
    }
};