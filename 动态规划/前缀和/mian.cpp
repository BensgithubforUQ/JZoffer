#include <iostream>
#include <vector>
using namespace std;

void sumOfLR() { //ǰ׺�ͣ�ע��۲����ݷ�Χ 10�ľŴη���ֱ��tm��long long
    int n, q;
    cin >> n;
    cin >> q;
    vector<long> arr(n, 0);
    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp; //dp˼�룬������ﲻ��dp�������Ҫ����+ʱ�临�Ӷ�ֱ��*n

    }
    vector<pair<long, long>> res(q, pair<long, long>(0, 0));
    for (int i = 0; i < q; i++) {
        cin >> res[i].first;
        cin >> res[i].second;
    }

    for (int i = 0; i < q; i++) {
        long long temp = 0;
        if (res[i].first == 1) temp = arr[res[i].second - 1]; //�ü����������ӣ���ʡʱ�临�Ӷȡ�
        else temp = arr[res[i].second - 1] - arr[res[i].first - 2];
        cout << temp << endl;
    }
}


void twoDSum() { //��ά��ǰ׺�ͣ�˼·һ���ģ�ֻ�����Ƕ���㼸�����ˡ�
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n, vector<long long>(m, 0));
    for (int i = 0; i < n; i++) {
        long long temp;
        long long sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> temp;
            sum += temp;
            arr[i][j] = sum;
            if (i > 0) arr[i][j] += arr[i - 1][j];
        }
    }


    for (int i = 0; i < q; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        long long xy1, xy2, xy3, xy4;
        if (x1 > 0 && y1 > 0) xy1 = arr[x1 - 1][y1 - 1];
        else xy1 = 0;
        if (x1 == 0) xy2 = 0;
        else xy2 = arr[x1 - 1][y2];
        if (y1 == 0) xy3 = 0;
        else xy3 = arr[x2][y1 - 1];
        long long sum = arr[x2][y2] - xy2 - xy3 + xy1;
        cout << sum << endl;
    }

}
