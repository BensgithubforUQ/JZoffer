#include "Solution.h"


string Solution::replaceSpace(string s) {
	//��ʵ��һ����������һ���ַ���s�е�ÿ���ո��滻�ɡ� % 20����
	//���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
	//���ݷ�Χ:0 \le len(s) \le 1000 \0��len(s)��1000 ����֤�ַ����е��ַ�Ϊ��дӢ����ĸ��СдӢ����ĸ�Ϳո��е�һ�֡�
	if (s.empty()) {
		return "";
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') { //string�������ַ�����ÿ���ַ���char
				
				s[i] = '%';
				s.insert(i+1,"20"); //�ؼ���inser�����ú�"" �Լ�''������
			}
		}
	}
	return s;
}
