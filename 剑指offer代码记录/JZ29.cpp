#include "Solution3.h"

void Solution3::readMatrix(vector<vector<int> >& matrix, vector<int> &res) {
    int size1 = matrix.size();
    int size2 = matrix[0].size();
    cout << size1 << " " << size2 << endl;
    int index = 0;
    int num = 0;
    while (num < size1 * size2) {//ֻҪnum��С��size��ˣ���˵����û�б�����
        for (int i = index; i < size2 - index; i++) {//����һ�����ϱ߽�+��߽磬һֱ���ұ߽�
            res.push_back(matrix[index][i]);
            ++num;//ÿ��pushһ����++
        }
        for (int i = index + 1; i < size1 - index; i++) {//����������ϱ߽�+�ұ߽磬���±߽�
            res.push_back(matrix[i][size2 - index - 1]);
            ++num;
        }
        if (index != size1 - index - 1) //����ط���Ҫ�ж�һ�£���ֹ����һ��ͬһ���Ͻ���
            for (int i = size2 - index - 2; i >= index; i--) {//���±߽�+�ұ߽磬����߽�
                res.push_back(matrix[size1 - index - 1][i]);
                ++num;
            }
        if (index != size2 - index - 1)
            for (int i = size1 - index - 2; i > index; i--) {//���±߽�+��߽磬�����ϱ߽�
                res.push_back(matrix[i][index]);
                ++num;
            }
        ++index;//�߽�Ѳ�꣬�߽�++
    }

}

vector<int> Solution3::printMatrix(vector<vector<int> > matrix) {
	//;//JZ29 ˳ʱ���ӡ����
	/*����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬�����������4 X 4����*/
	//����������ȡsize
	if (matrix.empty()) return matrix[0];
	int size1 = matrix.size();
	int size2 = matrix[0].size();
	vector<int> res;
	//[0][0 - size2-1],[1 - size1-1][size2-1]
	//[size1-1][size2-1 - 0],[size1 - 1 - 0][0]
	readMatrix(matrix, res);
	return res;
}
