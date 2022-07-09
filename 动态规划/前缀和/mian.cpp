#include <iostream>
#include <vector>
using namespace std;

void sumOfLR() { //前缀和，注意观察数据范围 10的九次方，直接tm用long long
    int n, q;
    cin >> n;
    cin >> q;
    vector<long> arr(n, 0);
    cin >> arr[0];
    for (int i = 1; i < n; i++) {
        int temp;
        cin >> temp;
        arr[i] = arr[i - 1] + temp; //dp思想，如果这里不用dp，后面就要遍历+时间复杂度直接*n

    }
    vector<pair<long, long>> res(q, pair<long, long>(0, 0));
    for (int i = 0; i < q; i++) {
        cin >> res[i].first;
        cin >> res[i].second;
    }

    for (int i = 0; i < q; i++) {
        long long temp = 0;
        if (res[i].first == 1) temp = arr[res[i].second - 1]; //用减法代替连加，节省时间复杂度、
        else temp = arr[res[i].second - 1] - arr[res[i].first - 2];
        cout << temp << endl;
    }
}
