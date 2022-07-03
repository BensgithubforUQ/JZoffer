#include "Solution.h"

class compare { //�º�����һ��
public:
	bool operator()(int a,int b) const {
		return a > b;
	}
};

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {// ��С��K����
	//����һ������Ϊ n �Ŀ������ظ�ֵ�����飬�ҳ����в�ȥ�ص���С�� k ������
	//	��������Ԫ����4, 5, 1, 6, 2, 7, 3, 8��8�����֣�����С��4��������1, 2, 3, 4(����˳��Կ�)��
	/*���룺
		[4, 5, 1, 6, 2, 7, 3, 8], 4
	����ֵ��
		[1, 2, 3, 4]
	˵����
		������С��4�������ɣ�����[1, 3, 2, 4]Ҳ����*/
	multiset<int,compare> s;
	vector<int> res;
	int min = 0;
	for (vector<int>::iterator i = input.begin(); i != input.end(); i++) {
		if (i - input.begin() < 4) {
			s.insert(*i);
			continue;
		}
		if ((*s.begin()) > *i) {
			s.erase(s.begin());
			s.insert(*i);
		}
	}
	for (multiset<int, compare>::iterator i = s.begin(); i != s.end(); i++) {
		res.push_back(*i);
	}
	return res;
}