#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
	//给出一个长度为 n 的，仅包含字符 '(' 和 ')' 的字符串，计算最长的格式正确的括号子串的长度。
	//用栈记录左括号位置，然后用一个int记录上次结束的位置。
	int size = s.size();
	stack<int> b;
	int start = -1;
	int res = 0;
	for (int i = 0; i < size; i++) {
		if (s[i] == '(') b.push(i);
		else {
			if (b.empty()) start = i;
			else {
				b.pop();
				if (!b.empty()) res = max(res, i - b.top());
				else res = max(res, i - start);
			}
		}
	}
	return res;
}