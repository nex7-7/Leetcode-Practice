#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n_len = needle.length();
        int h_len = haystack.length();
        int pos = -1;
        for(int i = 0; i < (h_len - n_len + 1); i++){
            if(haystack[i] == needle[0]){
                if(haystack.substr(i,n_len) == needle){
                    pos = i;
                    break;
                }
            }
        }
        return pos;
    }
};