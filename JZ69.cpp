class Solution {
public:
    int jumpFloor(int number) {//��̬�滮����
        if (number == 0) return 1; //��Ϊ��Ŀ�и���number�����ܵ���0����˲���Ҫ�ж���
        if (number == 1) return 1;
        if (number >= 2) {
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
        return 0;
    }
};
//��̨�����⣬�޷�������������һ����һ����һ���ӣ�һ����һ����������
//�����⣬���ǵ�̨�״���1��ʱ�򣬾Ϳ���-1����-2����̨��==2��ʱ��-1==1��-2==0
//���number==0��Ĭ����-2���������==1����-1�����������++1
//��==1�����ֱ�ӷ���1����Ϊֻ��һ�����ķ�ʽ
//��number>2��ʱ�򣬾���Ҫ�ݹ飬�������������Ȼ>2,������ݹ顣
class Solution {
public:
    int jumpFloorII(int number) { //��̨����չ�������Ҫ��֮ǰ��ÿ����ֵ�Ľ�����ӵ�һ��
        //��Ϊÿ���ṹ����������һ��ֱ�ӵ��յ㣬�γ��µĽ��������
        if (number == 0) return 1;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int res = 0;
        for (; number > 0; number--)
            res += jumpFloorII(number - 1);
        return  res;
    }
};