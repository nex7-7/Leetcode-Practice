#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int len_a = a.length();
        int len_b = b.length();

        bool num1, num2;
        bool sum = 0, carry = 0;
        char num;
        string result = "";

        while(len_a != 0 || len_b != 0){
            num = 48, num1 = 0, num2 = 0;
            if(len_a != 0){
                num1 = bool(a[len_a - 1] - '0');
                len_a --;
            }
            if(len_b != 0){
                num2 = bool(b[len_b - 1] - '0');
                len_b --;
            }

            sum = num1 ^ num2 ^ carry;
            carry = (num1 & num2) | (carry & (num1 ^ num2));

            if(sum == 1){
                num ++;
            }

            result = num + result;
        }

        if(carry){
            result = "1" + result;
        }

        return result;
    }
};

int main(){
    Solution sol;
    sol.addBinary("11","1");
    return 0;
}