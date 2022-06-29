#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {//��ΪS����������
        //��׼����ֻ��ͷָ���βָ�����ұƽ�����������������飬���Կ����ö��ַ���һ�����ٲ�ѯ
        int size = array.size();
        vector<int> res;
        for (int i = 0; i < size; i++) {
            int l = i + 1;
            int r = size - 1;
            int mid = (r + l) / 2;
            int diff = sum - array[i];
            while (l <= r) {
                mid = (r + l) / 2;
                if (array[mid] == sum - array[i]) {
                    break;
                }
                if (array[mid] < diff) l = mid + 1;
                if (array[mid] > diff) r = mid - 1;

            }
            if (array[mid] == sum - array[i]) {
                res.push_back(array[i]);
                res.push_back(array[mid]);
                break;
            }
        }
        return res;

    }
};