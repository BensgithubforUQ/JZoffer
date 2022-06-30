#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool IsContinuous(vector<int> numbers) {  //简单的排序，没什么好说的 
        int zero = 0;
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] > numbers[j]) {
                    int temp = numbers[j];
                    numbers[j] = numbers[i];
                    numbers[i] = temp;
                }
            }
        }
        int temp = 0;
        for (int i = 0; i < numbers.size() - 1; i++) {
            if (numbers[i] >= 0) zero++;
            else {
                if (zero == 4) return false;
                int gap = numbers[i + 1] - numbers[i];
                if (gap == 0) return false;
                while (gap > 1) {
                    zero--;
                    gap--;
                    if (zero < 0) return false;
                }
            }
        }

        return true;
    }
};