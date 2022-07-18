#include <iostream>
#include <vector>
#include <queue>
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

//�Ǿ͵����������ŵĿ���
class Solution {
public:
    void quickSort(int begin, int end, vector<int>& a, int K) { //����������ţ�
        int povit = (begin + end) / 2;
        int temp = a[povit];
        a[povit] = a[begin];
        a[begin] = temp;
        //��Ϊ��Ŀ����������д��һ����������ݣ�������ֱ����������Ԫ�ص�����׼�㣬�ͻᵼ�¿����˻���o n2
        //���Բ�ȡ������Ϊ��׼���ˡ�
        int i = begin;
        int j = end;
        temp = a[begin];
        while (i < j) {
            while (i < j && a[j] <= temp) j--; //��С�ڵ��ڻ�׼ֵ�������Ҳ�
           //�ͷ����˱Ȼ�׼ֵ���ֵ��
            while (i < j && a[i] >= temp) i++; //ͬ��
            //��ʱi����ֵӦ����С�ڻ��ߵ��ڻ�׼ֵ��
            if (i < j) swap(a[i], a[j]);
        }
        swap(a[begin], a[i]);

        //��ʱ���õ�i��඼�Ǵ��ڻ��ߵ���temp�ģ�i���Ҳ඼��С��temp��
        if (K < i + 1)  quickSort(begin, i - 1, a, K); //���ַ�����Ϊ���ҵ�k�󣬶�����ǰk�����Բ���Ҫȫ�����ֻ꣬��Ҫ�ҵ���Ӧ�ĵ������
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

//�����������Ҳ����ˣ����������priority_queue���stl���� ��standard template library�����ǾͲ�̫����hh�������˷��˿ռ䡣
int findKth(vector<int> a, int n, int K) {
    // write code here
    if (K > n / 2) {
        priority_queue<int, vector<int>, greater<int>> res; //С����
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
    priority_queue<int, vector<int>>res; //��С
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