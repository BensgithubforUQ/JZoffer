#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param s string�ַ���
     * @return int����
     */
    int StrToInt(string s) { //����Ŀ��ûʲô��˼
        // write code here
        //for(auto i :s){
        //  if(i == ' ')
        //}
        long long int res = 0;
        int flag = 0; //��ʼ
        char a = '0';
        printf("%d\n", a);
        int count = 0;
        int flag0 = 0;
        int over = 0;
        for (auto i : s) {

            if (count >= 10) {
                if (0 <= i - 48 && i - 48 <= 9) {
                    over = 1;
                }
                break;
            }
            if (flag == 0 && i != ' ' && i != '+' && i != '-' &&
                !(0 <= i - 48 && i - 48 <= 9)) {
                return 0;
            }
            if (flag != 0 && !(0 <= i - 48 && i - 48 <= 9)) break;
            if (i == ' ') continue;
            if (flag == 0 && (i == '+' || i == '-')) {
                if (i == '+') flag = 1; //�з��� ����
                else flag = 2; //�з��� ����
            }

            if (flag == 0 && (0 <= i - 48 && i - 48 <= 9)) {
                flag = 1; //�޷��� ����
                if (flag0 == 0 && flag != 0 && i != '0') flag0 = 1;
                if (flag0 == 1) {
                    res += (i - 48);
                    res *= 10;
                    count++;
                }
                continue;
            }
            if (0 <= i - 48 && i - 48 <= 9) {
                if (flag0 == 0 && flag != 0 && i != '0') flag0 = 1;
                if (flag0 == 1) {
                    res += (i - 48);
                    res *= 10;
                    count++;
                }
            }

        }

        if (flag == 2) res = 0 - res;
        res /= 10;
        if (res >= 2147483648) res = 2147483647;
        if (res <= -2147483648) res = -2147483648;
        if (over == 1 && flag == 1) res = 2147483647;
        if (over == 1 && flag == 2) res = -2147483648;
        printf("count: %d, res: %d \n", count, res);

        return res;
    }
};