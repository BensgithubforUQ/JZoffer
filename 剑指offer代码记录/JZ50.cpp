#include <hash_map>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        unordered_map<char, int> mp;
        for (int i = 0; i < str.size(); ++i) mp[str[i]]++;
        for (int i = 0; i < str.length(); i++)
            if (mp[str[i]] == 1) return i;
        return -1;
    }
};