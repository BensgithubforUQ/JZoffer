#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int> > threeSum(vector<int>& num) { //用哈希表比较烦，需要反复判断一个值是否有多次出现，用双指针更加优。
    vector<vector<int>> res;
    //set<vector<int>> noRepeat;
    if (num.size() < 3) return res;
    sort(num.begin(), num.end());
    int cur = -101;
    for (int i = 0; i < num.size() && num[i] <= 0; i++) { //当基准值大于0，则不可能再得到和为0的情况
        if (num[i] == cur) continue;
        cur = num[i];
        int left = i + 1;
        int right = num.size() - 1;
        while (left < right) {
            int cur_l = num[left]; //记录当前左值和右值
            int cur_r = num[right];
            int sum = num[i] + num[left] + num[right];
            if (sum == 0) {
                vector<int> temp = { num[i], num[left], num[right] };
                //sort(temp.begin(), temp.end());
                res.push_back(temp);
                right--;
                left++;
                while (num[left] == cur_l && left < right) left++; //相同的值没必要再用，因为一一对应。
                while (num[right] == cur_r && left < right) right--; 
            }
            if (num[i] + 2 * num[right] < 0) break; //如果基准值  + 右值的两倍还小于0，意味着已经无法和为0，右值太小
            if (num[i] + 2 * num[left] > 0) break; //同上
            if (sum > 0) { //如果和大于0，意味着当前右值太大
                right--;
                while (num[right] == cur_r && left < right) right--;
            }
            if (sum < 0) { //如果和小于0，意味着当前中值太小
                left++;
                while (num[left] == cur_l && left < right) left++;
            }
        }
    }
    //for (auto i : noRepeat) res.push_back(i);
    return res;
}

char* f(int a) { return (char*)malloc(sizeof(char) * 8); }

class base {
public:
    base(int x) :a(x) {}
    virtual void print() {};
private:
    int a;
};

class base1 :public base{
public:
    base1(int x) :b(x),base(x-1) {};
    virtual void print() {};
private:
    int b;
};

int halfDivide(vector<int>& v,int i,int j) {
    if (i == j) return i;
    int mid = (i + j) / 2;
    if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1]) return mid;
    else if (v[mid]<v[mid-1]) return halfDivide(v,i,mid-1);
    return halfDivide(v, mid+1, j);
}



void main(void) {
    //char* pstr;
    //pstr = f(1);
    //printf("%s", pstr);
    ////strcpy(pstr, "123456789");
    //printf("%s", pstr);
 /*   char str[24];
    char* p = str;
    int n = 24;
    void* q = malloc(24);
    base1 x(1);
    cout << sizeof(str) << " " << sizeof(p) << " " << sizeof(n) << " " <<sizeof(q) << " " <<sizeof(x) << endl;*/
    /*char c = 1;
    unsigned int a = 5;
    int b = -7;
    (a + b > 10) ? (c = 1) : (c = 2);
    cout << a + b << endl;
        printf("%d", c);*/

   /* char a[] {'Z','Z','Z'};
    char b[] = "zzz";

    cout << sizeof(a) << " " << sizeof(b);*/

    //mountainSort(v);
    
}