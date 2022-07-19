#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

//��ϣ��Hash table��Ҳ��ɢ�б����Ǹ��ݹؼ���ֵ(Key value)��ֱ�ӽ��з��ʵ����ݽṹ��
//Ҳ����˵����ͨ���ѹؼ���ֵӳ�䵽����һ��λ�������ʼ�¼���Լӿ���ҵ��ٶȡ�
//���ӳ�亯������ɢ�к���(��ϣ����)����ż�¼�����������ϣ��
//������M�����ں���f(key)������������Ĺؼ���ֵkey��
//���뺯�������ܵõ������ùؼ��ֵļ�¼�ڱ��еĵ�ַ��
//��Ʊ�MΪ��ϣ��Hash��������f(key)Ϊ��ϣ(Hash) ������

//hash strength �� ����Ԫ�غܿ죬��ɾ��ķ��㣬
//ȱ�� Ԫ�����򣬲��Ҳ����ظ�
vector<int> twoSum(vector<int>& numbers, int target) {
	vector<int> res;
	unordered_map <int, int> mp; //unordered_map�ײ�ʵ���ǹ�ϣ����map�ĵײ�ʵ���Ǻ����
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
    int res;//���������У����ִ����������鳤��һ���ֵ��
    unordered_map<int, int> mp;
    for (auto i : numbers) {
        mp[i]++;
        if (mp[i] > numbers.size() / 2) {
            res = i;
            break;
        }
    }
    return res;
	//�����ϣ����Ҫ������Ҫ��unordered_map�е�pair��ŵ�vector���棬Ȼ���������㷨����
	//��ȻҲ��������һ���ص�����������stl����
}