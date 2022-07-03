#include "Solution2.h"

bool Solution2::isNumeric(string str) {
	/*请实现一个函数用来判断字符串str是否表示数值（包括科学计数法的数字，小数和整数）。

		科学计数法的数字(按顺序）可以分成以下几个部分:
	    1.若干空格
		2.一个整数或者小数
		3.（可选）一个 'e' 或 'E' ，后面跟着一个整数(可正可负)
		4.若干空格

		小数（按顺序）可以分成以下几个部分：
		1.若干空格
		2.（可选）一个符号字符（'+' 或 '-'）
		3. 可能是以下描述格式之一:
	    3.1 至少一位数字，后面跟着一个点 '.'
		3.2 至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
		3.3 一个点 '.' ，后面跟着至少一位数字
		4.若干空格

		整数（按顺序）可以分成以下几个部分：
		1.若干空格
		2.（可选）一个符号字符（'+' 或 '-')
		3. 至少一位数字
		4.若干空格


		例如，字符串["+100", "5e2", "-123", "3.1416", "-1E-16"]都表示数值。
		但是["12e", "1a3.14", "1.2.3", "+-5", "12e+4.3"]都不是数值。

		提示 :
	1.1 <= str.length <= 25
		2.str 仅含英文字母（大写和小写），数字（0 - 9），加号 '+' ，减号 '-' ，空格 ' ' 或者点 '.' 。*/
	
    while (str[0] == ' ') {
        str.erase(str.begin());
    }

    bool flag_front = true; //头部 + 或者 - 的判定
    bool flag_point = true; // .的判定
    bool flag_e = true; //e的判定
    bool flag_middle = true; //e后+/-的判定
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
            cout << "重复的+/-";
            return false;
        }
        if (flag_blank == true && (str[0] == ' ')) {
            while (!str.empty()) {
                if (str[0] != ' ') {
                    cout << "空格后出现非空格" << endl;
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
            cout << "重复的. / e后小数" << endl;
            return false;
        }

        if ((str[0] >= '0' && str[0] <= '9')) {
            str.erase(str.begin());
            flag_number = true; //最后判断是否有过数字
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
                cout << "重复的middle +/-" << endl;
                return false;
            }
            if (!(str[0] >= '0' && str[0] <= '9')) {
                cout << "e后无数" << endl;
                return false;
            }
        }
        else if ((str[0] == 'E' || str[0] == 'e') && (flag_e == false ||
            flag_number == false)) {
            cout << "重复的e" << endl;
            return false;
        }

    }
    if (flag_number == false && flag_e == false) {
        cout << "孤独的e" << endl;
        return false;
    }
    if (flag_number == false && flag_point == false) {
        cout << "孤独的." << endl;
        return false;
    }
    return true;
}