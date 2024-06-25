#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int max(int a, int b){
        return a>b?a:b;
    }
    string longestCommonPrefix(vector<string>& strs) {
        int len = max(1, strs[0].length());
        int size = 0;
        bool br;
        for(int i = 0; i<len; i++){
            int j;
            for(j = 1; j<strs.size(); j++){
                if(strs[j].length() > len){
                    len = strs[j].length();
                }
                if(strs[j][i] != strs[j-1][i]){
                    break;
                }
            }
            if(j == strs.size()){
                size ++;
            }
            else
                break;
        }
        return strs[0].substr(0,size);
    }
};

int main(){
    vector<string> strs;
    strs.push_back("car");
    strs.push_back("cir");
    Solution sol;
    sol.longestCommonPrefix(strs);
    return 0;
}