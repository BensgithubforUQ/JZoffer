class Solution {
public:
    string ReverseSentence(string str) { //反转字符串中的单词序列
        if (str == "") return str;
        deque<string> q_str;
        string temp = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                q_str.push_front(temp);
                temp = "";
            }
            else temp.push_back(str[i]);
        }
        q_str.push_front(temp);
        temp = "";

        for (auto i = q_str.begin(); i != q_str.end(); i++) {
            temp += *i;
            if (i != q_str.end() - 1) temp += " ";
        }
        return temp;
    }
};