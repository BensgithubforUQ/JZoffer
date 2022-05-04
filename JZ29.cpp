#include "Solution3.h"

void Solution3::readMatrix(vector<vector<int> >& matrix, vector<int> &res) {
    int size1 = matrix.size();
    int size2 = matrix[0].size();
    cout << size1 << " " << size2 << endl;
    int index = 0;
    int num = 0;
    while (num < size1 * size2) {//只要num不小于size相乘，就说明还没有遍历完
        for (int i = index; i < size2 - index; i++) {//步骤一，在上边界+左边界，一直到右边界
            res.push_back(matrix[index][i]);
            ++num;//每次push一个，++
        }
        for (int i = index + 1; i < size1 - index; i++) {//步骤二，从上边界+右边界，到下边界
            res.push_back(matrix[i][size2 - index - 1]);
            ++num;
        }
        if (index != size1 - index - 1) //这个地方需要判断一下，防止步骤一在同一行上进行
            for (int i = size2 - index - 2; i >= index; i--) {//从下边界+右边界，到左边界
                res.push_back(matrix[size1 - index - 1][i]);
                ++num;
            }
        if (index != size2 - index - 1)
            for (int i = size1 - index - 2; i > index; i--) {//从下边界+左边界，到，上边界
                res.push_back(matrix[i][index]);
                ++num;
            }
        ++index;//边界巡完，边界++
    }

}

vector<int> Solution3::printMatrix(vector<vector<int> > matrix) {
	//;//JZ29 顺时针打印矩阵
	/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下4 X 4矩阵：*/
	//照例，首先取size
	if (matrix.empty()) return matrix[0];
	int size1 = matrix.size();
	int size2 = matrix[0].size();
	vector<int> res;
	//[0][0 - size2-1],[1 - size1-1][size2-1]
	//[size1-1][size2-1 - 0],[size1 - 1 - 0][0]
	readMatrix(matrix, res);
	return res;
}
