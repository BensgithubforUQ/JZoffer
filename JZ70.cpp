class Solution {
public:
    int rectCover(int number) { //jz70 n个2*1的小矩形覆盖2*n的矩形的方法
        //简单的递归+动态规划
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        if (number == 3) return 3;
        return rectCover(number - 2) + rectCover(number - 1);
    }
};