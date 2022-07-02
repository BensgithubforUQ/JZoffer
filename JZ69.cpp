class Solution {
public:
    int jumpFloor(int number) {//动态规划问题
        if (number == 0) return 1; //因为题目中给的number不可能等于0，因此不需要判断了
        if (number == 1) return 1;
        if (number >= 2) {
            return jumpFloor(number - 1) + jumpFloor(number - 2);
        }
        return 0;
    }
};
//跳台阶问题，无非是两种跳法，一种是一次跳一格子，一种是一次跳俩格子
//简化问题，就是当台阶大于1的时候，就可能-1或者-2，当台阶==2的时候-1==1，-2==0
//因此number==0就默认是-2的情况，而==1就是-1的情况，都是++1
//而==1的情况直接返回1，因为只有一种跳的方式
//而number>2的时候，就需要递归，如果计算完了仍然>2,则继续递归。
class Solution {
public:
    int jumpFloorII(int number) { //跳台阶扩展，这次需要把之前的每个数值的结果都加到一起。
        //因为每个结构都可以再跳一步直接倒终点，形成新的解决方案。
        if (number == 0) return 1;
        if (number == 1) return 1;
        if (number == 2) return 2;
        int res = 0;
        for (; number > 0; number--)
            res += jumpFloorII(number - 1);
        return  res;
    }
};