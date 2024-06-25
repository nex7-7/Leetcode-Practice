#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        vector<int> num;
        int multiplier = 0;
        int result = 0;
        while(x){
            num.push_back(x%10);
            x /= 10;
        }
        if(num.size() % 2 != 0){
            num.push_back(0);
        }
        for(int i = num.size() - 1; i >= 0; i -= 2){
            x = (x * 100) + (num[i]*10) + num[i-1];
            for(int j = 0; j < 10; j++){
                if( ((multiplier * 10) + (j + 1))*(j + 1) > x ){
                    x -= ((multiplier * 10) + j)*j;
                    multiplier = (multiplier * 10) + (2*j);
                    result = (result*10) + j;
                    break;
                }
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    sol.mySqrt(8192);
    return 0;
}