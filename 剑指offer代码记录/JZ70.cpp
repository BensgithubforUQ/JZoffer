class Solution {
public:
    int rectCover(int number) { //jz70 n��2*1��С���θ���2*n�ľ��εķ���
        //�򵥵ĵݹ�+��̬�滮
        if (number == 0) return 0;
        if (number == 1) return 1;
        if (number == 2) return 2;
        if (number == 3) return 3;
        return rectCover(number - 2) + rectCover(number - 1);
    }
};