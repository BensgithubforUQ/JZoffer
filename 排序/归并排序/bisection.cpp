#include <iostream>
#include <vector>
using namespace std;

//���ַ����򵥵ĺܣ�����ÿ����mid�Ƚ�һ�£���mid���left = mid+1
//�������right = mid

int bisection(vector<int>& nums, int target) { //ԭ��ּ������ַ���ѯ��
	if (nums.size() == 0) return -1; 
	int l, r, mid;
	l = 0;
	r = nums.size();
	mid = (r - l) / 2 + l;
	while (l < r) {
		if (nums[mid] < target) l = mid + 1;
		else r = mid;
		mid = (r - l) / 2 + l;
	}
	if (nums[mid] == target) return mid;
	else return -1;
}

int bisection_2dArray(vector<int>& arr, int target, int r) { //��ά����Ķ��ֲ���
    int l = 0;
    int mid = (r - l) / 2 + l;
    while (l < r) {
        if (arr[mid] < target) l = mid + 1;
        else r = mid;
        mid = (r - l) / 2 + l;
    }
    return mid;
}

bool Find(int target, vector<vector<int> > array) { 
    if (array.size() == 0 || array[0].size() == 0) return false;
    int  r = array[0].size() - 1;
    for (int i = 0; i < array.size(); i++) { 
        if (array[i][0] > target) return false;
        r = bisection_2dArray(array[i], target, r);
        if (array[i][r] == target) return true;
    }
    return false;
}

int findPeakElement(vector<int>& nums) { //o(n) Ѱ�ҷ�ֵ�����з��η���Ҳ���Ƕ��ַ�������
       // write code here'
    if (nums.size() == 0) return -1;
    if (nums.size() == 1) return 0;
    if (nums.size() == 2) {
        if (nums[0] == nums[1]) return -1;
        else return nums[0] < nums[1] ? 1 : 0;
    }
    int pre = 0;
    int cur = 1;
    int nex = 2;
    if (nums[pre] > nums[cur]) return pre;
    while (nex < nums.size()) {
        if (nums[pre]<nums[cur] && nums[cur]>nums[nex]) return cur;
        pre++;
        cur++;
        nex++;
    }
    if (nums[cur] > nums[pre]) return cur;
    else return -1;
}

int findPeakElement_bisection(vector<int>& nums) {
    //û������ȵģ���˿���ѡ�������ߴ��ߣ�ˮ���ʹ�����
    //ֱ��һ�����ַ�������mid������mid�Ǳ߸��ıߵ͡�����һֱ���ߵıߴ�
    int l = 0;
    int r = nums.size()-1;
    int mid = (r - l) / 2 + l;
    while (l < r) {
        if (nums[mid] < nums[mid + 1]) l = mid + 1; //�����midС���ұߵģ��Ǿ����ұ��ߣ��϶��в���
        else r = mid; //������˵��mid�����Ǵ����ұߵģ�������������ߣ��������߶��ַ�
        mid = (r - l) / 2 + l;
    }
    return mid;//����ֱ�ӷ���mid�����ˡ�
}

int minNumberInRotateArray(vector<int> arr) { //��ת�ķǽ������飬�Ҳ���
    //�Ҳ����𣬲��Ⱦ��Ƕ��ַ���������
    int l = 0;
    int r = arr.size() - 1;
    int mid = (r - l) / 2 + l;
    while (l < r) {
        if (arr[mid] > arr[r]) l = mid + 1;  //���mid�����Ҳ���mid������ζ��mid�ڷ�תǰ�ĺ��Σ�����С��϶���mid�ұ�
        else if (arr[mid] < arr[r]) r = mid; //mid�����Ҳ��ȣ����mid���Ҳ��С����˵�������ǽ������r = mid
        else if (arr[mid] == arr[r]) r = r - 1; //���mid�պú����Ҳ����ȣ��������ֿ���
        //1��mid����������ȵĵ������ϣ�������������Ҳ�㣬������ָ�С���Ҳ�㣬�ͻ�ִ�е�һ����������û�У��ͻ�ִ�еڶ������
        //2��mid���Ҳ������ȵĵ������ϣ�������������Ҳ�㣬������ָ�С��mid���ͻ�ڶ��֣�����ͻ��õ�һ�֡�
        mid = (r - l) / 2 + l;
    }
    return arr[mid];
}