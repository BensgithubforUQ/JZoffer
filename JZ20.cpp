#include "Solution2.h"

bool Solution2::isNumeric(string str) {
	/*��ʵ��һ�����������ж��ַ���str�Ƿ��ʾ��ֵ��������ѧ�����������֣�С������������

		��ѧ������������(��˳�򣩿��Էֳ����¼�������:
	    1.���ɿո�
		2.һ����������С��
		3.����ѡ��һ�� 'e' �� 'E' ���������һ������(�����ɸ�)
		4.���ɿո�

		С������˳�򣩿��Էֳ����¼������֣�
		1.���ɿո�
		2.����ѡ��һ�������ַ���'+' �� '-'��
		3. ����������������ʽ֮һ:
	    3.1 ����һλ���֣��������һ���� '.'
		3.2 ����һλ���֣��������һ���� '.' �������ٸ�������һλ����
		3.3 һ���� '.' �������������һλ����
		4.���ɿո�

		��������˳�򣩿��Էֳ����¼������֣�
		1.���ɿո�
		2.����ѡ��һ�������ַ���'+' �� '-')
		3. ����һλ����
		4.���ɿո�


		���磬�ַ���["+100", "5e2", "-123", "3.1416", "-1E-16"]����ʾ��ֵ��
		����["12e", "1a3.14", "1.2.3", "+-5", "12e+4.3"]��������ֵ��

		��ʾ :
	1.1 <= str.length <= 25
		2.str ����Ӣ����ĸ����д��Сд�������֣�0 - 9�����Ӻ� '+' ������ '-' ���ո� ' ' ���ߵ� '.' ��*/
	
    while (str[0] == ' ') {
        str.erase(str.begin());
    }

    bool flag_front = true; //ͷ�� + ���� - ���ж�
    bool flag_point = true; // .���ж�
    bool flag_e = true; //e���ж�
    bool flag_middle = true; //e��+/-���ж�
    bool flag_blank = false;
    bool flag_number = false;
    if ((str[0] == '+' || str[0] == '-') && flag_front == true) {
        flag_front = false;
        str.erase(str.begin());
    }
    if (str.empty()) return false;
    while (!str.empty()) {
        if (str[0] == '+' || str[0] == '-' || (str[0] != ' ' && str[0] != '.' &&
            !(str[0] >= '0' && str[0] <= '9'))) {
            cout << "�ظ���+/-";
            return false;
        }
        if (flag_blank == true && (str[0] == ' ')) {
            while (!str.empty()) {
                if (str[0] != ' ') {
                    cout << "�ո����ַǿո�" << endl;
                    return false;
                }
                str.erase(str.begin());
            }
        }

        if (str[0] == '.' && flag_point == true && flag_e == true) {
            flag_point = false;
            flag_blank = true;
            str.erase(str.begin());
        }
        else if (str[0] == '.' && (flag_point == false || flag_e == false)) {
            cout << "�ظ���. / e��С��" << endl;
            return false;
        }

        if ((str[0] >= '0' && str[0] <= '9')) {
            str.erase(str.begin());
            flag_number = true; //����ж��Ƿ��й�����
            flag_blank = true;
        }

        if ((str[0] == 'E' || str[0] == 'e') && flag_e == true && flag_number == true) {
            flag_e = false;
            str.erase(str.begin());
            if ((str[0] == '+' || str[0] == '-') && flag_middle == true) {
                flag_middle = false;
                str.erase(str.begin());
            }
            else if ((str[0] == '+' || str[0] == '-') && flag_middle == false) {
                cout << "�ظ���middle +/-" << endl;
                return false;
            }
            if (!(str[0] >= '0' && str[0] <= '9')) {
                cout << "e������" << endl;
                return false;
            }
        }
        else if ((str[0] == 'E' || str[0] == 'e') && (flag_e == false ||
            flag_number == false)) {
            cout << "�ظ���e" << endl;
            return false;
        }

    }
    if (flag_number == false && flag_e == false) {
        cout << "�¶���e" << endl;
        return false;
    }
    if (flag_number == false && flag_point == false) {
        cout << "�¶���." << endl;
        return false;
    }
    return true;
}