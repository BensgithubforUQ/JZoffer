#include "Solution3.h"

bool Solution3::VerifySquenceOfBST(vector<int> sequence) {
	/*输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则返回 true, 否则返回 false 。
		假设输入的数组的任意两个数字都互不相同。

		数据范围： 节点数量 0 \le n \le 10000≤n≤1000 ，节点上的值满足 1 \le val \le 10 ^ {5}1≤val≤10
		5
		，保证节点上的值各不相同
		要求：空间复杂度 O(n)O(n) ，时间时间复杂度 O(n ^ 2)O(n
			2
		)
		提示：
		1.二叉搜索树是指父亲节点大于左子树中的全部节点，但是小于右子树中的全部节点的树。
		2.该题我们约定空树不是二叉搜索树
		3.后序遍历是指按照 “左子树 - 右子树 - 根节点” 的顺序遍历*/

	//所谓二叉搜索树，就是根节点大于左节点，小于右节点。
	//所谓后序遍历，（后序）遍历左子树，然后（后序）遍历右子树，最后返回根节点
	//先确定根节点的值，左节点小于根节点，右节点大于根节点，就是二叉搜索树
	// 分析
	//8（end）
	//6    10  (可知，end-1就是右树根结点，而6在begin - end中第一个>root的值的前一个)
	//5（begin） 7  9 11
	//[5, 7, 6, 9, 11, 10, 8]
	return recursioVerify(sequence, 0, sequence.size() - 1);
}

bool Solution3::recursioVerify(vector<int> sequence, int begin, int end) {
	if (sequence.empty()|| end<begin) return false;
	int root = sequence[end];//ends是根结点
	int index = 0;//index用于查找左子树的根节点
	for (; index < end; index++) {
		if (sequence[index] > root) {//当左子树根节点大于根节点的时候，就找到了根节点的左节点和右子树的最左叶子结点
			break;
		}
	}

	for (int j = index; j < end; j++) {//从右子树的最左结点开始找，右边子树有任何大于root的值，则返回错误
		if (sequence[j] < root) {
			return false;
		}
	}

	bool left = true;
	if (index > begin) {
		left = recursioVerify(sequence, begin, index - 1);//左子树进行递归
	}

	bool right = true;
	if (index < end - 1) {
		right = recursioVerify(sequence, index, end = index);//右子树进行递归
	}

	return left && right;//左右同时为真，二叉搜索树才为真
}

//
//class Solution {
//	bool judge(vector<int>& a, int l, int r) {
//		if (l >= r) return true;
//		int i = r;
//		while (i > l && a[i - 1] > a[r]) --i;
//		for (int j = i - 1; j >= l; --j) if (a[j] > a[r]) return false;
//		return judge(a, l, i - 1) && (judge(a, i, r - 1));
//	}
//public:
//	bool VerifySquenceOfBST(vector<int> a) {
//		if (!a.size()) return false;
//		return judge(a, 0, a.size() - 1);
//	}
//};