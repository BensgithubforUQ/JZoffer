#include <iostream>
#include <vector>
using namespace std;

void heapSort(vector<int>& arr) { //大跟堆，排升序，小根堆，排降序
	//size / 2 得到的就是堆的第一个叶子结点的索引，因此，size / 2 - 1就是第一个非叶子结点的索引
	int  size = arr.size();
	while (size > 0) {
		int start = size / 2 - 1; //这是第一个非叶子结点的索引
		cout << "size: " << size << "start: " << start << " " << endl;
	//现在需要做的就是查看非叶子节点的左右子节点，是否更大，把比较大的那一个和该根节点交换
		for (int i = start; i >= 0; i--) { 
			int mx = arr[i]; //取根节点值为默认最大值
			if (i * 2 + 2 < size) { //当存在右节点的时候
				if (arr[i * 2 + 1] < arr[i * 2 + 2]) { //如果右节点大于左节点，则交换左右节点位置
					int temp = arr[i * 2 + 1];
					arr[i * 2 + 1] = arr[i * 2 + 2];
					arr[i * 2 + 2] = temp;
				}
			}
			if (mx < arr[i * 2 + 1]) { //此时左节点为子节点中较大结点，如果根节点小于左节点，互换位置
				arr[i] = arr[i * 2 + 1];
				arr[i * 2 + 1] = mx;
			}
		}//则一次循环之后，当前根节点为左右子节点和根节点中的最大值，然后i--，向前遍历
		int temp = arr[0]; //一次循环之后，最终根节点得到了堆中最大值
		size = size - 1; //此时就把堆的大小size--;这个size要用于后续循环
		arr[0] = arr[size]; //然后把当前数组和数组最后一个数据交换
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