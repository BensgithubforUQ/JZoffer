#include "Solution2.h"]

void printArray(const vector<int>& array) {
	for (auto a : array) {
		cout << a << " ";
	}
	cout << endl;
}

vector<int> Solution2::reOrderArray(vector<int>& array) {
	/*输入一个长度为 n 整数数组，实现一个函数来调整该数组中数字的顺序，
		使得所有的奇数位于数组的前面部分，所有的偶数位于数组的后面部分，
		并保证奇数和奇数，偶数和偶数之间的相对位置不变。*/
	int size = array.size();
	int pre = -1;//用于z存放被置换的偶数的位置
	int last = -1;//用于存放下一个奇数的位置
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
