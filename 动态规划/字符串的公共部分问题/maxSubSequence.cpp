#include <iostream>
#include <string>
#include <vector>
using namespace std;

//���䶯̬�滮��Ŀ-����������У��Ż���
int maxSubSequence(string& s1, int i, string& s2, int j, vector<vector<int>>& log) {
	//log����־����ž��Ǽ�¼�ĸ�λ���Ѿ��ȶԹ��ˣ��Ͳ���Ҫ�ٴαȶ�
	int size1 = s1.size();
	int size2 = s2.size();
	if (i >= size1 || j >= size2) return 0;
	if (log[i][ j] == 1) return 0;
	log[i][j] == 1; //���û���������ͼ���
	if (s1[i] == s2[j]) return 1 + maxSubSequence(s1, i + 1, s2, j + 1, log);
	return max(maxSubSequence(s1, i + 1, s2, j, log), maxSubSequence(s1, i, s2, j + 1, log));
}

int main() {
	string s1 = "abcdefga";
	string s2 = "abcaaaaaaaaaadefgaaaaaaaaaadefg";
	vector<vector<int>> log(s1.size(), vector<int>(s2.size(), 0));
	cout<<maxSubSequence(s1, 0, s2, 0, log);
	return 0;
}