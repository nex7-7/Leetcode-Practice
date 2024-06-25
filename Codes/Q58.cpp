#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ctr = 0;
        for(int i = s.size() - 1; i>=0; i--){
            if(s[i] != ' '){
                ctr++;
            }
            if(s[i] == ' ' && ctr > 0){
                break;
            }
        }
        return ctr;
    }
};