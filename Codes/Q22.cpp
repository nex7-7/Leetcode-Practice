#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        if (n == 0) {
            str = "";
            ans.push_back(str);
            return ans;
        }

        else if (n == 1) {
            str = "()";
            ans.push_back(str);
            return ans;
        }

        else {
            for (int i = 0; i < n; i++) {
                vector<string> left = generateParenthesis(i);
                vector<string> right = generateParenthesis(n - i - 1);
                for (int j = 0; j < left.size(); j++) {
                    for (int k = 0; k < right.size(); k++) {
                        str = "(" + left[j] + ")" + right[k];
                        if (!checkInArray(ans, str)) {
                            ans.push_back(str);
                        }
                    }
                }
            }
        }

        return ans;
    }

    bool checkInArray(vector<string> arr, string str) {
        for (int i = arr.size(); i > 0 ; i--) {
            if (arr[i] == str) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    vector<string> ans = s.generateParenthesis(3);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}