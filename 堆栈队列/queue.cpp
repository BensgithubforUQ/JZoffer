#include <iostream>
#include <vector>
#include <deque>
using namespace std;

//�����Ƚ����룬����ʵ���Ϻܼ򵥣���ÿ�����������е����ֵ����deque����ʱ���浱ǰ�����е����ֵ�ʹδ�ֵ��
//�Ѱ����� ��ǰ���ֵ����������������֮ǰ���жϸ�ֵ�Ƿ�Ⱥ���ֵ��������ǣ��Ǿ�Ҫ�жϺ���ֵ�Ƿ�������м��ֵ����
//����Ǿ�pop��û�õ��м�ֵ����Ϊ��Щֵ�����ǻ������ڵ����ֵ��
//�������ֵ�ȵ�ǰ���ֵ�����������ǰ���ֵҲһ��pop����
//deque�д�������ֵ�ʹδ�ֵ�ǵ��±꣬�������ܸ��ݵ�ǰ����ֵ���±��ж�dequeͷ�������ֵ�Ƿ񱻻����������ڣ�����ǣ���pop����
vector<int> maxInWindows(const vector<int>& nums, int size) {
    vector<int> res;
    if (nums.empty() || size < 1 || nums.size() < size) return res;
    int n = nums.size();
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        while (!dq.empty() && nums[dq.back()] < nums[i])
            //�����в�Ϊ�գ����ң�����ĩβ�洢��λ����nums�е�ֵС��nums[i]��ʱ��
            dq.pop_back();//����ʱ����ζ�ţ���Щֵ�������õģ���Ϊ�����󻬶��Ĺ����У���Щ�����������ֵ
        dq.push_back(i);
        if (dq.front() + size <= i)
            dq.pop_front(); //������ͷ�����±��Ѿ�������ȥ�ˣ�pop
        if (i + 1 >= size) //�γ���size��С�Ļ�������֮��
            res.push_back(nums[dq.front()]); //��ʼ��res����push
    }
    return res;
}

//int main() {
//    return 0;
//}