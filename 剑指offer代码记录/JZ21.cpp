#include "Solution2.h"]

void printArray(const vector<int>& array) {
	for (auto a : array) {
		cout << a << " ";
	}
	cout << endl;
}

vector<int> Solution2::reOrderArray(vector<int>& array) {
	/*����һ������Ϊ n �������飬ʵ��һ�����������������������ֵ�˳��
		ʹ�����е�����λ�������ǰ�沿�֣����е�ż��λ������ĺ��沿�֣�
		����֤������������ż����ż��֮������λ�ò��䡣*/
	int size = array.size();
	int pre = -1;//����z��ű��û���ż����λ��
	int last = -1;//���ڴ����һ��������λ��
	for (int i = 0; i < size; i++) {
		if (array[i] % 2 == 0) {
			pre = i;
			/*cout << "pre: " << pre << " ,";
			printArray(array);*/
		}
		if (pre == -1) continue;
		for (int i = pre + 1; i < size; i++) {
			if (array[i] % 2 != 0) {
				last = i;
				/*cout << "last: " << last << " ,";
				printArray(array);*/
				int temp = array[last];
				for (int j = last; j > pre; j--) {
					array[j] = array[j - 1];
					//cout << "fuzhi" << " ,";
					/*printArray(array);*/
				}
				array[pre] = temp;
				break;
			}
		}
	}
	
	return array;
}
