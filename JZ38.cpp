#include "Solution4.h"

//输入一个长度为 n 字符串，打印出该字符串中字符的所有排列，你可以以任意顺序返回这个字符串数组。
//例如输入字符串ABC, 则输出由字符A, B, C所能排列出来的所有字符串ABC, ACB, BAC, BCA, CBA和CAB。
vector<string> Solution4::Permutation(string str) {
	vector<string> res;
	set<string> res_s;
	int size = str.length();
	if (size == 1 || size == 0) {
		res.push_back(str);
		return res;
	}
	permutation(res_s, str, 0);
	for (set<string>::iterator begin = res_s.begin(); begin != res_s.end(); begin++) {
		res.push_back(*begin);
	}
	return res;
}
void Solution4::permutation(set<string>& ans, string str, int index) {
	if (index >= str.length()) {
		//找到了一个答案
		//对于去除重复排列，还有一种非常简单的方案，就是再保存某一个排列时，直接判断该排列情况是否
		//已经存在于答案集里，存在则不再插入。
		cout << "插入 " << str << endl;
		ans.insert(str);
		return;
	}
	for (int i = index; i < str.length(); i++) { //条件
		cout << "index= " << index << " i= " << i << " " << str << " ";
		swap(str[i], str[index]); //交换 查询
		cout<<str<<endl;
		permutation(ans, str, index + 1);
		swap(str[i], str[index]); //交换回来  回溯
		cout << "回转 index: " << index << " i: " << i << " " << str << endl;
	}
	cout << "end!!!!" << endl;
}
int main() {
	string s = "abc";
	Solution4 s4;
	//cout << s[0] << endl; //test
	//s[0] = s[2];
	//printf("s[0]:%c\n", s[0]);
	vector<string> sv = s4.Permutation(s);
	for (int i = 0; i < sv.size(); i++) {
		cout << sv[i] << endl;
	}
	return 0;
}