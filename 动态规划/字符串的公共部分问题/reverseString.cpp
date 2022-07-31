#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dp_decrypt(vector<vector<int>>& dp, int num, int size, string &str) { //���Ĵ����⣬����˫ָ���������
    if (num == dp.size()-1) return; //�ݹ��������
    //����ǰ���������������
    int left = num / 2;
    int right = num / 2;
    if (num % 2 == 1) {
        //������
    }
    if (num % 2 == 0) {
        //ż����
        left -= 1;
    }
    for (int i = 0; i < dp[num - 2].size(); i++) { //��ʵ����ά��һ����ά���飬������������string������
        if (dp[num - 2][i] - left >= 0 && dp[num - 2][i] + right < size) {
            if (str[dp[num - 2][i] - left] == str[dp[num - 2][i] + right]) //ÿ�ζ�ȡǰǰ���������Ȼ���ж϶�Ӧ��λ�õ���ֵ�Ƿ�һ��
                dp[num].push_back(dp[num - 2][i]); //���һ�����Ǿʹ浽��������
        }
    }
    dp_decrypt(dp, num+1, size, str); //����֮�����������ĵط�����
}

//int main() {
//    string str;
//    cin >> str;
//    vector<vector<int>> dp(str.size() + 1, vector<int>(0));
//    if (str.size() == 1)  cout << 1 << endl;
//    else {
//
//        int num = 0;
//        for (auto i : str) {
//            dp[1].push_back(num);
//            if (num + 1 < str.size())
//                if (str[num] == str[num + 1])
//                    dp[2].push_back(num);
//            num++;
//        }
//        dp_decrypt(dp, 3, str.size(), str);
//    }
//    for (auto i : dp) {
//        for (auto j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}