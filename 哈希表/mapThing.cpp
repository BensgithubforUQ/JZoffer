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

int minNumberDisappeared(vector<int>& nums) { //��ϣ����û�г����������е���С����������
    // write code here
    int res = 1;
    if (nums.empty()) return res;
    unordered_map<int, int> mp;
    int mx = INT_MAX;
    int mn = INT_MIN; 
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] > 0) {
            mp[nums[i]]++;
            if (mx < nums[i]) mx = nums[i];
            if (mn > nums[i]) mn = nums[i];
        }
    }
    if (mn > 1) return res;
    int size = mp.size();
    int diff = mx - mn + 1; //���ֵ����Сֵ��Ĳ�ֵ
    if (size == diff) return mx + 1;
    for (int i = 1; i <= mx; i++)
        if (mp[i] == 0)
        {
            cout << i << endl;
            res = i;
            break;
        }
    return res;
}