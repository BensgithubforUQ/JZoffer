class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param array int����vector
     * @return int����vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) { // ���������������(��)
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
            if (temp + array[j] < array[j]) { //�������һ�Ѽ����� Ϊ���� �������ұߵ�һ������
                //����߿���ֱ�����������ұ߿�ʼ����
                //������һ����ؼ�����һ���Ƕ�̬�滮��˼·��
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