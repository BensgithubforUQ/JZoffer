#include "Solution4.h"
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 0) return 0;
        set<long>ugly = { 1 };
        int size = ugly.size();
        int eraseMin = 0;
        set<long>::iterator i = ugly.begin();

        while (ugly.size() < 2001) {
            // cout << (*i) << " size: " << ugly.size() << endl;
            ugly.insert(*i * 2);

            ugly.insert(*i * 3);

            ugly.insert(*i * 5);
            i++;
        }
        //cout << size << endl;
        set<long>::iterator j = ugly.begin();
        for (; j != ugly.end(); j++) {
            cout << *j << endl;
            index--;
            if (index == 0) break;
        }

        return *j;
    }
};