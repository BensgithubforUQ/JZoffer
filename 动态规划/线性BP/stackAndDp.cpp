#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
	//����һ������Ϊ n �ģ��������ַ� '(' �� ')' ���ַ�����������ĸ�ʽ��ȷ�������Ӵ��ĳ��ȡ�
	//��ջ��¼������λ�ã�Ȼ����һ��int��¼�ϴν�����λ�á�
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