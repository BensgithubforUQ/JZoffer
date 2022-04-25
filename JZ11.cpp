#include "Solution.h"



int Solution::minNumberInRotateArray(vector<int> rotateArray) {//JZ11 旋转数组的最小数字
	int left = 0;
	int right = rotateArray.size() - 1;

	if (rotateArray[left] < rotateArray[right]) {
		return rotateArray[0];
	}

	while (left < right) {
		int povite = (right - left) / 2 + left;
		if (rotateArray[povite] > rotateArray[right]) {
			left = povite + 1;
		}
		else if (rotateArray[povite] < rotateArray[right]) {//rotateArray[povite] >rotateArray[left]
			right = povite;
		}
		else {
			right--;
		}
	}

	return rotateArray[left];
}