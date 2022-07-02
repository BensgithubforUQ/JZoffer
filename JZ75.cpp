class Solution
{
public:
    //Insert one char from stringstream
    string s = "";
    unordered_map<char, int> res;
    int pos = 0;
    void Insert(char ch) {
        res[ch]++;
        s += ch;
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        char temp;
        bool flag = false;
        for (auto i : s) {
            if (res[i] == 1) return i;
        }
        return '#';
    }

};