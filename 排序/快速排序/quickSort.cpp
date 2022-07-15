#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int begin, int end) { //最坏n*n，平均n*logn
	if (begin < end) {
		int temp = arr[begin];
		int i = begin;
		int j = end;
		while (i < j) {
			while (i < j && arr[j]>temp) j--;
			arr[i] = arr[j]; //此时的arr[j] 是一个小于或等于基准temp的值，直接用他代替基准原来在的位置
			while (i < j && arr[i] <= temp) i++;
			arr[j] = arr[i]; //此时的arr[i] 是一个大于基准temp的值，直接用它代替之前得到的右边第一个小于基准的值的位置的数
		}//经过上述循环，i和j不断靠近，依靠基准值temp把数据分为左右两部分。
		arr[i] = temp; //然后把当前的位置的值替换为基准值。
		//但是这样只是把左右笼统的排序成为大于或者小于基准值的值，数据依然是无序的，因此需要递归
		quickSort(arr, begin, i - 1);
		quickSort(arr, i + 1, end);
	}
	else return;
}

int main() {
	vector<int> arr = { 5,4,3,2,1,6,7,8,9,10 };
	quickSort(arr,0,arr.size()-1);
	for (auto i : arr) cout << i << " ";
	return 0;
}