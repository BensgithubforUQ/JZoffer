#include <iostream>
#include <vector>
using namespace std;

//二分法，简单的很，就是每次拿mid比较一下，比mid大就left = mid+1
//否则就是right = mid

int bisection(vector<int>& nums, int target) { //原教旨主义二分法查询。
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

int bisection_2dArray(vector<int>& arr, int target, int r) { //二维数组的二分查找
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

int findPeakElement(vector<int>& nums) { //o(n) 寻找峰值，还有分治法，也就是二分法的做法
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
    //没有连相等的，因此可以选择人往高处走，水往低处流哈
    //直接一步二分法，先找mid，看看mid那边高哪边低。反正一直往高的边凑
    int l = 0;
    int r = nums.size()-1;
    int mid = (r - l) / 2 + l;
    while (l < r) {
        if (nums[mid] < nums[mid + 1]) l = mid + 1; //如果，mid小于右边的，那就往右边走，肯定有波峰
        else r = mid; //否则，那说明mid起码是大于右边的，那左边是往高走，因此往左边二分法
        mid = (r - l) / 2 + l;
    }
    return mid;//最后就直接返回mid就行了。
}

int minNumberInRotateArray(vector<int> arr) { //反转的非降序数组，找波谷
    //找波谷吗，波谷就是二分法，往下走
    int l = 0;
    int r = arr.size() - 1;
    int mid = (r - l) / 2 + l;
    while (l < r) {
        if (arr[mid] > arr[r]) l = mid + 1;  //如果mid和最右侧点比mid更大，意味着mid在反转前的后半段，则最小店肯定在mid右边
        else if (arr[mid] < arr[r]) r = mid; //mid和最右侧点比，如果mid比右侧点小，那说明往左是降序，因此r = mid
        else if (arr[mid] == arr[r]) r = r - 1; //如果mid刚好和最右侧点相等，那有两种可能
        //1是mid在左侧大量相等的点区域上，这种情况内缩右侧点，如果发现更小的右侧点，就会执行第一种情况，如果没有，就会执行第二种情况
        //2是mid在右侧大量相等的点区域上，这种情况内锁右侧点，如果发现更小的mid，就会第二种，否则就会用第一种。
        mid = (r - l) / 2 + l;
    }
    return arr[mid];
}