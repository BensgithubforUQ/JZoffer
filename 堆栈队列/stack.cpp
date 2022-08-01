#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

//֪����ô������������ͽ������⡣
//
//���Ǹ�ģ���⣬ģ������ŵ��������㡣
//�ҵ�˼·���Ȱ�����ת��Ϊ��׺���ʽ��
//��д���ʽΪ��׺���ʽ��ʱ����Ҫά��һ������ջ����������׺���ʽ���м����ʱ����Ҫά��һ������ջ��
//��֮����ջ�����á�
//��׺���ʽת���������Ȱ��������Ŷ�ʶ��Ϊ����������̫���ˣ����ǽ��һ����
//Ȼ��ά��һ������ջ��
//��û�������ų��ֵ�ʱ��ÿ���������ţ��ͺ�ջ�����������ȼ��Ƚϣ����·������ȼ��ߣ���ջ��
//���򣬳�ջ���뵽���ʽ�ַ����У�ֱ���·��ŵ����ȼ�����ߵģ��·�����ջ��
//���������ų��ֵ�ʱ���Ȱ������������ջ��Ȼ�������վɡ������������ŵ�ʱ�򣬷���ջ��ʼ��ջ�����뵽���ʽ�ַ����У�ֱ��ջ���������ţ������ų�ջ�����ǲ����뵽���ʽ�С�
//���ַ��棬ֱ�����뵽���ʽ�У�ÿ�����������ֵ����룬˵�������ֶθ�һ���䣬�������ֶ�Ϊ�ա�
//�������������и��ӣ������ʽ����λ����ÿ�����Ź������λ�п����Ǹ����š�
//����ļ������һ�����ֶΣ���ζ���Ǹ�������ˣ��������ŵ�ʱ����Ҫ�жϣ��������ջ��ջ���Ǹ������ţ�������#������ջ������ռλ��ռλ�������ȼ���ͣ������˵������һ�����ֶ��Ǹ�������������һ��������ʾ�������������Ǹ������Ա�������㡣
//
//�����Ǻ�׺���ʽ��ת��������
//
//�����������㡣
//��׺���ʽ�����ʱ����Ҫά��һ������ջ��
//�Ӻ�׺���ʽ�ж�ȡ�ַ����ָ�����Ϊdouble���ͣ�Ȼ�����뵽ջ�С�
//����������ţ���˵����Ҫ���м����ˣ���ʱ������ջ��ջ�����������շ��Ž��м��㣨ע���ȳ����Ǹ��ڷ����ұߣ���Ϊ���Ǻ��ȥ�ģ���������ϣ��������ջ��
//
//���ѭ�������գ�����ջջ���ᱣ��һ�����ݣ������ݾ���������Ҫ�ļ�������

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
        //��Ϊ���涼continue�ˣ�����ߵ���һ��˵������һλ��������
        if (!flag) temp = 0 - temp;
        if (valid) {
            num.push(temp);
            temp = 0;
            valid = false;
            flag = true;
            //cout<<temp<<endl;
        }
        if (i == ' ') continue; //���Կո�
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
    stack<char> op; //����ջ
    op.push('#'); //��ʼ��ջ��
    string str; //Ŀ����ʽ-��׺
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
        else if (c == '(' || c == '[' || c == '{') op.push('('); //����Ҫ��λ�ú���Ҫ����Ȼ�����߼���
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