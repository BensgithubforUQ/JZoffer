#include "Solution4.h"


//��εõ�һ���������е���λ����������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
//������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
//����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����

class mycompare {
public:
	bool operator()(int a, int b) {
		return a > b;
	}
};
//max ���� min
void Insert(int num) {
	multiset<int> min; //����
	multiset<int, mycompare> max; //����
	

}

double GetMedian() {

}

