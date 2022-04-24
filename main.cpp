#include "Solution.h"

int main() {
	Solution offer;
	vector<int> test_duplicate_jz3;
	test_duplicate_jz3 = { 2, 3, 1, 0, 2, 5, 3 };
	cout << "jz3 return: " << offer.duplicate(test_duplicate_jz3) << endl;
	cout << "jz3 return: " << offer.duplicate2(test_duplicate_jz3) << endl; //这个在牛客网无法通过

	vector<int> tests1_Find_jz4 = { 1,2,8,9 };
	vector<int> tetss2_Find_jz4 = { 2,4,9,12 };
	vector<int> tests3_Find_jz4 = { 4,7,10,13 }; 
	vector<int> tests4_Find_jz4 = { 6, 8, 11, 15 };
	vector<vector<int>> tests_Find_jz4;
	tests_Find_jz4.push_back(tests1_Find_jz4);
	tests_Find_jz4.push_back(tests1_Find_jz4);
	tests_Find_jz4.push_back(tests1_Find_jz4);
	tests_Find_jz4.push_back(tests1_Find_jz4);
	cout<<"jz4 return: "<<offer.Find1(7, tests_Find_jz4)<<endl;

	return 0;
}