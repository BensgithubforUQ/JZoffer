#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

//哈希表（Hash table，也叫散列表），是根据关键码值(Key value)而直接进行访问的数据结构。
//也就是说，它通过把关键码值映射到表中一个位置来访问记录，以加快查找的速度。
//这个映射函数叫做散列函数(哈希函数)，存放记录的数组叫做哈希表。
//给定表M，存在函数f(key)，对任意给定的关键字值key，
//代入函数后若能得到包含该关键字的记录在表中的地址，
//则称表M为哈希（Hash）表，函数f(key)为哈希(Hash) 函数。

//hash strength ： 处理元素很快，增删查改方便，
//缺点 元素无序，并且不能重复
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

int MoreThanHalfNum_Solution(vector<int> numbers) {
    int res;//查找数组中，出现次数超过数组长度一半的值。
    unordered_map<int, int> mp;
    for (auto i : numbers) {
        mp[i]++;
        if (mp[i] > numbers.size() / 2) {
            res = i;
            break;
        }
    }
    return res;
	//如果哈希表需要排序，则要把unordered_map中的pair存放到vector里面，然后用排序算法排序
	//当然也可以重载一个回调函数用其他stl排序。
}