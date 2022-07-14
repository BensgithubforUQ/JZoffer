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