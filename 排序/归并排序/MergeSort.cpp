#include <iostream>
#include <vector>
using namespace std;

// 使用递归方法来实现归并排序时，主要是两个“有序子序列”的合并 ----分治法，分而治之，然后吞并。

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

//int main() {
//	vector<int> arr = { 6,5,4,8,9,7,10,2,1,3,12,14 }; //原教旨归并排序
//	mergeSort(arr, 0, arr.size() - 1);
//	for (auto i : arr) {
//		cout << i <<" ";
//	}
//	return 0;
//}

char low2up(char a) {
    if (a >= 'A' && a <= 'Z')
        return a - 'A' + 'a';
    return a;
}

void merge1(vector<char>& v, int left, int mid, int right) {
    vector<char> temp;
    int i1 = left;
    int i2 = mid + 1;
    while (i1 <= mid && i2 <= right) {
        low2up(v[i1]) <= low2up(v[i2]) ? (temp.push_back(v[i1++])) : (temp.push_back(v[i2++]));
    }
    while (i1 <= mid) temp.push_back(v[i1++]);
    while (i2 <= right) temp.push_back(v[i2++]);
    for (int i = 0, j = left; i < temp.size(); i++, j++) v[j] = temp[i];
}

void mergeSort1(vector<char>& v, int begin, int end) {
    if (begin == end) return;
    int mid = (end + begin) / 2;
    mergeSort1(v, begin, mid);
    mergeSort1(v, mid + 1, end);
    merge1(v, begin, mid, end);
}

int main() {
    char c;
    vector<char> v;
    vector<char> res;
    int pos = 0;
    while ((c = getchar()) != '\n') {
        if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A')) v.push_back(c);
        res.push_back(c);
    }
    mergeSort1(v, 0, v.size()-1);
    for (int i = 0, j = 0; i < res.size() && j < v.size(); i++) {
        if ((res[i] <= 'z' && res[i] >= 'a') || (res[i] <= 'Z' && res[i] >= 'A')) {
            res[i] = v[j];
            j++;
        }
    }
    for (auto i : res) cout << i;
    return 0;
}