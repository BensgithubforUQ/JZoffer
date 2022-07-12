#include <iostream>
#include <vector>
using namespace std;

// ʹ�õݹ鷽����ʵ�ֹ鲢����ʱ����Ҫ�����������������С��ĺϲ�

//(1)�����������д��м�һ��Ϊ����
//�����������ٽ��еݹ�ָ������ʹ�õݹ飬�õ�n���໥�����������У��������������������
//
//(2)��n�������������еݹ��ִ�кϲ����������յõ���������С�

void merge(vector<int>& arr, int begin_index, int mid_index, int end_index);

void mergeSort(vector<int> &arr, int begin_index, int end_index) {
	if (begin_index == end_index) return;
	else cout << begin_index << " " << end_index << endl;

	//���ƶ��ַ�
	int mid_index = (end_index - begin_index) / 2 + begin_index;
	mergeSort(arr, begin_index, mid_index); //�԰��
	mergeSort(arr, mid_index+1, end_index); //�԰��
	merge(arr, begin_index, mid_index, end_index); //�԰����������
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