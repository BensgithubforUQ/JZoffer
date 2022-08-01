#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//知道怎么叫崽种题吗，这就叫崽种题。
//
//这是个模拟题，模拟带括号的四则运算。
//我的思路是先把输入转化为后缀表达式。
//改写表达式为后缀表达式的时候需要维护一个符号栈，而解析后缀表达式进行计算的时候，需要维护一个数字栈。
//总之就是栈的运用。
//后缀表达式转化规则，首先把所有括号都识别为（），花样太多了，但是结果一样。
//然后维护一个符号栈：
//当没有左括号出现的时候，每次碰到符号，就和栈顶符号作优先级比较，当新符号优先级高，入栈。
//否则，出栈输入到表达式字符串中，直到新符号的优先级是最高的，新符号入栈。
//当有左括号出现的时候，先把左括号入符号栈，然后其他照旧。当碰到有括号的时候，符号栈开始出栈，输入到表达式字符串中，直到栈顶是左括号，左括号出栈，但是不加入到表达式中。
//数字方面，直接输入到表达式中，每次遇到非数字的输入，说明该数字段告一段落，重置数字段为空。
//但是数字这里有个坑，即表达式的首位或者每个括号过后的首位有可能是个减号。
//这里的减号配合一个数字段，意味着是负数。因此，遇到符号的时候需要判断，如果符号栈的栈顶是个左括号，或者是#（符号栈中用来占位的占位符，优先级最低），这就说明下面一个数字段是负数。这里我用一个！来表示接下来的数字是负数，以便后续计算。
//
//以上是后缀表达式的转化方法。
//
//下面来讲计算。
//后缀表达式计算的时候，需要维护一个数字栈。
//从后缀表达式中读取字符，恢复数字为double类型，然后输入到栈中。
//如果遇到符号，则说明需要进行计算了，这时，数字栈出栈两个数，按照符号进行计算（注意先出的那个在符号右边，因为他是后进去的）。计算完毕，将结果入栈。
//
//如此循环，最终，数字栈栈顶会保留一个数据，该数据就是我们需要的计算结果。

double calculate(string& str) {
    stack<double> num;
    double temp = 0;
    double res = 0;
    int flag = true;
    int valid = false;
    for (auto i : str) {
        if (i == '!' || (i <= '9' && i >= '0')) {
            valid = true;
            if (i == '!') {
                flag = false;
                continue;
            }
            temp *= 10;
            temp += i - '0';
            continue;
        }
        //因为上面都continue了，如果走到这一步说明最新一位不是数字
        if (!flag) temp = 0 - temp;
        if (valid) {
            num.push(temp);
            temp = 0;
            valid = false;
            flag = true;
            //cout<<temp<<endl;
        }
        if (i == ' ') continue; //忽略空格
        else if (i == '+') {
            double r = num.top();
            num.pop();
            double l = num.top();
            num.pop();
            num.push(l + r);
            //cout<<l<<" + "<<r<<"="<<num.top()<<endl;
        }
        else if (i == '-') {
            double r = num.top();
            num.pop();
            double l = num.top();
            num.pop();
            num.push(l - r);
            //cout<<l<<" - "<<r<<"="<<num.top()<<endl;
        }
        else if (i == '*') {
            double r = num.top();
            num.pop();
            double l = num.top();
            num.pop();
            num.push(l * r);
            //cout<<l<<" * "<<r<<"="<<num.top()<<endl;
        }
        else if (i == '/') {
            double r = num.top();
            num.pop();
            double l = num.top();
            num.pop();
            num.push(l / r);
            //cout<<l<<" / "<<r<<"="<<num.top()<<endl;
        }

    }
    return num.top();
}

int main() {
    stack<char> op; //符号栈
    op.push('#'); //初始化栈顶
    string str; //目标表达式-后缀
    char c;
    unordered_map<char, int> pr;
    pr['#'] = 1;
    pr['+'] = 3;
    pr['-'] = 3;
    pr['*'] = 4;
    pr['/'] = 4;
    pr['('] = 2;
    string num = "";
    while (cin >> c) {
        if ((op.top() == '#' || op.top() == '(') && num.empty() && c == '-') {
            num += "!";
            continue;
        }
        if (c <= '9' && c >= '0') {
            num += c;
            continue;
        }
        if (!num.empty()) str += num + " ";
        num = "";

        if (c == ')' || c == ']' || c == '}') {
            while (op.top() != '(') {
                str.insert(str.end(), op.top());
                str += " ";
                op.pop();
            }
            op.pop();
        }
        else if (c == '(' || c == '[' || c == '{') op.push('('); //很重要，位置很重要，不然会搞错逻辑。
        else if (pr[c] > pr[op.top()]) op.push(c);
        else if (pr[c] <= pr[op.top()]) {
            while (pr[c] <= pr[op.top()]) {
                if (op.size() > 1) {
                    str.insert(str.end(), op.top());
                    str += " ";
                    op.pop();
                }
            }
            op.push(c);
        }
    }
    str += num + " ";
    while (op.top() != '#') {
        if (op.size() > 1) str.insert(str.end(), op.top());
        str += " ";
        op.pop();
    }
    //cout << str<<endl;
    cout << calculate(str);
}