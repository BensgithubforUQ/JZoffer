#include <iostream>
#include <vector>
using namespace std;

void heapSort(vector<int>& arr) { //����ѣ�������С���ѣ��Ž���
	//size / 2 �õ��ľ��Ƕѵĵ�һ��Ҷ�ӽ�����������ˣ�size / 2 - 1���ǵ�һ����Ҷ�ӽ�������
	int  size = arr.size();
	while (size > 0) {
		int start = size / 2 - 1; //���ǵ�һ����Ҷ�ӽ�������
		cout << "size: " << size << "start: " << start << " " << endl;
	//������Ҫ���ľ��ǲ鿴��Ҷ�ӽڵ�������ӽڵ㣬�Ƿ���󣬰ѱȽϴ����һ���͸ø��ڵ㽻��
		for (int i = start; i >= 0; i--) { 
			int mx = arr[i]; //ȡ���ڵ�ֵΪĬ�����ֵ
			if (i * 2 + 2 < size) { //�������ҽڵ��ʱ��
				if (arr[i * 2 + 1] < arr[i * 2 + 2]) { //����ҽڵ������ڵ㣬�򽻻����ҽڵ�λ��
					int temp = arr[i * 2 + 1];
					arr[i * 2 + 1] = arr[i * 2 + 2];
					arr[i * 2 + 2] = temp;
				}
			}
			if (mx < arr[i * 2 + 1]) { //��ʱ��ڵ�Ϊ�ӽڵ��нϴ��㣬������ڵ�С����ڵ㣬����λ��
				arr[i] = arr[i * 2 + 1];
				arr[i * 2 + 1] = mx;
			}
		}//��һ��ѭ��֮�󣬵�ǰ���ڵ�Ϊ�����ӽڵ�͸��ڵ��е����ֵ��Ȼ��i--����ǰ����
		int temp = arr[0]; //һ��ѭ��֮�����ո��ڵ�õ��˶������ֵ
		size = size - 1; //��ʱ�ͰѶѵĴ�Сsize--;���sizeҪ���ں���ѭ��
		arr[0] = arr[size]; //Ȼ��ѵ�ǰ������������һ�����ݽ���
		arr[size] = temp; 
	}
}


int main() {
	vector<int> test = { 5,4,3,2,1,7,8,9,70};
	heapSort(test);
	for (int i = 0; i < test.size(); i++)
		cout << test[i] << " ";
	return 0;
}