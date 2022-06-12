#include "Solution4.h"

//����һ������Ϊ n �ַ�������ӡ�����ַ������ַ����������У������������˳�򷵻�����ַ������顣
//���������ַ���ABC, ��������ַ�A, B, C�������г����������ַ���ABC, ACB, BAC, BCA, CBA��CAB��

//���ݷ�����󾭵��㷨֮һ���������˸о�����������㷨�е���򵥵�һ���ˣ�
//���ݷ������Ҫ����������⣬��ö�ٳ����е���������й̶���ģ�壬���ҳ������͹̶���
//ֻҪ�������⼸�ֻ������;Ϳ���������������ݷ����⡣���ݷ���Ҫ�ҳ�����������Ϳɽ����
//
//·����Ҳ�����Ѿ�������ѡ��
//ѡ���б�Ҳ�����㵱ǰ��������ѡ��
//����������Ҳ���ǵ���������ײ㣬�޷�����ѡ���������
//���뷽��ֱ����������ģ�弴��

vector<string> Solution4::Permutation(string str) {
	vector<string> res;
	set<string> res_s;
	int size = str.length();
	if (size == 1 || size == 0) {
		res.push_back(str);
		return res;
	}
	permutation(res_s, str, 0);
	for (set<string>::iterator begin = res_s.begin(); begin != res_s.end(); begin++) {
		res.push_back(*begin);
	}
	return res;
}
void Solution4::permutation(set<string>& ans, string str, int index) {
	if (index >= str.length()) {
		//�ҵ���һ����
		//����ȥ���ظ����У�����һ�ַǳ��򵥵ķ����������ٱ���ĳһ������ʱ��ֱ���жϸ���������Ƿ�
		//�Ѿ������ڴ𰸼���������ٲ��롣
		cout << "���� " << str << endl;
		ans.insert(str);
		return;
	}
	for (int i = index; i < str.length(); i++) { //����
		cout << "index= " << index << " i= " << i << " " << str << " ";
		swap(str[i], str[index]); //���� ��ѯ
		cout<<str<<endl;
		permutation(ans, str, index + 1);
		swap(str[i], str[index]); //��������  ����   
		cout << "��ת index: " << index << " i: " << i << " " << str << endl;
	}
	cout << "i = 3 end!!!!" << "��ת index: " << index << endl;
}
int main() {
	string s = "abc";
	Solution4 s4;
	//cout << s[0] << endl; //test
	//s[0] = s[2];
	//printf("s[0]:%c\n", s[0]);
	vector<string> sv = s4.Permutation(s);
	for (int i = 0; i < sv.size(); i++) {
		cout << sv[i] << endl;
	}
	return 0;
}