class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        vector<int> temp;
        int sum1 = 0;
        //��Ϊ�������������������ö����ൽ�����ֵ�һ������ȡ��
        int up = (sum - 1) / 2;
        //ö��������
        for (int i = 1; i <= up; i++) {
            //���������������������ۼ�
            for (int j = i; ; j++) {
                sum1 += j;
                //����Ŀ�����������������
                if (sum1 > sum) {
                    sum1 = 0;
                    break;
                    //�������ҵ�
                }
                else if (sum1 == sum) {
                    sum1 = 0;
                    temp.clear();
                    //��¼���������
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