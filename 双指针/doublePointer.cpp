#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int> > threeSum(vector<int>& num) { //�ù�ϣ��ȽϷ�����Ҫ�����ж�һ��ֵ�Ƿ��ж�γ��֣���˫ָ������š�
    vector<vector<int>> res;
    //set<vector<int>> noRepeat;
    if (num.size() < 3) return res;
    sort(num.begin(), num.end());
    int cur = -101;
    for (int i = 0; i < num.size() && num[i] <= 0; i++) { //����׼ֵ����0���򲻿����ٵõ���Ϊ0�����
        if (num[i] == cur) continue;
        cur = num[i];
        int left = i + 1;
        int right = num.size() - 1;
        while (left < right) {
            int cur_l = num[left]; //��¼��ǰ��ֵ����ֵ
            int cur_r = num[right];
            int sum = num[i] + num[left] + num[right];
            if (sum == 0) {
                vector<int> temp = { num[i], num[left], num[right] };
                //sort(temp.begin(), temp.end());
                res.push_back(temp);
                right--;
                left++;
                while (num[left] == cur_l && left < right) left++; //��ͬ��ֵû��Ҫ���ã���Ϊһһ��Ӧ��
                while (num[right] == cur_r && left < right) right--; 
            }
            if (num[i] + 2 * num[right] < 0) break; //�����׼ֵ  + ��ֵ��������С��0����ζ���Ѿ��޷���Ϊ0����ֵ̫С
            if (num[i] + 2 * num[left] > 0) break; //ͬ��
            if (sum > 0) { //����ʹ���0����ζ�ŵ�ǰ��ֵ̫��
                right--;
                while (num[right] == cur_r && left < right) right--;
            }
            if (sum < 0) { //�����С��0����ζ�ŵ�ǰ��ֵ̫С
                left++;
                while (num[left] == cur_l && left < right) left++;
            }
        }
    }
    //for (auto i : noRepeat) res.push_back(i);
    return res;
}