class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
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