#include <iostream>
#include <vector>
#include <queue>
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

//那就得来看看快排的坑了
class Solution {
public:
    void quickSort(int begin, int end, vector<int>& a, int K) { //比如这个快排，
        int povit = (begin + end) / 2;
        int temp = a[povit];
        a[povit] = a[begin];
        a[begin] = temp;
        //因为题目把例子里面写了一堆逆序的数据，因此如果直接用数组首元素当做基准点，就会导致快排退化成o n2
        //所以不取首数组为基准点了。
        int i = begin;
        int j = end;
        temp = a[begin];
        while (i < j) {
            while (i < j && a[j] <= temp) j--; //当小于等于基准值，留在右侧
           //就发现了比基准值大的值，
            while (i < j && a[i] >= temp) i++; //同理
            //此时i处的值应该是小于或者等于基准值的
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[begin], a[i]);

        //此时，得到i左侧都是大于或者等于temp的，i的右侧都是小于temp的
        if (K < i + 1)  quickSort(begin, i - 1, a, K); //二分法，因为是找第k大，而不是前k大，所以不需要全部排完，只需要找到对应的点就行了
        if (K > i + 1) quickSort(i + 1, end, a, K);
    }
    int findKth(vector<int> a, int n, int K) {
        // write code here
        quickSort(0, n - 1, a, K);
        for (auto i : a) cout << i << " ";
        if (K > n || K == 0) return -1;
        return a[K - 1];
    }
};

//上面这个题他也可以耍赖哈，可以priority_queue这个stl来排 （standard template library）但是就不太好了hh，而且浪费了空间。
int findKth(vector<int> a, int n, int K) {
    // write code here
    if (K > n / 2) {
        priority_queue<int, vector<int>, greater<int>> res; //小到大
        for (auto i : a)
            res.push(i);
        K = n - K;
        while (!res.empty() && K > 0) {
            K--;
            cout << res.top() << " ";
            res.pop();
        }
        return res.top();
    }
    priority_queue<int, vector<int>>res; //大到小
    for (auto i : a)
        res.push(i);
    while (!res.empty() && K > 1) {
        K--;
        cout << res.top() << " ";
        res.pop();
    }
    return res.top();
}

int main() {
	vector<int> arr = { 5,4,3,2,1,6,7,8,9,10 };
	quickSort(arr,0,arr.size()-1);
	for (auto i : arr) cout << i << " ";
	return 0;
}