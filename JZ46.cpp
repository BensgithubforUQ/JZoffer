#include "Solution4.h"
//
//��һ�ֽ���ĸ��������ֵķ�ʽ��'a'->1, 'b->2', ..., 'z->26'��
//���ǰ�һ���ַ��������һ�����֣��ٿ������������ַ�����
//����û�зָ��������ֱ������ĸ�����ж��ֱ����������� 11 �ȿ��Կ��������� 'a' Ҳ���Կ�����һ�� 'k' ��
//�� 10 ֻ������ 'j' ����Ϊ 0 ���ܱ�����κν����
//���ڸ�һ�����֣������ж����ֿ��ܵ�������
class Solution {
public:
    /**
     * ����
     * @param nums string�ַ��� ���ִ�
     * @return int����
     */
    int solve(string nums) {
        // write code here
        vector<int> dp(nums.size() + 1, 1);
        if (nums == "0") return 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == '0' && (nums[i - 1] != '1' && nums[i - 1] != '2')) {
                return 0;
            }
            if (nums[i] >= '0' && nums[i] <= '9') {
                dp[i + 1] = dp[i];
            }
            if ((nums[i - 1] == '1' && nums[i] > '0') || (nums[i - 1] == '2' && nums[i] < '7' && nums[i]>'0')) {
                dp[i + 1] = dp[i] + dp[i - 1];
            }
        }
        return dp[nums.size()];
    }
};