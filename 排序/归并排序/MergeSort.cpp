#include <iostream>
#include <vector>
using namespace std;

// 使用递归方法来实现归并排序时，主要是两个“有序子序列”的合并

//(1)将待排序序列从中间一分为二，
//对左右两边再进行递归分割操作，使用递归，得到n个相互独立的子序列（过程像二叉树那样）；
//
//(2)对n个独立的子序列递归的执行合并操作，最终得到有序的序列。

void merge(vector<int>& arr, int begin_index, int mid_index, int end_index);

void mergeSort(vector<int> &arr, int begin_index, int end_index) {
	if (begin_index == end_index) return;
	else cout << begin_index << " " << end_index << endl;

	//类似二分法
	int mid_index = (end_index - begin_index) / 2 + begin_index;
	mergeSort(arr, begin_index, mid_index); //对半分
	mergeSort(arr, mid_index+1, end_index); //对半分
	merge(arr, begin_index, mid_index, end_index); //对半分完了排列
}

void merge(vector<int>& arr, int begin_index, int mid_index, int end_index) {
	vector<int> temp;
	int id_1 = begin_index;
	int id_2 = mid_index + 1;
	while (id_1 <= mid_index && id_2 <= end_index) {
		arr[id_1] <= arr[id_2] ? (temp.push_back(arr[id_1++])) : (temp.push_back(arr[id_2++]));
	}
	while (id_1 <= mid_index) temp.push_back(arr[id_1++]);
	while (id_2 <= end_index) temp.push_back(arr[id_2++]);
	cout << temp.size() << endl;
	for (int i = 0, j = begin_index; i < temp.size(); i++,j++)
		arr[j] = temp[i];
}

int main() {
	vector<int> arr = { 6,5,4,8,9,7,10,2,1,3,12,14 };
	mergeSort(arr, 0, arr.size() - 1);
	for (auto i : arr) {
		cout << i <<" ";
	}
	return 0;
}