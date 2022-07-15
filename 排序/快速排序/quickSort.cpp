#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int begin, int end) { //�n*n��ƽ��n*logn
	if (begin < end) {
		int temp = arr[begin];
		int i = begin;
		int j = end;
		while (i < j) {
			while (i < j && arr[j]>temp) j--;
			arr[i] = arr[j]; //��ʱ��arr[j] ��һ��С�ڻ���ڻ�׼temp��ֵ��ֱ�����������׼ԭ���ڵ�λ��
			while (i < j && arr[i] <= temp) i++;
			arr[j] = arr[i]; //��ʱ��arr[i] ��һ�����ڻ�׼temp��ֵ��ֱ����������֮ǰ�õ����ұߵ�һ��С�ڻ�׼��ֵ��λ�õ���
		}//��������ѭ����i��j���Ͽ�����������׼ֵtemp�����ݷ�Ϊ���������֡�
		arr[i] = temp; //Ȼ��ѵ�ǰ��λ�õ�ֵ�滻Ϊ��׼ֵ��
		//��������ֻ�ǰ�������ͳ�������Ϊ���ڻ���С�ڻ�׼ֵ��ֵ��������Ȼ������ģ������Ҫ�ݹ�
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