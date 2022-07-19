#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> res;
	unordered_map <int, int> mp; //unordered_map底层实现是哈希表，而map的底层实现是红黑树
	for (int i = 0; i < numbers.size(); i++) {
		int diff = target - numbers[i];
		if (mp.find(diff) != mp.end()) {
			res.push_back(mp[diff] + 1);
			res.push_back(i + 1);
			break;
		}
		mp[numbers[i]] = i;
	}
}