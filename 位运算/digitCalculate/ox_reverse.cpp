#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverse0X(string& str) {
    string temp;
    for (auto& i : str) { //����ԭ���и��Ӱ�����ǰû���֣���
        unsigned n, r = 0;
        if (i >= '0' && i <= '9')  n = i - '0';
        else if (i >= 'a' && i <= 'f') n = i - 'a' + 10;
        else if (i >= 'A' && i <= 'F') n = i - 'A' + 10;
        else continue;
        for (int j = 0; j < 4; j++) { //���������ĵߵ�����������ʵ��Ҫ���ڵ��ԵĴ�С��ת����
            r = r << 1;
            r += (n & 1);
            n = n >> 1;
        }
        //cout<<" i:"<<i<<" r:"<<r<<" n:"<<n<<endl;
        //cout<<r<<endl;
        if (r >= 0 && r <= 9)  i = '0' + r;
        if (r >= 10 && r < 16) i = r - 10 + 'A';
    }
}

int main() {
    //�������ʮ����������������ż����ż���ţ�������������
    //Ȼ�� ��ת��Ϊ2���ƣ�Ȼ������һ��temp��������������ԭ����Ȼ�������temp��
    //Ȼ������2������ ת�� Ϊ 16������
    //Ȼ�����ԭ��

    //Ȼ���������ϲ�������
    string str1, str2;
    char c;
    int pos = 1;
    while (cin >> c) {
        if (pos % 2 == 0) str2 += c;
        else str1 += c;
        pos++;
    }
    //getline(cin,str);
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    //cout<<str1<<" "<<str2<<endl;
    reverse0X(str1);
    reverse0X(str2);
    //cout<<str1<<" "<<str2<<endl;
    //cout<<str1<<" "<<str2<<endl;
    string str = "";
    int i = 0;
    while (str.size() < str1.size() + str2.size()) {
        if (i < str1.size()) str += str1[i];
        if (i < str2.size()) str += str2[i];
        i++;
    }

    cout << str << endl;
    return 0;

}