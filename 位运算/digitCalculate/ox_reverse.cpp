#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void reverse0X(string& str) {
    string temp;
    for (auto& i : str) { //这里原来有个坑啊，以前没发现，淦
        unsigned n, r = 0;
        if (i >= '0' && i <= '9')  n = i - '0';
        else if (i >= 'a' && i <= 'f') n = i - 'a' + 10;
        else if (i >= 'A' && i <= 'F') n = i - 'A' + 10;
        else continue;
        for (int j = 0; j < 4; j++) { //二进制数的颠倒输出，这个其实主要用于电脑的大小端转换。
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
    //输入的是十六进制数，先排序，偶数按偶数排，奇数按奇数排
    //然后 数转化为2进制，然后，再整一个temp二进制数，遍历原数，然后输入给temp数
    //然后把这个2进制数 转化 为 16进制数
    //然后代替原数

    //然后把俩数组合并起来。
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