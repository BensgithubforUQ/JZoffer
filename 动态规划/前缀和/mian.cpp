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
