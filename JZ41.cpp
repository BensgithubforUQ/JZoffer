#include "Solution4.h"


//��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
//������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
//����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����


//max ���� min

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