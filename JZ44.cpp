#include "Solution4.h"
//������ 0123456789101112131415...�ĸ�ʽ��Ϊһ���ַ����У�
//����������е� 2 λ�����±� 0 ��ʼ���㣩�� 2 ���� 10 λ�� 1 ���� 13 λ�� 1 ���Դ����⣬��������� n λ��Ӧ�����֡�
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param n int����
     * @return int����
     */
    int findNthDigit(int n) {
        // write code here
        // 0 - 9 = 10 * 1 10 
        // 10 - 99 = 90 * 2 180 
        // 100 - 999 = 900 * 3 2700
        // ****        9000 * 4 36000
        // write code here
        long int num = 10;
        long int size = 1;
        long int th = 1;
        long int temp = 0;
        for (; num <= n; num += size * (th * 9)) {
            temp = num;
            size++;
            th = th * 10;
        }
        cout << "temp ��" << temp << endl;
        cout << "num ��" << num << endl;
        cout << "size ��" << size << endl;
        cout << "th ��" << th << endl;
        cout << "/" << (n - temp) / size << endl;
        cout << "%" << (n - temp) % size << endl;
        long int res = 0;
        if (n > 10) res = 1;
        for (int i = 0; i < size - 1; i++) {
            res = res * 10;
        }
        res += (n - temp) / size;
        string str = to_string(res);
        cout << str << endl;
        res = (int)(str[(n - temp) % size] - 48);
        return res;
    }
};