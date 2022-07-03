class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> reOrderArrayTwo(vector<int>& array) { 
        // write code here
        int size = array.size();
        for (int i = 0; i < size; i++) {
            if (array[i] % 2 != 0) {
                int temp = array[i];
                array.erase(array.begin() + i);
                array.insert(array.begin(), temp);
            }
        }
        return array;
    }
};