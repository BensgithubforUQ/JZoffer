#include<iostream>
#include<vector>
using namespace std;

void fib() { //ì³²¨À­ÆõÊıÁĞ
    vector<int> res;
    res.push_back(1); //1
    res.push_back(1); //2
    int n;
    cin >> n;
    if (n <= 2) cout << 1 << endl;
    else {
        for (int i = 2; i < n; i++) 
            res.push_back(res[i - 1] + res[i - 2]);
        cout << res[n - 1] << endl;
    }
}

int main() {
    fib();
    return 0;
}