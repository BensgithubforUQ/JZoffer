#include "Solution.h"

bool Solution::Find(int target, vector<vector<int> > array) {//JZ4 ��ά�����еĲ���
	/*��һ����ά����array�У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
		ÿһ�ж����մ��ϵ��µ�����˳������
		�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������*/
	if (!array.empty()) {
		for (auto i : array) {
			if (i[0] > target) {
				continue;
			}
			else {
				for (auto j : i) {
					if (j == target) {
						return true;
					}
				}
			}
		}
		return false;
	}
	else {
		return false;
	}
}

bool Solution::Find1(int target, vector<vector<int> > array) {//JZ4 ��ά�����еĲ���
	/*��һ����ά����array�У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������
		ÿһ�ж����մ��ϵ��µ�����˳������
		�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������*/
	set<int>s;
	for (auto i : array) {
		for (auto j : i) {
			s.insert(j);
		}
	}
	int intial_Size = s.size();
	s.insert(target);
	if (intial_Size != s.size()) {
		return false;
	}
	else {
		return true;
	}
}

